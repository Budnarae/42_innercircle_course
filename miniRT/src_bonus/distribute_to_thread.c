/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_to_thread.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:46:32 by chansjeo          #+#    #+#             */
/*   Updated: 2024/07/02 15:37:59 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/factor_bonus.h"
#include "../header_bonus/miniRT_bonus.h"

void	*render_section(void *arg)
{
	t_thread_data	*d;
	t_vec3			ray_to_pixel;
	int				pixel_color;
	int				i;
	int				j;

	d = (t_thread_data *)arg;
	i = d->start_y;
	while (i < d->end_y)
	{
		j = d->start_x;
		while (j < d->end_x)
		{
			ray_to_pixel = vec3_normalize(vec3_add(d->up_left_pixel, \
				get_vec3(2.0f / WIDTH * j, -2.0f / HEIGHT * i, 0)));
			pixel_color = create_unit_rgb(shoot_ray_to_pixel(ray_to_pixel, \
			d->f, d->vars));
			my_mlx_pixel_put(d->vars, j, i, pixel_color);
			j++;
		}
		i++;
	}
	return (NULL);
}

void	init_data_and_create_thread(t_thread_tool *tool, pthread_t *threads, \
									t_thread_data *thread_data)
{
	int	i;
	int	row;
	int	col;

	i = -1;
	while (++i < tool->num_threads)
	{
		row = i / tool->cols;
		col = i % tool->cols;
		thread_data[i].start_x = col * tool->section_width;
		thread_data[i].end_x = (col + 1) * tool->section_width;
		thread_data[i].start_y = row * tool->section_height;
		thread_data[i].end_y = (row + 1) * tool->section_height;
		thread_data[i].up_left_pixel = tool->up_left_pixel;
		thread_data[i].vars = tool->vars;
		thread_data[i].f = tool->f;
		if (pthread_create(&threads[i], NULL, render_section, &thread_data[i]))
		{
			free(threads);
			free(thread_data);
			ft_error_msg("Error creating thread\n", 1);
		}
	}
}

void	wait_thread(t_thread_tool *tool, pthread_t *threads, \
					t_thread_data *thread_data)
{
	int	i;

	i = 0;
	while (i < tool->num_threads)
	{
		if (pthread_join(threads[i], NULL))
		{
			free(threads);
			free(thread_data);
			ft_error_msg("Error joining thread\n", 1);
		}
		i++;
	}
	free(threads);
	free(thread_data);
}

void	distribute_to_thread(int rows, int cols, t_vars *vars, t_factor *f)
{
	t_thread_tool	tool;
	pthread_t		*threads;
	t_thread_data	*thread_data;

	tool.num_threads = rows * cols;
	threads = ft_calloc_adv(tool.num_threads, sizeof(pthread_t));
	thread_data = ft_calloc_adv(tool.num_threads, sizeof(t_thread_data));
	tool.section_width = WIDTH / cols;
	tool.section_height = HEIGHT / rows;
	tool.f = f;
	tool.vars = vars;
	tool.cols = cols;
	tool.up_left_pixel = get_vec3(-1.0f, 1.0f, -get_focal_length(f->cam->fov));
	init_data_and_create_thread(&tool, threads, thread_data);
	wait_thread(&tool, threads, thread_data);
}
