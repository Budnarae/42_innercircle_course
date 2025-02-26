/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_plane.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:24:25 by sihong            #+#    #+#             */
/*   Updated: 2024/07/05 15:24:27 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/factor_bonus.h"
#include "../header_bonus/miniRT_bonus.h"

t_col_info	get_texture_info(t_vec3 v, t_vars *vars)
{
	char		*dst_t;
	char		*dst_m;
	double		x;
	double		z;
	t_col_info	t_c;

	while (v.e[X] < 0.0f)
		v.e[X] += TEX_SIZE;
	while (v.e[Z] < 0.0f)
		v.e[Z] += TEX_SIZE;
	x = v.e[X] - ((size_t)v.e[X] * 10000 \
		/ (size_t)(TEX_SIZE * 10000)) * TEX_SIZE;
	z = v.e[Z] - ((size_t)v.e[Z] * 10000 \
		/ (size_t)(TEX_SIZE * 10000)) * TEX_SIZE;
	dst_t = vars->tex.addr + ((size_t)(z * 16.0f) * vars->tex.line_length \
		+ (size_t)(x * 16.0f) * (vars->tex.bits_per_pixel / 8));
	t_c.color = get_vec3(get_r(*(int *)dst_t), get_g(*(int *)dst_t), \
		get_b(*(int *)dst_t));
	dst_m = vars->map.addr + ((size_t)(z * 16.0f) * vars->map.line_length \
		+ (size_t)(x * 16.0f) * (vars->map.bits_per_pixel / 8));
	t_c.n_vec = vec3_normalize(get_vec3((double)get_r(*(int *)dst_m) \
	- 128.0f / 128.0f, (double)get_b(*(int *)dst_m) - 128.0f / 128.0f \
	, (double)get_g(*(int *)dst_m) - 128.0f / 128.0f));
	t_c.n_vec = vec3_sub(vec3_scale(2.0f, t_c.n_vec), get_vec3(1.0, 1.0, 1.0));
	return (t_c);
}

t_col_info	get_texture_plane(t_col_info col, t_plane pl, t_vars *vars)
{
	t_mat4x4	rev_pl;
	t_mat4x4	restore;
	t_vec3		pos;
	t_vec3		n_vec;
	t_col_info	t_c;

	rev_pl = get_rev_fi_matrix(pl.plane_pos, pl.unit_vec);
	restore = get_fi_matrix(pl.plane_pos, pl.unit_vec);
	pos = vec4_to_3(mat4x4_vec4_mul(rev_pl, vec3_to_4(col.pos, 1.0f)));
	n_vec = vec4_to_3(mat4x4_vec4_mul(rev_pl, vec3_to_4(col.n_vec, 1.0f)));
	t_c = get_texture_info(pos, vars);
	if (n_vec.e[Y] < 0.0f)
		t_c.n_vec = vec3_negate(t_c.n_vec);
	t_c.n_vec = vec3_sub(vec4_to_3(mat4x4_vec4_mul(restore, \
		vec3_to_4(vec3_add(pos, t_c.n_vec), 1.0f))), col.pos);
	t_c.pos = col.pos;
	return (t_c);
}
