/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col_all_co_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:57:44 by sihong            #+#    #+#             */
/*   Updated: 2024/07/02 17:57:46 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/factor_bonus.h"
#include "../header_bonus/miniRT_bonus.h"

t_col_info	get_col_co_cap(t_vec4 cam_pos, t_vec4 pl_pos, \
							t_cone co)
{
	double		t;
	t_col_info	p;
	t_vec3		ray_to_pixel;

	t = -cam_pos.e[Y] / (pl_pos.e[Y] - cam_pos.e[Y]);
	if (t <= 0.0f)
		return (get_fake_col());
	else
		p.pos = vec3_add(vec3_scale(t, vec4_to_3(pl_pos)), \
				vec3_scale(1.0f - t, vec4_to_3(cam_pos)));
	if (pow(p.pos.e[X], 2.0) + pow(p.pos.e[Z], 2.0) \
		> pow(co.diameter / 2.0, 2.0))
		return (get_fake_col());
	p.n_vec = get_vec3(0.0f, -1.0f, 0.0f);
	ray_to_pixel = \
		vec3_normalize(vec3_sub(vec4_to_3(pl_pos), vec4_to_3(cam_pos)));
	if (vec3_dot(p.n_vec, ray_to_pixel) > 0.0f)
		p.n_vec = vec3_negate(p.n_vec);
	return (p);
}

t_col_info	check_col_co_cap(t_vec4 cam_pos, t_vec4 pl_pos, t_cone co)
{
	t_col_info	col;
	t_mat4x4	restore;

	if (cam_pos.e[Y] == pl_pos.e[Y])
		return (get_fake_col());
	col = get_col_co_cap(cam_pos, pl_pos, co);
	if (vec3_iszero(col.n_vec) == FALSE)
	{
		restore = get_fi_matrix(co.center_pos, co.unit_vec);
		col = restore_to_origin(restore, col);
	}
	col.color = co.color;
	return (col);
}

t_col_info	check_col_all_co(t_vec3 ray_to_pixel, int co_num, t_cone *co)
{
	t_mat4x4	rev_fi;
	t_vec4		cam_pos;
	t_vec4		pl_pos;
	t_col_info	col;
	int			i;

	i = 0;
	col = get_fake_col();
	while (i < co_num)
	{
		rev_fi = get_rev_fi_matrix(co[i].center_pos, co[i].unit_vec);
		cam_pos = mat4x4_vec4_mul(rev_fi, get_vec4(0.0f, 0.0f, 0.0f, 1.0f));
		pl_pos = mat4x4_vec4_mul(rev_fi, \
				vec3_to_4(ray_to_pixel, 1.0f));
		col = get_closer_coord(col, \
			check_col_co_side(vec4_to_3(cam_pos), vec4_to_3(pl_pos), co[i]));
		col = get_closer_coord(col, check_col_co_cap(cam_pos, pl_pos, co[i]));
		i++;
	}
	return (col);
}
