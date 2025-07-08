/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:17:16 by sihong            #+#    #+#             */
/*   Updated: 2024/07/02 15:38:23 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/factor_bonus.h"
#include "../header_bonus/miniRT_bonus.h"

t_col_info	get_collision_location(t_vec3 ray_to_pixel, \
	t_factor *f, t_vars *vars)
{
	t_col_info	col;
	t_col_info	tmp;

	col = get_fake_col();
	tmp = check_col_all_sp(ray_to_pixel, f->tab[SPHERE], f->sp);
	col = get_closer_coord(col, tmp);
	tmp = check_col_all_cy(ray_to_pixel, f->tab[CYLINDER], f->cy);
	col = get_closer_coord(col, tmp);
	tmp = check_col_all_pl(ray_to_pixel, f->tab[PLANE], f->pl, vars);
	col = get_closer_coord(col, tmp);
	tmp = check_col_all_co(ray_to_pixel, f->tab[CONE], f->co);
	col = get_closer_coord(col, tmp);
	return (col);
}

int	check_light_collision(int lit_num, t_vec3 col_pos, t_factor *f)
{
	if (check_lit_col_all_sp(lit_num, col_pos, f) == TRUE)
		return (TRUE);
	if (check_lit_col_all_cy(lit_num, col_pos, f) == TRUE)
		return (TRUE);
	if (check_lit_col_all_pl(lit_num, col_pos, f) == TRUE)
		return (TRUE);
	if (check_lit_col_all_co(lit_num, col_pos, f) == TRUE)
		return (TRUE);
	return (FALSE);
}

t_vec3	shoot_ray_to_pixel(t_vec3 ray_to_pixel, t_factor *f, t_vars *vars)
{
	t_col_info	col;
	t_vec3		color;

	col = get_collision_location(ray_to_pixel, f, vars);
	color = get_pixel_color(col, f);
	return (color);
}

/** if (f->cam->fov < 1.0f) --> black screen! */
void	raytracer(t_vars *vars, t_factor *f)
{
	if (f->cam->fov < 1.0f)
	{
		black_screen(vars);
		return ;
	}
	distribute_to_thread(4, 4, vars, f);
}
