/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lit_col_all_sp.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:10:11 by sihong            #+#    #+#             */
/*   Updated: 2024/06/25 15:10:14 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/factor.h"
#include "../header/miniRT.h"

t_dic	get_lit_sp_dic(t_vec3 col_pos, t_vec3 lit_pos, t_sphere sp)
{
	t_dic	dic;
	t_vec3	o_sub_l;
	t_vec3	l_sub_c;

	o_sub_l = vec3_sub(col_pos, lit_pos);
	l_sub_c = vec3_sub(lit_pos, sp.center_pos);
	dic.a = vec3_dot(o_sub_l, o_sub_l);
	dic.b = 2.0f * vec3_dot(o_sub_l, l_sub_c);
	dic.c = vec3_dot(l_sub_c, l_sub_c) - pow(sp.diameter / 2.0f, 2.0f);
	dic.dic = pow(dic.b, 2) - 4 * dic.a * dic.c;
	if (dic.dic < 0.0f)
	{
		dic.t_neg = 0.0f;
		dic.t_pos = 0.0f;
	}
	else
	{
		dic.t_neg = (-dic.b - sqrt(dic.dic)) / (2 * dic.a);
		dic.t_pos = (-dic.b + sqrt(dic.dic)) / (2 * dic.a);
	}
	return (dic);
}

int	check_lit_col_all_sp(t_vec3 col_pos, t_factor *f)
{
	int		i;
	t_dic	dic;

	i = 0;
	while (i < f->tab[SPHERE])
	{
		dic = get_lit_sp_dic(col_pos, f->light->light_pos, f->sp[i]);
		if (dic.dic > 0.0f)
		{
			if ((dic.t_neg > 0.001f && dic.t_neg < 0.999f) \
				|| (dic.t_pos > 0.001f && dic.t_pos < 0.999f))
				return (TRUE);
		}
		i++;
	}
	return (FALSE);
}
