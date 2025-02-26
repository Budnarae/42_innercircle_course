/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:51:57 by sihong            #+#    #+#             */
/*   Updated: 2024/07/02 15:52:08 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/factor_bonus.h"
#include "../header_bonus/miniRT_bonus.h"

void	calculate_multiple_light(t_phong *phong, t_col_info col, t_factor *f)
{
	t_vec3	l;
	t_vec3	r;
	t_vec3	v;
	int		i;

	v = vec3_normalize(col.pos);
	i = 0;
	while (i < f->tab[LIGHT])
	{
		l = vec3_normalize(vec3_sub(f->light[i].light_pos, col.pos));
		if (vec3_dot(col.n_vec, l) < 0.0f \
			|| check_light_collision(i, col.pos, f) == 1)
		{
			i++;
			continue ;
		}
		phong->diffuse = vec3_add(phong->diffuse, vec3_scale(f->light[i].range \
			* max(vec3_dot(col.n_vec, l), 0.0f), vec3_mul(phong->obj_color, \
			vec3_scale(1.0f / 255.0f, f->light[i].color))));
		r = vec3_sub(vec3_scale(2.0f * vec3_dot(l, col.n_vec), col.n_vec), l);
		phong->specular = vec3_add(phong->specular, \
			vec3_scale(pow(max(-vec3_dot(r, v), 0.0f), 64.0f) \
			* f->light[i].range, get_vec3(1.0f, 1.0f, 1.0f)));
		i++;
	}
}

t_vec3	get_pixel_color(t_col_info col, t_factor *f)
{
	t_phong	phong;
	t_vec3	color;

	if (vec3_iszero(col.n_vec) == TRUE)
		return (get_vec3(0.0f, 0.0f, 0.0f));
	phong.obj_color = vec3_scale(1.0f / 255.0f, col.color);
	phong.ambient = vec3_scale(f->amb->range, vec3_mul(vec3_scale(1.0f \
					/ 255.0f, f->amb->color), phong.obj_color));
	phong.diffuse = get_vec3(0.0f, 0.0f, 0.0f);
	phong.specular = get_vec3(0.0f, 0.0f, 0.0f);
	calculate_multiple_light(&phong, col, f);
	color = vec3_add(phong.ambient, phong.diffuse);
	color = vec3_add(color, phong.specular);
	color = clip_color(color);
	return (color);
}
