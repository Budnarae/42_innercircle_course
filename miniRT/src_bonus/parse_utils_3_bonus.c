/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_3_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:26:59 by chansjeo          #+#    #+#             */
/*   Updated: 2024/07/02 13:37:13 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/miniRT_bonus.h"

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

void	get_co(t_cone *co, char **args)
{
	get_three_pos(&co->center_pos, args[1], 0);
	get_three_pos(&co->unit_vec, args[2], UNIT_VEC);
	co->diameter = ft_atof(args[3]);
	co->height = ft_atof(args[4]);
	get_three_pos(&co->color, args[5], COLOR);
}

void	reset_factor(t_factor *f)
{
	f->amb -= f->tab[0];
	f->cam -= f->tab[1];
	f->light -= f->tab[2];
	f->pl -= f->tab[3];
	f->sp -= f->tab[4];
	f->cy -= f->tab[5];
	f->co -= f->tab[6];
}
