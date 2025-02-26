/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col_all_sp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:56:16 by sihong            #+#    #+#             */
/*   Updated: 2024/06/29 18:14:00 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/factor.h"
#include "../header/miniRT.h"

t_dic	get_sp_dic(t_vec3 ray_to_pixel, t_sphere sp)
{
	t_dic	dic;

	dic.a = vec3_dot(ray_to_pixel, ray_to_pixel);
	dic.b = -2.0f * vec3_dot(ray_to_pixel, sp.center_pos);
	dic.c = vec3_dot(sp.center_pos, sp.center_pos) \
			- pow(sp.diameter / 2.0f, 2.0f);
	dic.dic = pow(dic.b, 2.0f) - 4.0f * dic.a * dic.c;
	if (dic.dic < 0.0f)
	{
		dic.t_neg = 0.0f;
		dic.t_pos = 0.0f;
	}
	else if (dic.dic == 0.0f)
	{
		dic.t_neg = -dic.b / (2 * dic.a);
		dic.t_pos = -dic.b / (2 * dic.a);
	}
	else
	{
		dic.t_neg = (-dic.b - sqrt(dic.dic)) / (2 * dic.a);
		dic.t_pos = (-dic.b + sqrt(dic.dic)) / (2 * dic.a);
	}
	return (dic);
}

t_col_info	check_col_1sp(t_vec3 ray_to_pixel, t_sphere sp)
{
	t_dic		dic;
	t_col_info	col;

	dic = get_sp_dic(ray_to_pixel, sp);
	if (dic.dic < 0.0f || (-dic.b + sqrt(dic.dic)) <= 0.0f)
		return (get_fake_col());
	else if (dic.dic == 0.0f)
		col.pos = vec3_scale(dic.t_pos, ray_to_pixel);
	else
	{
		if (-dic.b - sqrt(dic.dic) <= 0.0f)
			col.pos = vec3_scale(dic.t_pos, ray_to_pixel);
		else
			col.pos = vec3_scale(dic.t_neg, ray_to_pixel);
	}
	col.n_vec = vec3_normalize(vec3_sub(col.pos, sp.center_pos));
	if (vec3_dot(ray_to_pixel, col.n_vec) > 0.0f)
		col.n_vec = vec3_normalize(vec3_sub(sp.center_pos, col.pos));
	col.color = sp.color;
	return (col);
}

t_col_info	check_col_all_sp(t_vec3 ray_to_pixel, int sp_num, t_sphere *sp)
{
	int			i;
	t_col_info	col;
	t_col_info	tmp;

	i = 0;
	col = get_fake_col();
	while (i < sp_num)
	{
		tmp = check_col_1sp(ray_to_pixel, sp[i]);
		col = get_closer_coord(col, tmp);
		i++;
	}
	return (col);
}
