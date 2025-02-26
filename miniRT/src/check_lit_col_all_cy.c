/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lit_col_all_cy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:12:02 by sihong            #+#    #+#             */
/*   Updated: 2024/06/29 17:54:12 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/factor.h"
#include "../header/miniRT.h"

t_dic	get_lit_cy_side(t_vec3 col_pos, t_vec3 lit_pos, double diameter)
{
	t_vec3	o_sub_l;
	t_dic	dic;

	o_sub_l = vec3_sub(col_pos, lit_pos);
	dic.a = vec3_dot(o_sub_l, o_sub_l) - pow(o_sub_l.e[Y], 2.0f);
	dic.b = 2.0f * vec3_dot(o_sub_l, lit_pos) \
		- 2.0f * o_sub_l.e[Y] * lit_pos.e[Y];
	dic.c = vec3_dot(lit_pos, lit_pos) - pow(lit_pos.e[Y], 2.0f) \
			- pow(diameter / 2.0f, 2.0f);
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

int	check_lit_col_cy_side(t_vec3 col_pos, t_vec3 lit_pos, t_cylinder cy)
{
	t_dic	dic;
	double	y;

	dic = get_lit_cy_side(col_pos, lit_pos, cy.diameter);
	if (dic.dic <= 0.0f)
		return (FALSE);
	if (dic.t_neg > 0.001f && dic.t_neg < 0.999f)
	{
		y = dic.t_neg * col_pos.e[Y] + (1.0f - dic.t_neg) * lit_pos.e[Y];
		if (y > -cy.height / 2.0f && y < cy.height / 2.0f)
			return (TRUE);
	}
	if (dic.t_pos > 0.001f && dic.t_pos < 0.999f)
	{
		y = dic.t_pos * col_pos.e[Y] + (1.0f - dic.t_pos) * lit_pos.e[Y];
		if (y > -cy.height / 2.0f && y < cy.height / 2.0f)
			return (TRUE);
	}
	return (FALSE);
}

int	check_lit_col_cy_cap(t_vec3 col_pos, t_vec3 lit_pos, t_cylinder cy)
{
	double	t;
	double	x;
	double	z;

	if (col_pos.e[Y] == lit_pos.e[Y] && \
		(lit_pos.e[Y] == cy.height / 2.0f || lit_pos.e[Y] == -cy.height / 2.0f))
		return (FALSE);
	t = (-lit_pos.e[Y] + cy.height / 2.0f) / (col_pos.e[Y] - lit_pos.e[Y]);
	if (t > 0.001f && t < 0.999f)
	{
		x = col_pos.e[X] * t + lit_pos.e[X] * (1 - t);
		z = col_pos.e[Z] * t + lit_pos.e[Z] * (1 - t);
		if (pow(x, 2.0f) + pow(z, 2.0f) <= pow(cy.diameter / 2.0f, 2.0f))
			return (TRUE);
	}
	t = (-lit_pos.e[Y] - cy.height / 2.0f) / (col_pos.e[Y] - lit_pos.e[Y]);
	if (t > 0.001f && t < 0.999f)
	{
		x = col_pos.e[X] * t + lit_pos.e[X] * (1 - t);
		z = col_pos.e[Z] * t + lit_pos.e[Z] * (1 - t);
		if (pow(x, 2.0f) + pow(z, 2.0f) <= pow(cy.diameter / 2.0f, 2.0f))
			return (TRUE);
	}
	return (FALSE);
}

int	check_lit_col_all_cy(t_vec3 col_pos, t_factor *f)
{
	int			i;
	t_mat4x4	rev_cy;
	t_vec3		n_col_pos;
	t_vec3		n_lit_pos;

	i = 0;
	while (i < f->tab[CYLINDER])
	{
		rev_cy = get_rev_cy_matrix(f->cy[i]);
		n_col_pos = vec4_to_3(mat4x4_vec4_mul(rev_cy, \
			vec3_to_4(col_pos, 1.0f)));
		n_lit_pos = vec4_to_3(mat4x4_vec4_mul(rev_cy, \
			vec3_to_4(f->light->light_pos, 1.0f)));
		if (check_lit_col_cy_side(n_col_pos, n_lit_pos, f->cy[i]) == TRUE \
			|| check_lit_col_cy_cap(n_col_pos, n_lit_pos, f->cy[i]) == TRUE)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
