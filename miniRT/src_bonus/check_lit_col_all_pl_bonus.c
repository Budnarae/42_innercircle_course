/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lit_col_all_pl_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:15:27 by sihong            #+#    #+#             */
/*   Updated: 2024/06/29 18:15:28 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/factor_bonus.h"
#include "../header_bonus/miniRT_bonus.h"

int	check_lit_col_all_pl(int lit_num, t_vec3 col_pos, t_factor *f)
{
	int		i;
	t_vec3	l_sub_p;
	t_vec3	o_sub_l;
	double	t;

	i = 0;
	while (i < f->tab[PLANE])
	{
		l_sub_p = vec3_sub(f->light[lit_num].light_pos, f->pl[i].plane_pos);
		o_sub_l = vec3_sub(col_pos, f->light[lit_num].light_pos);
		if (vec3_dot(f->pl[i].unit_vec, o_sub_l) == 0.0f)
		{
			i++;
			continue ;
		}
		t = -1.0f * vec3_dot(f->pl[i].unit_vec, l_sub_p) \
			/ vec3_dot(f->pl[i].unit_vec, o_sub_l);
		if (t > 0.001f && t < 0.999f)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
