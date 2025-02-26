/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:19:12 by sihong            #+#    #+#             */
/*   Updated: 2024/01/12 17:19:19 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	quadrant_4(t_mlx_data mlx_data, t_vertex a, t_vertex b)
{
	int		w;
	int		h;
	int		n;
	int		m;

	w = (int)b.vertex[0] - (int)a.vertex[0];
	h = (int)b.vertex[1] - (int)a.vertex[1];
	n = 0;
	m = 0;
	while ((int)a.vertex[0] - n != (int)b.vertex[0])
	{
		n++;
		if (2 * h * n + 2 * m * w + w >= 0)
			m++;
		if (!((int)a.vertex[0] - n <= 0 || (int)a.vertex[0] - n >= 2560
				|| (int)a.vertex[1] + m <= 0 || (int)a.vertex[1] + m >= 1315))
			my_mlx_pixel_put(&mlx_data.img_data,
				(int)a.vertex[0] - n, (int)a.vertex[1] + m,
				color_lerp(a.color, b.color, -n, w));
	}
}

void	quadrant_3(t_mlx_data mlx_data, t_vertex a, t_vertex b)
{
	int		w;
	int		h;
	int		n;
	int		m;

	w = (int)b.vertex[0] - (int)a.vertex[0];
	h = (int)b.vertex[1] - (int)a.vertex[1];
	n = 0;
	m = 0;
	while ((int)a.vertex[1] + m != (int)b.vertex[1])
	{
		m++;
		if (2 * w * m + 2 * n * h + h <= 0)
			n++;
		if (!((int)a.vertex[0] - n <= 0 || (int)a.vertex[0] - n >= 2560
				|| (int)a.vertex[1] + m <= 0 || (int)a.vertex[1] + m >= 1315))
			my_mlx_pixel_put(&mlx_data.img_data,
				(int)a.vertex[0] - n, (int)a.vertex[1] + m,
				color_lerp(a.color, b.color, m, h));
	}
}

void	quadrant_2(t_mlx_data mlx_data, t_vertex a, t_vertex b)
{
	int		w;
	int		h;
	int		n;
	int		m;

	w = (int)b.vertex[0] - (int)a.vertex[0];
	h = (int)b.vertex[1] - (int)a.vertex[1];
	n = 0;
	m = 0;
	while ((int)a.vertex[1] + m != (int)b.vertex[1])
	{
		m++;
		if (2 * w * m - 2 * n * h - h >= 0)
			n++;
		if (!((int)a.vertex[0] + n <= 0 || (int)a.vertex[0] + n >= 2560
				|| (int)a.vertex[1] + m <= 0 || (int)a.vertex[1] + m >= 1315))
			my_mlx_pixel_put(&mlx_data.img_data,
				(int)a.vertex[0] + n, (int)a.vertex[1] + m,
				color_lerp(a.color, b.color, m, h));
	}
}

void	quadrant_1(t_mlx_data mlx_data, t_vertex a, t_vertex b)
{
	int		w;
	int		h;
	int		n;
	int		m;

	w = (int)b.vertex[0] - (int)a.vertex[0];
	h = (int)b.vertex[1] - (int)a.vertex[1];
	n = 0;
	m = 0;
	while ((int)a.vertex[0] + n != (int)b.vertex[0])
	{
		n++;
		if (2 * h * n - 2 * m * w - w >= 0)
			m++;
		if (!((int)a.vertex[0] + n <= 0 || (int)a.vertex[0] + n >= 2560
				|| (int)a.vertex[1] + m <= 0 || (int)a.vertex[1] + m >= 1315))
			my_mlx_pixel_put(&mlx_data.img_data,
				(int)a.vertex[0] + n, (int)a.vertex[1] + m,
				color_lerp(a.color, b.color, n, w));
	}
}

void	bresenham(t_mlx_data mlx_data, t_vertex a, t_vertex b)
{
	if ((int)b.vertex[1] == (int)a.vertex[1]
		&& (int)b.vertex[0] > (int)a.vertex[0])
		quadrant_1(mlx_data, a, b);
	else if ((int)b.vertex[1] == (int)a.vertex[1]
		&& (int)b.vertex[0] < (int)a.vertex[0])
		quadrant_1(mlx_data, b, a);
	else if ((int)b.vertex[0] == (int)a.vertex[0]
		&& (int)b.vertex[1] > (int)a.vertex[1])
		quadrant_2(mlx_data, a, b);
	else if ((int)b.vertex[0] == (int)a.vertex[0]
		&& (int)b.vertex[1] < (int)a.vertex[1])
		quadrant_2(mlx_data, b, a);
	else
		bresenham_2(mlx_data, a, b);
}
