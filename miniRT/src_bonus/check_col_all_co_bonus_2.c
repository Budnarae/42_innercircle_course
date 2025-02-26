/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col_all_co_bonus_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:24:00 by sihong            #+#    #+#             */
/*   Updated: 2024/07/03 14:24:03 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/factor_bonus.h"
#include "../header_bonus/miniRT_bonus.h"

t_dic	get_co_side_dic(t_vec3 c, t_vec3 p, t_cone co)
{
	t_dic	dic;
	double	x;
	double	y;
	double	z;

	x = p.e[X] - c.e[X];
	y = p.e[Y] - c.e[Y];
	z = p.e[Z] - c.e[Z];
	dic.a = x * x + z * z - \
		pow(co.diameter / 2.0f, 2.0f) * y * y / pow(co.height, 2.0f);
	dic.b = 2.0f * (x * c.e[X] + z * c.e[Z]) - 2.0f \
		* pow(co.diameter / 2.0f, 2.0f) / pow(co.height, 2.0f) \
		* y * c.e[Y] + 2.0f * pow(co.diameter / 2.0f, 2.0f) * y / co.height;
	dic.c = pow(c.e[X], 2.0f) + pow(c.e[Z], 2.0f) \
		- pow(c.e[Y], 2.0f) * pow(co.diameter / 2.0f, 2.0f) \
		/ pow(co.height, 2.0f) + 2.0f * pow(co.diameter / 2.0f, 2.0f) \
		* c.e[Y] / co.height - pow(co.diameter / 2.0f, 2.0f);
	dic.dic = pow(dic.b, 2) - 4 * dic.a * dic.c;
	if (dic.dic >= 0.0f)
	{
		dic.t_neg = (-dic.b - sqrt(dic.dic)) / (2 * dic.a);
		dic.t_pos = (-dic.b + sqrt(dic.dic)) / (2 * dic.a);
	}
	return (dic);
}

t_col_info	get_co_side_col(double t, double h, t_vec3 cam_pos, t_vec3 pl_pos)
{
	t_col_info	col;
	t_vec3		u;
	t_vec3		v;
	t_vec3		w;

	col.pos = vec3_add(vec3_scale(t, pl_pos), vec3_scale(1 - t, cam_pos));
	if (col.pos.e[Y] < 0.0f || col.pos.e[Y] > h)
		return (get_fake_col());
	u = vec3_normalize(get_vec3(-col.pos.e[X], 0.0f, -col.pos.e[Z]));
	v = vec3_normalize(vec3_sub(get_vec3(0.0f, h, 0.0f), col.pos));
	w = vec3_normalize(vec3_cross(u, v));
	col.n_vec = vec3_normalize(vec3_cross(w, v));
	if (vec3_dot(vec3_normalize(vec3_sub(pl_pos, cam_pos)), col.n_vec) > 0.0f)
		col.n_vec = vec3_negate(col.n_vec);
	return (col);
}

t_col_info	check_col_co_side_2(t_cone co, t_dic dic, \
	t_vec3 cam_pos, t_vec3 pl_pos)
{
	t_col_info	col;

	if (dic.t_neg < 0.0f && dic.t_pos >= 0.0f)
		col = get_co_side_col(dic.t_pos, co.height, cam_pos, pl_pos);
	else if (dic.t_neg >= 0.0f && dic.t_pos < 0.0f)
		col = get_co_side_col(dic.t_neg, co.height, cam_pos, pl_pos);
	else
	{
		if (dic.t_neg >= dic.t_pos)
		{
			col = get_co_side_col(dic.t_pos, co.height, cam_pos, pl_pos);
			if (vec3_iszero(col.n_vec) == TRUE)
				col = get_co_side_col(dic.t_neg, co.height, cam_pos, pl_pos);
		}
		else
		{
			col = get_co_side_col(dic.t_neg, co.height, cam_pos, pl_pos);
			if (vec3_iszero(col.n_vec) == TRUE)
				col = get_co_side_col(dic.t_pos, co.height, cam_pos, pl_pos);
		}
	}
	return (col);
}

t_col_info	check_col_co_side(t_vec3 cam_pos, t_vec3 pl_pos, t_cone co)
{
	t_dic		dic;
	t_col_info	col;
	t_mat4x4	restore;

	dic = get_co_side_dic(cam_pos, pl_pos, co);
	if (dic.dic < 0.0f || (dic.t_neg < 0.0f && dic.t_pos < 0.0f))
		return (get_fake_col());
	else if (dic.dic == 0.0f)
		col = get_co_side_col(dic.t_pos, co.height, cam_pos, pl_pos);
	else
		col = check_col_co_side_2(co, dic, cam_pos, pl_pos);
	col.color = co.color;
	if (vec3_iszero(col.n_vec) == FALSE)
	{
		restore = get_fi_matrix(co.center_pos, co.unit_vec);
		col = restore_to_origin(restore, col);
	}
	return (col);
}
