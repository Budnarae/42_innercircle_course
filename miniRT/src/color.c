/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:56:49 by chansjeo          #+#    #+#             */
/*   Updated: 2024/06/29 18:17:31 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/miniRT.h"

int	create_rgb(t_vec3 color)
{
	return ((int)color.e[X] << 16 | (int)color.e[Y] << 8 | (int)color.e[Z]);
}

int	create_unit_rgb(t_vec3 color)
{
	int	ur;
	int	ug;
	int	ub;

	ur = (int)(255.0f * color.e[X]);
	ug = (int)(255.0f * color.e[Y]);
	ub = (int)(255.0f * color.e[Z]);
	return (ur << 16 | ug << 8 | ub);
}

t_vec3	clip_color(t_vec3 color)
{
	t_vec3	cliped;

	if (color.e[X] > 1.0f)
		cliped.e[X] = 1.0f;
	else
		cliped.e[X] = color.e[X];
	if (color.e[Y] > 1.0f)
		cliped.e[Y] = 1.0f;
	else
		cliped.e[Y] = color.e[Y];
	if (color.e[Z] > 1.0f)
		cliped.e[Z] = 1.0f;
	else
		cliped.e[Z] = color.e[Z];
	return (cliped);
}

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
