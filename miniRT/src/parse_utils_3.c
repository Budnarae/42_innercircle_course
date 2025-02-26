/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:26:59 by chansjeo          #+#    #+#             */
/*   Updated: 2024/06/29 18:27:12 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/miniRT.h"

void	get_sp(t_sphere *sp, char **args)
{
	get_three_pos(&sp->center_pos, args[1], 0);
	sp->diameter = ft_atof(args[2]);
	get_three_pos(&sp->color, args[3], COLOR);
}

void	get_cy(t_cylinder *cy, char **args)
{
	get_three_pos(&cy->center_pos, args[1], 0);
	get_three_pos(&cy->unit_vec, args[2], UNIT_VEC);
	cy->diameter = ft_atof(args[3]);
	cy->height = ft_atof(args[4]);
	get_three_pos(&cy->color, args[5], COLOR);
}
