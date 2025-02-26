/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:03:51 by sihong            #+#    #+#             */
/*   Updated: 2024/01/11 12:04:04 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	find_col_size_alloc(char ***splited_col, char *col,
	t_vertex ***vertex, int row_size)
{
	int	col_size;

	*splited_col = ft_split(col, ' ');
	if (*splited_col == 0)
		print_error_exit("error : ft_split failed.\n");
	free(col);
	col_size = 0;
	while ((*splited_col)[col_size] && (*splited_col)[col_size][0] != '\n')
		col_size += 1;
	(*vertex)[row_size] = (t_vertex *)ft_calloc(col_size, sizeof(t_vertex));
	if ((*vertex)[row_size] == 0)
		print_error_exit("error : malloc failed.\n");
}

int	input_data_to_col(char **splited_col, t_vertex ***vertex,
	int row_size)
{
	int	col_size;

	col_size = 0;
	while (splited_col[col_size] && splited_col[col_size][0] != '\n')
	{
		(*vertex)[row_size][col_size].vertex[0] = (float)col_size;
		(*vertex)[row_size][col_size].vertex[1] = (float)row_size;
		(*vertex)[row_size][col_size].vertex[2]
			= (float)ft_atoi(splited_col[col_size]);
		(*vertex)[row_size][col_size].vertex[3] = 1.0f;
		define_color((*vertex)[row_size][col_size].vertex,
			(*vertex)[row_size][col_size].color);
		free(splited_col[col_size]);
		col_size += 1;
	}
	if (splited_col[col_size])
		free(splited_col[col_size]);
	free(splited_col);
	return (col_size);
}

void	malloc_vertex_col(t_vertex ***vertex, char *file_name,
	t_map_size *map_size)
{
	int		fd;
	int		row_size;
	char	*col;
	char	**splited_col;

	row_size = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		print_error_exit("error : open failed.\n");
	while (1)
	{
		col = get_next_line(fd);
		if (col == 0)
			break ;
		find_col_size_alloc(&splited_col, col, vertex, row_size);
		(map_size -> col_size)[row_size] = input_data_to_col(splited_col,
				vertex, row_size);
		find_biggest_col_z_size(map_size, row_size, vertex);
		row_size += 1;
	}
	if (read(fd, col, 1) != 0)
		print_error_exit("error : get_next_line failed.\n");
	close(fd);
}

int	malloc_vertex_row(t_vertex ***vertex, char *file_name)
{
	int		fd;
	int		row_size;
	char	*col;

	row_size = 0;
	col = (char *)1;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		print_error_exit("error : open failed.\n");
	while (1)
	{
		col = get_next_line(fd);
		if (col == 0)
			break ;
		row_size += 1;
		free(col);
	}
	if (read(fd, col, 1) != 0)
		print_error_exit("error : get_next_line failed.\n");
	close(fd);
	*vertex = (t_vertex **)ft_calloc(row_size, sizeof(t_vertex **));
	if (*vertex == 0)
		print_error_exit("error : malloc failed.");
	return (row_size);
}

void	parse_fdf(t_vertex ***vertex, char *file_name, t_map_size *map_size)
{
	map_size -> row_size = malloc_vertex_row(vertex, file_name);
	map_size -> col_size = (int *)ft_calloc(map_size -> row_size, sizeof(int));
	if (map_size -> col_size == 0)
		print_error_exit("error : malloc failed.\n");
	malloc_vertex_col(vertex, file_name, map_size);
}
