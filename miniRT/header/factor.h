/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 21:32:40 by chansjeo          #+#    #+#             */
/*   Updated: 2024/06/29 19:50:42 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTOR_H
# define FACTOR_H

# include "vector.h"

typedef enum e_element
{
	AMBIENT,
	CAMERA,
	LIGHT,
	PLANE,
	SPHERE,
	CYLINDER,
}	t_element;

typedef struct s_ambient
{
	int		id;
	double	range;
	t_vec3	color;
}	t_ambient;

typedef struct s_camera
{
	int		id;
	t_vec3	view_pos;
	t_vec3	unit_vec;
	double	fov;
}	t_camera;

typedef struct s_light
{
	int		id;
	t_vec3	light_pos;
	double	range;
	t_vec3	color;
}	t_light;

typedef struct s_sphere
{
	int		id;
	t_vec3	center_pos;
	double	diameter;
	t_vec3	color;
}	t_sphere;

typedef struct s_plane
{
	int		id;
	t_vec3	plane_pos;
	t_vec3	unit_vec;
	t_vec3	color;
}	t_plane;

typedef struct s_cylinder
{
	int		id;
	t_vec3	center_pos;
	t_vec3	unit_vec;
	double	diameter;
	double	height;
	t_vec3	color;
}	t_cylinder;

typedef struct s_factor
{
	int			tab[6];
	t_ambient	*amb;	
	t_camera	*cam;
	t_light		*light;
	t_plane		*pl;
	t_sphere	*sp;
	t_cylinder	*cy;
}	t_factor;

#endif
