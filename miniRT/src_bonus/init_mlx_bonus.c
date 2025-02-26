/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:40:56 by sihong            #+#    #+#             */
/*   Updated: 2024/07/08 09:41:00 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/miniRT_bonus.h"

void	init_img(t_vars *vars)
{
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (vars->img == NULL)
		exit(1);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, \
			&vars->line_length, &vars->endian);
	if (vars->addr == NULL)
		exit(1);
	vars->tex.tex_img = mlx_xpm_file_to_image(vars->mlx, "./img/texture.xpm", \
		&vars->tex.tex_width, &vars->tex.tex_height);
	if (vars->tex.tex_img == NULL)
		exit(1);
	vars->tex.addr = mlx_get_data_addr(vars->tex.tex_img, \
	&vars->tex.bits_per_pixel, &vars->tex.line_length, &vars->tex.endian);
	if (vars->addr == NULL)
		exit(1);
	vars->map.tex_img = mlx_xpm_file_to_image(vars->mlx, "./img/normal.xpm", \
		&vars->map.tex_width, &vars->map.tex_height);
	if (vars->map.tex_img == NULL)
		exit(1);
	vars->map.addr = mlx_get_data_addr(vars->map.tex_img, \
		&vars->map.bits_per_pixel, &vars->map.line_length, &vars->map.endian);
	if (vars->addr == NULL)
		exit(1);
}

void	init_window(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		exit(1);
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "miniRT");
	if (vars->win == NULL)
		exit(1);
	init_img(vars);
}
