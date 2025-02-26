/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:00:59 by chansjeo          #+#    #+#             */
/*   Updated: 2024/06/29 18:02:49 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/miniRT.h"

int	vec3_iszero(t_vec3 v)
{
	if (v.e[X] == 0.0f && v.e[Y] == 0.0f && v.e[Z] == 0.0f)
		return (TRUE);
	else
		return (FALSE);
}

t_vec3	vec3_scale(double scalar, t_vec3 v)
{
	return (get_vec3(scalar * v.e[X], scalar * v.e[Y], scalar * v.e[Z]));
}

t_vec4	get_vec4(double x, double y, double z, double w)
{
	t_vec4	v;

	v.e[X] = x;
	v.e[Y] = y;
	v.e[Z] = z;
	v.e[W] = w;
	return (v);
}

t_vec4	vec3_to_4(t_vec3 v, double w)
{
	if (w == 0.0f)
		return (get_vec4(v.e[X], v.e[Y], v.e[Z], w));
	else
		return (get_vec4(v.e[X], v.e[Y], v.e[Z], 1.0f));
}

t_vec3	vec4_to_3(t_vec4 v)
{
	return (get_vec3(v.e[X], v.e[Y], v.e[Z]));
}
