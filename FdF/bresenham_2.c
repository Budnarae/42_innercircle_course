/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:12:24 by sihong            #+#    #+#             */
/*   Updated: 2024/01/15 13:12:33 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	color_lerp(int color_a[4], int color_b[4], float n, float range)
{
	float	t;
	float	r;
	float	g;
	float	b;

	t = n / range;
	r = (1.0f - t) * color_a[0] + t * color_b[0];
	g = (1.0f - t) * color_a[1] + t * color_b[1];
	b = (1.0f - t) * color_a[2] + t * color_b[2];
	return (((int)r * (int)pow(16, 4)) + (int)g * (int)pow(16, 2) + (int)b);
}

void	bresenham_2(t_mlx_data mlx_data, t_vertex a, t_vertex b)
{
	float	slope;
	float	*av;
	float	*bv;

	av = a.vertex;
	bv = b.vertex;
	slope = (float)((int)bv[1] - (int)av[1]) / (float)((int)bv[0] - (int)av[0]);
	if (av[0] <= bv[0] && av[1] <= bv[1] && slope < 1.0f && slope >= 0.0f)
		quadrant_1(mlx_data, a, b);
	else if (av[0] <= bv[0] && av[1] <= bv[1] && slope >= 1.0f)
		quadrant_2(mlx_data, a, b);
	else if (av[0] > bv[0] && av[1] <= bv[1] && slope < -1.0f)
		quadrant_3(mlx_data, a, b);
	else if (av[0] > bv[0] && av[1] <= bv[1] && slope >= -1.0f && slope < 0.0f)
		quadrant_4(mlx_data, a, b);
	else if (av[0] > bv[0] && av[1] > bv[1] && slope < 1.0f && slope >= 0.0f)
		quadrant_1(mlx_data, b, a);
	else if (av[0] > bv[0] && av[1] > bv[1] && slope >= 1.0f)
		quadrant_2(mlx_data, b, a);
	else if (av[0] <= bv[0] && av[1] > bv[1] && slope < -1.0f)
		quadrant_3(mlx_data, b, a);
	else if (av[0] <= bv[0] && av[1] > bv[1] && slope >= -1.0f && slope < 0.0f)
		quadrant_4(mlx_data, b, a);
}
