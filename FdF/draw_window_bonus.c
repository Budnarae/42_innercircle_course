/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:22:25 by sihong            #+#    #+#             */
/*   Updated: 2024/01/12 10:22:35 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_vertex_put(t_vertex **vertex, t_map_size map_size,
	t_mlx_data mlx_data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map_size.row_size)
	{
		j = -1;
		while (++j < map_size.col_size[i])
		{
			if (!((int)vertex[i][j].vertex[0] <= 0
				|| (int)vertex[i][j].vertex[0] >= 2560
				|| (int)vertex[i][j].vertex[1] <= 0
				|| (int)vertex[i][j].vertex[1] >= 1315))
				my_mlx_pixel_put(&mlx_data.img_data,
					(int)vertex[i][j].vertex[0],
					(int)vertex[i][j].vertex[1], vertex[i][j].color[3]);
			if (j < map_size.col_size[i] - 1)
				bresenham(mlx_data, vertex[i][j],
					vertex[i][j + 1]);
			if (i < map_size.row_size - 1 && map_size.col_size[i + 1] > j)
				bresenham(mlx_data, vertex[i][j],
					vertex[i + 1][j]);
		}
	}
}

void	draw_window(t_total *total)
{
	total->mlx_data.img_data.img
		= mlx_new_image(total->mlx_data.mlx_ptr, 2560, 1315);
	total->mlx_data.img_data.addr
		= mlx_get_data_addr(total->mlx_data.img_data.img,
			&total->mlx_data.img_data.bits_per_pixel,
			&total->mlx_data.img_data.line_length,
			&total->mlx_data.img_data.endian);
	init_matrix(total);
	relocate_vertex(total->vertex,
		total->matrixs.merged_matrix, total->map_size);
	my_mlx_vertex_put(total->vertex, total->map_size, total->mlx_data);
	roll_back_vertex(total);
	mlx_put_image_to_window(total->mlx_data.mlx_ptr,
		total->mlx_data.win_ptr, total->mlx_data.img_data.img, 0, 0);
}
