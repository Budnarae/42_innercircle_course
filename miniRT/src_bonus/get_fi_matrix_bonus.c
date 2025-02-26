/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fi_matrix_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:53:26 by sihong            #+#    #+#             */
/*   Updated: 2024/06/29 18:42:18 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/factor_bonus.h"
#include "../header_bonus/miniRT_bonus.h"

t_vec3	*get_fi_xyz_local(t_vec3 unit_vec)
{
	t_vec3	*local;
	t_vec3	front;
	t_vec3	right;

	local = ft_calloc_adv(3, sizeof(t_vec3));
	right = get_vec3(1.0f, 0.0f, 0.0f);
	front = get_vec3(0.0f, 0.0f, 1.0f);
	local[Y] = vec3_normalize(unit_vec);
	if (vec3_iszero(vec3_cross(local[Y], front)) == TRUE)
		local[X] = vec3_normalize(vec3_cross(local[Y], right));
	else
		local[X] = vec3_normalize(vec3_cross(local[Y], front));
	local[Z] = vec3_normalize(vec3_cross(local[X], local[Y]));
	return (local);
}

t_mat4x4	get_rev_fi_matrix(t_vec3 center_pos, t_vec3 unit_vec)
{
	t_mat4x4	rev_fi;
	t_vec3		*local;

	local = get_fi_xyz_local(unit_vec);
	rev_fi.e[0][0] = local[X].e[X];
	rev_fi.e[0][1] = local[X].e[Y];
	rev_fi.e[0][2] = local[X].e[Z];
	rev_fi.e[0][3] = -vec3_dot(center_pos, local[X]);
	rev_fi.e[1][0] = local[Y].e[X];
	rev_fi.e[1][1] = local[Y].e[Y];
	rev_fi.e[1][2] = local[Y].e[Z];
	rev_fi.e[1][3] = -vec3_dot(center_pos, local[Y]);
	rev_fi.e[2][0] = local[Z].e[X];
	rev_fi.e[2][1] = local[Z].e[Y];
	rev_fi.e[2][2] = local[Z].e[Z];
	rev_fi.e[2][3] = -vec3_dot(center_pos, local[Z]);
	rev_fi.e[3][0] = 0.0f;
	rev_fi.e[3][1] = 0.0f;
	rev_fi.e[3][2] = 0.0f;
	rev_fi.e[3][3] = 1.0f;
	free(local);
	return (rev_fi);
}

t_mat4x4	get_fi_matrix(t_vec3 center_pos, t_vec3 unit_vec)
{
	t_mat4x4	fi;
	t_vec3		*local;

	local = get_fi_xyz_local(unit_vec);
	fi.e[0][0] = local[X].e[X];
	fi.e[0][1] = local[Y].e[X];
	fi.e[0][2] = local[Z].e[X];
	fi.e[0][3] = center_pos.e[X];
	fi.e[1][0] = local[X].e[Y];
	fi.e[1][1] = local[Y].e[Y];
	fi.e[1][2] = local[Z].e[Y];
	fi.e[1][3] = center_pos.e[Y];
	fi.e[2][0] = local[X].e[Z];
	fi.e[2][1] = local[Y].e[Z];
	fi.e[2][2] = local[Z].e[Z];
	fi.e[2][3] = center_pos.e[Z];
	fi.e[3][0] = 0.0f;
	fi.e[3][1] = 0.0f;
	fi.e[3][2] = 0.0f;
	fi.e[3][3] = 1.0f;
	free(local);
	return (fi);
}
