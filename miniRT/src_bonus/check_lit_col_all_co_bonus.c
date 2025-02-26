/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lit_col_all_co_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:10:49 by sihong            #+#    #+#             */
/*   Updated: 2024/07/05 11:10:51 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/factor_bonus.h"
#include "../header_bonus/miniRT_bonus.h"

int	check_lit_col_co_side(t_vec3 col_pos, t_vec3 lit_pos, t_cone co)
{
	t_dic	dic;
	double	y;

	dic = get_co_side_dic(col_pos, lit_pos, co);
	if (dic.dic <= 0.0f)
		return (FALSE);
	if (dic.t_neg > 0.001f && dic.t_neg < 0.999f)
	{
		y = dic.t_neg * lit_pos.e[Y] + (1.0f - dic.t_neg) * col_pos.e[Y];
		if (y > 0.0f && y < co.height)
			return (TRUE);
	}
	if (dic.t_pos > 0.001f && dic.t_pos < 0.999f)
	{
		y = dic.t_pos * lit_pos.e[Y] + (1.0f - dic.t_pos) * col_pos.e[Y];
		if (y > 0.0f && y < co.height)
			return (TRUE);
	}
	return (FALSE);
}

int	check_lit_col_co_cap(t_vec3 col_pos, t_vec3 lit_pos, t_cone co)
{
	double	t;
	double	x;
	double	z;

	if (col_pos.e[Y] == lit_pos.e[Y])
		return (FALSE);
	t = -lit_pos.e[Y] / (col_pos.e[Y] - lit_pos.e[Y]);
	if (t > 0.001f && t < 0.999f)
	{
		x = col_pos.e[X] * t + lit_pos.e[X] * (1 - t);
		z = col_pos.e[Z] * t + lit_pos.e[Z] * (1 - t);
		if (pow(x, 2.0f) + pow(z, 2.0f) <= pow(co.diameter / 2.0f, 2.0f))
			return (TRUE);
	}
	return (FALSE);
}

int	check_lit_col_all_co(int lit_num, t_vec3 col_pos, t_factor *f)
{
	int			i;
	t_mat4x4	rev_co;
	t_vec3		n_col_pos;
	t_vec3		n_lit_pos;

	i = 0;
	while (i < f->tab[CONE])
	{
		rev_co = get_rev_fi_matrix(f->co[i].center_pos, f->co[i].unit_vec);
		n_col_pos = vec4_to_3(mat4x4_vec4_mul(rev_co, \
			vec3_to_4(col_pos, 1.0f)));
		n_lit_pos = vec4_to_3(mat4x4_vec4_mul(rev_co, \
			vec3_to_4(f->light[lit_num].light_pos, 1.0f)));
		if (check_lit_col_co_side(n_col_pos, n_lit_pos, f->co[i]) == TRUE \
			|| check_lit_col_co_cap(n_col_pos, n_lit_pos, f->co[i]) == TRUE)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
