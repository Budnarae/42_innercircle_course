/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:00:01 by sihong            #+#    #+#             */
/*   Updated: 2024/01/11 12:00:20 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	define_color(float vertex[4], int color[4])
{
	if ((int)vertex[0] / 128 % 2 == 0)
		color[2] = 127 + (int)vertex[0] % 128;
	else
		color[2] = 255 - (int)vertex[0] % 128;
	if ((int)vertex[1] / 128 % 2 == 0)
		color[1] = 127 + (int)vertex[1] % 128;
	else
		color[1] = 255 - (int)vertex[1] % 128;
	if ((int)vertex[2] / 128 % 2 == 0)
		color[0] = 127 + (int)vertex[2] % 128;
	else
		color[0] = 255 - (int)vertex[2] % 128;
	color[3] += (color[0] * (int)pow(16, 4)
			+ color[1] * (int)pow(16, 2) + color[2]);
}

int	end_fdf(t_mlx_data *mlx_data)
{
	mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->img_data.img);
	mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
	exit(0);
	return (0);
}

void	init_struct(t_screen_size *screen_size, t_control *control)
{
	screen_size->col = 2560;
	screen_size->row = 1315;
	control->scale_factor = 5.0f;
	control->x_pitch = 0.0f;
	control->y_roll = 0.0f;
	control->z_yaw = 0.0f;
	control->t_x = 0.0f;
	control->t_y = 0.0f;
	control->t_z = 0.0f;
}

void	print_error_exit(const char *s)
{
	perror(s);
	exit(1);
}

void	check_file_format(char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (!(len >= 4 && file_name[len - 1] == 'f'
			&& file_name[len - 2] == 'd' && file_name[len - 3] == 'f'
			&& file_name[len - 4] == '.'))
		print_error_exit("error : wrong file format.\n");
}
