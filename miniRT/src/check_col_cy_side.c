/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col_cy_side.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:50:40 by sihong            #+#    #+#             */
/*   Updated: 2024/06/29 17:59:25 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/factor.h"
#include "../header/miniRT.h"

t_dic	get_cy_side_dic(t_vec4 cam_pos, t_vec4 pl_pos, double diameter)
{
	t_dic	dic;
	t_vec3	c;
	t_vec3	p;
	t_vec3	p_sub_c;

	c = vec4_to_3(cam_pos);
	p = vec4_to_3(pl_pos);
	p_sub_c = vec3_sub(p, c);
	dic.a = vec3_dot(p_sub_c, p_sub_c) - pow(p_sub_c.e[Y], 2.0f);
	dic.b = 2.0f * (vec3_dot(p_sub_c, c) - p_sub_c.e[Y] * c.e[Y]);
	dic.c = vec3_dot(c, c) - pow(c.e[Y], 2.0f) - pow(diameter / 2.0f, 2.0f);
	dic.dic = pow(dic.b, 2) - 4 * dic.a * dic.c;
	if (dic.dic < 0.0f)
	{
		dic.t_neg = 0.0f;
		dic.t_pos = 0.0f;
	}
	else
	{
		dic.t_neg = (-dic.b - sqrt(dic.dic)) / (2 * dic.a);
		dic.t_pos = (-dic.b + sqrt(dic.dic)) / (2 * dic.a);
	}
	return (dic);
}

t_col_info	check_cy_height(t_vec4 cam_pos, t_vec4 pl_pos, \
		t_cylinder cy, double t)
{
	double		y;
	t_col_info	col;
	t_vec3		ray_to_pixel;

	y = pl_pos.e[Y] * t + cam_pos.e[Y] * (1 - t);
	if (y > -cy.height / 2 && y < cy.height / 2)
		col.pos = vec3_add(vec3_scale(t, vec4_to_3(pl_pos)) \
			, vec3_scale(1.0f - t, vec4_to_3(cam_pos)));
	else
		return (get_fake_col());
	col.n_vec = vec3_normalize(vec3_sub(col.pos, get_vec3(0.0f, y, 0.0f)));
	ray_to_pixel = vec3_normalize(vec3_sub(vec4_to_3(pl_pos), \
				vec4_to_3(cam_pos)));
	if (vec3_dot(ray_to_pixel, col.n_vec) > 0.0f)
		col.n_vec = vec3_normalize(vec3_sub(get_vec3(0.0f, y, 0.0f), col.pos));
	col.color = cy.color;
	return (col);
}

t_col_info	restore_to_origin(t_mat4x4 restore, t_col_info col)
{
	t_vec4		p;
	t_vec4		res_vec;
	t_col_info	res_col;

	res_vec = mat4x4_vec4_mul(restore, vec3_to_4(col.pos, 1.0f));
	p = vec3_to_4(vec3_add(col.pos, col.n_vec), 1.0f);
	p = mat4x4_vec4_mul(restore, p);
	res_col.pos = vec4_to_3(res_vec);
	res_col.n_vec = vec3_sub(vec4_to_3(p), res_col.pos);
	res_col.color = col.color;
	return (res_col);
}

t_col_info	check_col_cy_side(t_vec4 cam_pos, t_vec4 pl_pos, t_cylinder cy)
{
	t_dic		dic;
	t_col_info	col;
	t_mat4x4	restore;

	dic = get_cy_side_dic(cam_pos, pl_pos, cy.diameter);
	if (dic.dic < 0.0f || (-dic.b + sqrt(dic.dic)) <= 0.0f)
		return (get_fake_col());
	else
	{
		if (dic.dic == 0.0f)
			col = check_cy_height(cam_pos, pl_pos, cy, dic.t_pos);
		else if (dic.dic > 0.0f)
		{
			if (-dic.b - sqrt(dic.dic) <= 0.0f)
				col = check_cy_height(cam_pos, pl_pos, cy, dic.t_pos);
			else
				col = check_cy_height(cam_pos, pl_pos, cy, dic.t_neg);
		}
	}
	if (vec3_iszero(col.n_vec) == FALSE)
	{
		restore = get_cy_matrix(cy);
		col = restore_to_origin(restore, col);
	}
	return (col);
}
