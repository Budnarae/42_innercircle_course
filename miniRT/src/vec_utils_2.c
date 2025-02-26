/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:40:48 by chansjeo          #+#    #+#             */
/*   Updated: 2024/06/29 20:16:39 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/miniRT.h"

// dot
double	vec3_dot(const t_vec3 u, const t_vec3 v)
{
	return (u.e[X] * v.e[X] + u.e[Y] * v.e[Y] + u.e[Z] * v.e[Z]);
}

// Cross
t_vec3	vec3_cross(const t_vec3 u, const t_vec3 v)
{
	return (get_vec3(u.e[Y] * v.e[Z] - u.e[Z] * v.e[Y], \
				u.e[Z] * v.e[X] - u.e[X] * v.e[Z], \
				u.e[X] * v.e[Y] - u.e[Y] * v.e[X]));
}
