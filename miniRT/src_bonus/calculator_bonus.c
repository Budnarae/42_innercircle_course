/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:14:24 by sihong            #+#    #+#             */
/*   Updated: 2024/06/29 18:02:39 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/miniRT_bonus.h"

double	vec3_get_norm(t_vec3 v)
{
	return (sqrt(pow(v.e[X], 2.0f) + pow(v.e[Y], 2.0f) + pow(v.e[Z], 2.0f)));
}

t_vec3	vec3_normalize(t_vec3 v)
{
	double	norm;

	norm = vec3_get_norm(v);
	if (norm == 0.0f)
		return (v);
	return (get_vec3(v.e[X] / norm, v.e[Y] / norm, v.e[Z] / norm));
}

t_vec4	mat4x4_vec4_mul(t_mat4x4 m, t_vec4 v)
{
	t_vec4	mv;
	int		i;
	int		j;

	mv = get_vec4(0.0f, 0.0f, 0.0f, 0.0f);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			mv.e[i] += m.e[i][j] * v.e[j];
			j++;
		}
		i++;
	}
	return (mv);
}

t_mat4x4	get_zero_mat4x4(void)
{
	t_mat4x4	m;

	m.e[0][0] = 0.0f;
	m.e[0][1] = 0.0f;
	m.e[0][2] = 0.0f;
	m.e[0][3] = 0.0f;
	m.e[1][0] = 0.0f;
	m.e[1][1] = 0.0f;
	m.e[1][2] = 0.0f;
	m.e[1][3] = 0.0f;
	m.e[2][0] = 0.0f;
	m.e[2][1] = 0.0f;
	m.e[2][2] = 0.0f;
	m.e[2][3] = 0.0f;
	m.e[3][0] = 0.0f;
	m.e[3][1] = 0.0f;
	m.e[3][2] = 0.0f;
	m.e[3][3] = 0.0f;
	return (m);
}

t_mat4x4	mat4x4_mat4x4_mul(t_mat4x4 m2, t_mat4x4 m1)
{
	t_mat4x4	m;
	int			i;
	int			j;
	int			k;

	m = get_zero_mat4x4();
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				m.e[i][j] += m2.e[i][k] * m1.e[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (m);
}
