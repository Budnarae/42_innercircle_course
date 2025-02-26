/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:58:21 by chansjeo          #+#    #+#             */
/*   Updated: 2024/06/29 20:16:43 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/miniRT_bonus.h"

// Constructors
t_vec3	get_vec3(double e0, double e1, double e2)
{
	t_vec3	v;

	v.e[X] = e0;
	v.e[Y] = e1;
	v.e[Z] = e2;
	return (v);
}

// Unary operators
t_vec3	vec3_negate(const t_vec3 v)
{
	return (get_vec3(-v.e[X], -v.e[Y], -v.e[Z]));
}

// Binary operators
t_vec3	vec3_add(const t_vec3 u, const t_vec3 v)
{
	return (get_vec3(u.e[X] + v.e[X], u.e[Y] + v.e[Y], u.e[Z] + v.e[Z]));
}

t_vec3	vec3_sub(const t_vec3 u, const t_vec3 v)
{
	return (get_vec3(u.e[X] - v.e[X], u.e[Y] - v.e[Y], u.e[Z] - v.e[Z]));
}

t_vec3	vec3_mul(const t_vec3 u, const t_vec3 v)
{
	return (get_vec3(u.e[X] * v.e[X], u.e[Y] * v.e[Y], u.e[Z] * v.e[Z]));
}
