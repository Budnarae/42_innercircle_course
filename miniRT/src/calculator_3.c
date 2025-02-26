/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:02:24 by chansjeo          #+#    #+#             */
/*   Updated: 2024/06/29 18:02:54 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/miniRT.h"

double	get_radian(double angle)
{
	if (angle < 0.0f)
		return (-1.0f);
	return (PIE / 180.0f * angle);
}

double	max(double a, double b)
{
	if (a < b)
		return (b);
	else
		return (a);
}
