/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fdf_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:40:33 by sihong            #+#    #+#             */
/*   Updated: 2024/01/11 18:40:41 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	find_biggest_col_z_size(t_map_size *map_size, int row_size,
	t_vertex ***vertex)
{
	int	i;

	map_size -> biggest_col_size = 0;
	if ((map_size -> col_size)[row_size] > map_size -> biggest_col_size)
		map_size -> biggest_col_size = (map_size -> col_size)[row_size];
	map_size -> biggest_z_size = 0;
	i = 0;
	while (i < map_size -> col_size[row_size])
	{
		if (map_size -> biggest_z_size < (int)(*vertex)[row_size][i].vertex[2])
			map_size -> biggest_z_size = (int)(*vertex)[row_size][i].vertex[2];
		i++;
	}
}
