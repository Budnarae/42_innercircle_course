/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:23:30 by chansjeo          #+#    #+#             */
/*   Updated: 2024/06/29 18:27:29 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/miniRT.h"

void	get_three_pos(t_vec3 *v, char *arg, int type)
{
	char	*buf;
	int		cnt;

	cnt = 0;
	while (1)
	{
		buf = ft_strsep(&arg, ",");
		if (!buf)
			break ;
		v->e[cnt] = ft_atof(buf);
		if (type == COLOR && !(v->e[cnt] >= 0 && v->e[cnt] < 256))
			ft_error_msg("Out of range in color\n", 1);
		else if (type == UNIT_VEC && !(v->e[cnt] >= -1 && v->e[cnt] <= 1.0))
			ft_error_msg("Out of range in unit_vec\n", 1);
		cnt++;
	}
	if (cnt != 3)
		ft_error_msg("There must be only three points in vec3.\n", 1);
}

void	get_amb(t_ambient *amb, char **args)
{
	amb->range = ft_atof(args[1]);
	if (!(amb->range >= 0 && amb->range <= 1.0))
		ft_error_msg("Out of range in ambient range\n", 1);
	get_three_pos(&amb->color, args[2], COLOR);
}

void	get_cam(t_camera *cam, char **args)
{
	get_three_pos(&cam->view_pos, args[1], 0);
	get_three_pos(&cam->unit_vec, args[2], UNIT_VEC);
	cam->fov = ft_atof(args[3]);
	if (!(cam->fov >= 0 && cam->fov <= 180))
		ft_error_msg("Out of range in FOV\n", 1);
}

void	get_light(t_light *light, char **args)
{
	get_three_pos(&light->light_pos, args[1], 0);
	light->range = ft_atof(args[2]);
	if (!(light->range >= 0 && light->range <= 1.0))
		ft_error_msg("Out of range in light range\n", 1);
	get_three_pos(&light->color, args[3], COLOR);
}

void	get_pl(t_plane *pl, char **args)
{
	get_three_pos(&pl->plane_pos, args[1], 0);
	get_three_pos(&pl->unit_vec, args[2], UNIT_VEC);
	if (!pl->unit_vec.e[0] && !pl->unit_vec.e[1] && !pl->unit_vec.e[2])
		ft_error_msg("A plane can not be calculate\n", 1);
	get_three_pos(&pl->color, args[3], COLOR);
}
