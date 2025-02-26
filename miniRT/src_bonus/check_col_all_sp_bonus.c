/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col_all_sp_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:56:16 by sihong            #+#    #+#             */
/*   Updated: 2024/06/29 18:14:00 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/factor_bonus.h"
#include "../header_bonus/miniRT_bonus.h"

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

t_vec3	get_checker_ball_2(double height, double diameter, \
	t_vec3 color_a, t_vec3 color_b)
{
	if (height >= diameter / 3.0f)
		return (color_a);
	else if (height >= diameter / 6.0f && height < diameter / 3.0f)
		return (color_b);
	else if (height >= 0.0f && height < diameter / 6.0f)
		return (color_a);
	else if (height >= -diameter / 6.0f && height < 0.0f)
		return (color_b);
	else if (height >= -diameter / 3.0f && height < -diameter / 6.0f)
		return (color_a);
	else
		return (color_b);
}

t_vec3	get_checker_ball(t_col_info col, t_sphere sp)
{
	t_vec3	o;
	t_vec3	c_col;
	double	col_angle;
	double	height;

	o = get_vec3(0.0f, 0.0f, 1.0f);
	c_col = vec3_normalize(vec3_sub(col.pos, \
		get_vec3(sp.center_pos.e[X], col.pos.e[Y], sp.center_pos.e[Z])));
	height = col.pos.e[Y] - sp.center_pos.e[Y];
	col_angle = \
		acos(o.e[X] * c_col.e[X] + o.e[Z] * c_col.e[Z]) * (180.0f / PIE);
	if (((int)(col_angle / 30.0f) % 2 == 0 && c_col.e[X] < o.e[X]) \
		|| ((int)(col_angle / 30.0f) % 2 == 1 && c_col.e[X] > o.e[X]))
		return (get_checker_ball_2(height, sp.diameter, \
			sp.color, get_vec3(255.0f, 255.0f, 255.0f)));
	else
		return (get_checker_ball_2(height, sp.diameter, \
			get_vec3(255.0f, 255.0f, 255.0f), sp.color));
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
		if (i == 0 && vec3_iszero(col.n_vec) == FALSE)
			col.color = get_checker_ball(col, sp[i]);
		i++;
	}
	return (col);
}
