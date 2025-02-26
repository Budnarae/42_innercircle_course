/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_vertex_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:17:30 by sihong            #+#    #+#             */
/*   Updated: 2024/01/12 11:17:37 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	relocate_vertex(t_vertex **vertex, float m[4][4],
	t_map_size map_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_size.row_size)
	{
		j = 0;
		while (j < map_size.col_size[i])
		{
			matrix_multiplication_4x4_1x4(m, (vertex[i] + j)->vertex);
			j++;
		}
		i++;
	}
}

void	roll_back_vertex(t_total *total)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < total->map_size.row_size)
	{
		j = -1;
		while (++j < total->map_size.col_size[i])
		{
			k = -1;
			while (++k < 4)
				total->vertex[i][j].vertex[k]
					= total->vertex_back_up[i][j].vertex[k];
		}
	}
}

void	back_up_vertex(t_total *total)
{
	int	i;
	int	j;
	int	k;

	total->vertex_back_up
		= (t_vertex **)ft_calloc(total->map_size.row_size, sizeof(t_vertex *));
	if (total->vertex_back_up == 0)
		print_error_exit("ft_calloc failed\n");
	i = -1;
	while (++i < total->map_size.row_size)
	{
		total->vertex_back_up[i] = (t_vertex *)
			ft_calloc(total->map_size.col_size[i], sizeof(t_vertex));
		if (total->vertex_back_up == 0)
			print_error_exit("ft_calloc failed\n");
		j = -1;
		while (++j < total->map_size.col_size[i])
		{
			k = -1;
			while (++k < 4)
				total->vertex_back_up[i][j].vertex[k]
					= total->vertex[i][j].vertex[k];
		}
	}
}
