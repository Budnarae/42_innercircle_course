/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:34:42 by sihong            #+#    #+#             */
/*   Updated: 2024/01/11 16:34:48 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	init_t_screen(float m[4][4], t_screen_size screen_size)
{
	m[0][0] = 1.0f;
	m[0][1] = 0.0f;
	m[0][2] = 0.0f;
	m[0][3] = (float)screen_size.col / 2;
	m[1][0] = 0.0f;
	m[1][1] = 1.0f;
	m[1][2] = 0.0f;
	m[1][3] = (float)screen_size.row / 2;
	m[2][0] = 0.0f;
	m[2][1] = 0.0f;
	m[2][2] = 1.0f;
	m[2][3] = 0.0f;
	m[3][0] = 0.0f;
	m[3][1] = 0.0f;
	m[3][2] = 0.0f;
	m[3][3] = 1.0f;
}

void	init_r_isometric(float m[4][4])
{
	float	d;

	d = 45.0f * PI / 180.0f;
	m[0][0] = cos(d);
	m[0][1] = sin(d);
	m[0][2] = 0.0f;
	m[0][3] = 0.0f;
	m[1][0] = -cos(d) * sin(d);
	m[1][1] = cos(d) * cos(d);
	m[1][2] = -sin(d);
	m[1][3] = 0.0f;
	m[2][0] = -(sin(d) * sin(d));
	m[2][1] = cos(d) * sin(d);
	m[2][2] = cos(d);
	m[2][3] = 0.0f;
	m[3][0] = 0.0f;
	m[3][1] = 0.0f;
	m[3][2] = 0.0f;
	m[3][3] = 1.0f;
}

void	init_t(float m[4][4], t_control c)
{
	m[0][0] = 1.0f;
	m[0][1] = 0.0f;
	m[0][2] = 0.0f;
	m[0][3] = c.t_x;
	m[1][0] = 0.0f;
	m[1][1] = 1.0f;
	m[1][2] = 0.0f;
	m[1][3] = c.t_y;
	m[2][0] = 0.0f;
	m[2][1] = 0.0f;
	m[2][2] = 1.0f;
	m[2][3] = c.t_z;
	m[3][0] = 0.0f;
	m[3][1] = 0.0f;
	m[3][2] = 0.0f;
	m[3][3] = 1.0f;
}

void	matrix_multiplication_4x4_4x4(float m1[4][4], float m2[4][4])
{
	int		i;
	int		j;
	float	tmp[4][4];

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			tmp[i][j] = m1[i][0] * m2[0][j] + m1[i][1] * m2[1][j]
				+ m1[i][2] * m2[2][j] + m1[i][3] * m2[3][j];
	}
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			m2[i][j] = tmp[i][j];
	}
}

void	matrix_multiplication_4x4_1x4(float m1[4][4], float m2[4])
{
	int		i;
	float	tmp[4];

	i = -1;
	while (++i < 4)
	{
		tmp[i] = m1[i][0] * m2[0] + m1[i][1] * m2[1]
			+ m1[i][2] * m2[2] + m1[i][3] * m2[3];
	}
	i = -1;
	while (++i < 4)
		m2[i] = tmp[i];
}
