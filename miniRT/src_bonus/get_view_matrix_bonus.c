/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_view_matrix_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:27:28 by sihong            #+#    #+#             */
/*   Updated: 2024/06/29 18:23:53 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/factor_bonus.h"
#include "../header_bonus/miniRT_bonus.h"

t_vec3	*get_camera_local_axis(t_camera *cam)
{
	t_vec3	*cam_loc_axis;
	t_vec3	up;
	t_vec3	front;

	cam_loc_axis = ft_calloc_adv(3, sizeof(t_vec3));
	up = get_vec3(0.0f, 1.0f, 0.0f);
	front = get_vec3(0.0f, 0.0f, 1.0f);
	cam_loc_axis[Z] = vec3_normalize(cam->unit_vec);
	if (vec3_iszero(vec3_cross(up, cam_loc_axis[Z])))
		cam_loc_axis[X] = vec3_normalize(vec3_cross(front, cam_loc_axis[Z]));
	else
		cam_loc_axis[X] = vec3_normalize(vec3_cross(up, cam_loc_axis[Z]));
	cam_loc_axis[Y] = \
				vec3_normalize(vec3_cross(cam_loc_axis[Z], cam_loc_axis[X]));
	return (cam_loc_axis);
}

t_mat4x4	get_view_matrix(t_camera *cam)
{
	t_vec3		*cam_loc_axis;
	t_mat4x4	view;

	cam_loc_axis = get_camera_local_axis(cam);
	view.e[0][0] = -cam_loc_axis[X].e[X];
	view.e[0][1] = -cam_loc_axis[X].e[Y];
	view.e[0][2] = -cam_loc_axis[X].e[Z];
	view.e[0][3] = vec3_dot(cam_loc_axis[X], cam->view_pos);
	view.e[1][0] = cam_loc_axis[Y].e[X];
	view.e[1][1] = cam_loc_axis[Y].e[Y];
	view.e[1][2] = cam_loc_axis[Y].e[Z];
	view.e[1][3] = -vec3_dot(cam_loc_axis[Y], cam->view_pos);
	view.e[2][0] = -cam_loc_axis[Z].e[X];
	view.e[2][1] = -cam_loc_axis[Z].e[Y];
	view.e[2][2] = -cam_loc_axis[Z].e[Z];
	view.e[2][3] = vec3_dot(cam_loc_axis[Z], cam->view_pos);
	view.e[3][0] = 0;
	view.e[3][1] = 0;
	view.e[3][2] = 0;
	view.e[3][3] = 1;
	free(cam_loc_axis);
	return (view);
}
