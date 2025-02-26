/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col_all_pl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:50:40 by sihong            #+#    #+#             */
/*   Updated: 2024/06/29 18:12:37 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/factor.h"
#include "../header/miniRT.h"

t_col_info	check_col_1pl(t_vec3 ray_to_pixel, t_plane pl)
{
	double		t;
	t_col_info	col;

	if (vec3_dot(pl.unit_vec, ray_to_pixel) == 0.0f)
		return (get_fake_col());
	t = vec3_dot(pl.unit_vec, pl.plane_pos) \
		/ vec3_dot(pl.unit_vec, ray_to_pixel);
	if (t <= 0.0f)
		return (get_fake_col());
	col.pos = vec3_scale(t, ray_to_pixel);
	if (vec3_dot(ray_to_pixel, pl.unit_vec) > 0.0f)
		col.n_vec = vec3_negate(pl.unit_vec);
	else
		col.n_vec = pl.unit_vec;
	col.color = pl.color;
	return (col);
}

t_col_info	check_col_all_pl(t_vec3 ray_to_pixel, int pl_num, t_plane *pl)
{
	int			i;
	t_col_info	col;

	i = 0;
	col = get_fake_col();
	while (i < pl_num)
	{
		col = get_closer_coord(col, check_col_1pl(ray_to_pixel, pl[i]));
		i++;
	}
	return (col);
}
