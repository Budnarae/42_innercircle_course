/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:27:12 by sihong            #+#    #+#             */
/*   Updated: 2024/01/15 13:27:24 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_hook_2(int keycode, t_total *total)
{
	if (keycode == A)
		total->control.x_pitch -= 5.0f;
	if (keycode == D)
		total->control.x_pitch += 5.0f;
	if (keycode == W)
		total->control.y_roll += 5.0f;
	if (keycode == S)
		total->control.y_roll -= 5.0f;
	if (keycode == Q)
		total->control.z_yaw -= 5.0f;
	if (keycode == E)
		total->control.z_yaw += 5.0f;
	if (keycode == UP)
		total->control.scale_factor += 3.0f;
	if (keycode == DOWN && total->control.scale_factor >= 4.0f)
		total->control.scale_factor -= 3.0f;
	if (keycode == J)
		total->control.t_x -= 50.0f;
	if (keycode == L)
		total->control.t_x += 50.0f;
}

int	key_hook(int keycode, t_total *total)
{
	key_hook_2(keycode, total);
	if (keycode == I)
		total->control.t_y += 50.0f;
	if (keycode == K)
		total->control.t_y -= 50.0f;
	if (keycode == U)
		total->control.t_z -= 50.0f;
	if (keycode == O)
		total->control.t_z += 50.0f;
	if (keycode == SPACE)
	{
		if (total -> viewpoint == ISO)
			total -> viewpoint = CAB;
		else
			total -> viewpoint = ISO;
	}
	if (keycode == ESC)
		end_fdf(&total->mlx_data);
	mlx_destroy_image(total->mlx_data.mlx_ptr, total->mlx_data.img_data.img);
	draw_window(total);
	return (0);
}
