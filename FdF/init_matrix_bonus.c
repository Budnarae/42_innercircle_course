/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:34:27 by sihong            #+#    #+#             */
/*   Updated: 2024/01/11 16:34:35 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	init_r(float m[4][4], t_control c)
{
	float	d;

	d = PI / 180.0f;
	m[0][0] = cos(c.y_roll * d) * cos(c.z_yaw * d)
		+ sin(c.x_pitch * d) * sin(c.y_roll * d) * sin(c.z_yaw);
	m[0][1] = -sin(c.z_yaw * d) * cos(c.x_pitch * d);
	m[0][2] = sin(c.y_roll * d) * cos(c.z_yaw * d)
		+ sin(c.x_pitch * d) * sin(c.z_yaw * d) * cos(c.y_roll * d);
	m[0][3] = 0.0f;
	m[1][0] = sin(c.z_yaw * d) * cos(c.y_roll * d)
		+ sin(c.x_pitch * d) * sin(c.y_roll * d) * cos(c.z_yaw * d);
	m[1][1] = cos(c.x_pitch * d) * cos(c.z_yaw * d);
	m[1][2] = sin(c.y_roll * d) * sin(c.z_yaw * d)
		- sin(c.x_pitch * d) * cos(c.y_roll * d) * cos(c.z_yaw * d);
	m[1][3] = 0.0f;
	m[2][0] = -sin(c.y_roll * d) * cos(c.x_pitch * d);
	m[2][1] = sin(c.x_pitch * d);
	m[2][2] = cos(c.x_pitch * d) * cos(c.y_roll * d);
	m[2][3] = 0.0f;
	m[3][0] = 0.0f;
	m[3][1] = 0.0f;
	m[3][2] = 0.0f;
	m[3][3] = 1.0f;
}

void	init_s(float m[4][4], t_control control)
{
	m[0][0] = control.scale_factor;
	m[0][1] = 0.0f;
	m[0][2] = 0.0f;
	m[0][3] = 0.0f;
	m[1][0] = 0.0f;
	m[1][1] = control.scale_factor;
	m[1][2] = 0.0f;
	m[1][3] = 0.0f;
	m[2][0] = 0.0f;
	m[2][1] = 0.0f;
	m[2][2] = control.scale_factor;
	m[2][3] = 0.0f;
	m[3][0] = 0.0f;
	m[3][1] = 0.0f;
	m[3][2] = 0.0f;
	m[3][3] = 1.0f;
}

void	init_t_origin(float m[4][4], t_map_size ms)
{
	m[0][0] = 1.0f;
	m[0][1] = 0.0f;
	m[0][2] = 0.0f;
	m[0][3] = -(float)ms.biggest_col_size / 2;
	m[1][0] = 0.0f;
	m[1][1] = 1.0f;
	m[1][2] = 0.0f;
	m[1][3] = -(float)ms.row_size / 2;
	m[2][0] = 0.0f;
	m[2][1] = 0.0f;
	m[2][2] = 1.0f;
	m[2][3] = -(float)ms.biggest_z_size / 2;
	m[3][0] = 0.0f;
	m[3][1] = 0.0f;
	m[3][2] = 0.0f;
	m[3][3] = 1.0f;
}

void	init_merged_matrix(float m[4][4])
{
	m[0][0] = 1.0f;
	m[0][1] = 0.0f;
	m[0][2] = 0.0f;
	m[0][3] = 0.0f;
	m[1][0] = 0.0f;
	m[1][1] = 1.0f;
	m[1][2] = 0.0f;
	m[1][3] = 0.0f;
	m[2][0] = 0.0f;
	m[2][1] = 0.0f;
	m[2][2] = 1.0f;
	m[2][3] = 0.0f;
	m[3][0] = 0.0f;
	m[3][1] = 0.0f;
	m[3][2] = 0.0f;
	m[3][3] = 1.0f;
}

void	init_matrix(t_total *total)
{
	init_t_screen(total -> matrixs.t_screen, total -> screen_size);
	init_r_isometric(total -> matrixs.r_isometric);
	init_r_cabinet(total -> matrixs.r_cabinet);
	init_t(total -> matrixs.t, total -> control);
	init_r(total -> matrixs.r, total -> control);
	init_s(total -> matrixs.s, total -> control);
	init_t_origin(total -> matrixs.t_origin, total -> map_size);
	init_merged_matrix(total -> matrixs.merged_matrix);
	matrix_multiplication_4x4_4x4(total -> matrixs.t_origin,
		total -> matrixs.merged_matrix);
	matrix_multiplication_4x4_4x4(total -> matrixs.s,
		total -> matrixs.merged_matrix);
	matrix_multiplication_4x4_4x4(total -> matrixs.r,
		total -> matrixs.merged_matrix);
	matrix_multiplication_4x4_4x4(total -> matrixs.t,
		total -> matrixs.merged_matrix);
	if (total -> viewpoint == ISO)
		matrix_multiplication_4x4_4x4(total -> matrixs.r_isometric,
			total -> matrixs.merged_matrix);
	else if (total -> viewpoint == CAB)
		matrix_multiplication_4x4_4x4(total -> matrixs.r_cabinet,
			total -> matrixs.merged_matrix);
	matrix_multiplication_4x4_4x4(total -> matrixs.t_screen,
		total -> matrixs.merged_matrix);
}
