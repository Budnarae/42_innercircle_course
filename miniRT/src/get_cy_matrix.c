/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cy_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:53:26 by sihong            #+#    #+#             */
/*   Updated: 2024/06/29 18:42:18 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/factor.h"
#include "../header/miniRT.h"

t_vec3	*get_cy_xyz_local(t_cylinder cy)
{
	t_vec3	*local;
	t_vec3	front;
	t_vec3	right;

	local = ft_calloc_adv(3, sizeof(t_vec3));
	right = get_vec3(1.0f, 0.0f, 0.0f);
	front = get_vec3(0.0f, 0.0f, 1.0f);
	local[Y] = vec3_normalize(cy.unit_vec);
	if (vec3_iszero(vec3_cross(local[Y], front)) == TRUE)
		local[X] = vec3_normalize(vec3_cross(local[Y], right));
	else
		local[X] = vec3_normalize(vec3_cross(local[Y], front));
	local[Z] = vec3_normalize(vec3_cross(local[X], local[Y]));
	return (local);
}

t_mat4x4	get_rev_cy_matrix(t_cylinder cy)
{
	t_mat4x4	rev_cy;
	t_vec3		*local;

	local = get_cy_xyz_local(cy);
	rev_cy.e[0][0] = local[X].e[X];
	rev_cy.e[0][1] = local[X].e[Y];
	rev_cy.e[0][2] = local[X].e[Z];
	rev_cy.e[0][3] = -vec3_dot(cy.center_pos, local[X]);
	rev_cy.e[1][0] = local[Y].e[X];
	rev_cy.e[1][1] = local[Y].e[Y];
	rev_cy.e[1][2] = local[Y].e[Z];
	rev_cy.e[1][3] = -vec3_dot(cy.center_pos, local[Y]);
	rev_cy.e[2][0] = local[Z].e[X];
	rev_cy.e[2][1] = local[Z].e[Y];
	rev_cy.e[2][2] = local[Z].e[Z];
	rev_cy.e[2][3] = -vec3_dot(cy.center_pos, local[Z]);
	rev_cy.e[3][0] = 0.0f;
	rev_cy.e[3][1] = 0.0f;
	rev_cy.e[3][2] = 0.0f;
	rev_cy.e[3][3] = 1.0f;
	free(local);
	return (rev_cy);
}

t_mat4x4	get_cy_matrix(t_cylinder cyl)
{
	t_mat4x4	cy;
	t_vec3		*local;

	local = get_cy_xyz_local(cyl);
	cy.e[0][0] = local[X].e[X];
	cy.e[0][1] = local[Y].e[X];
	cy.e[0][2] = local[Z].e[X];
	cy.e[0][3] = cyl.center_pos.e[X];
	cy.e[1][0] = local[X].e[Y];
	cy.e[1][1] = local[Y].e[Y];
	cy.e[1][2] = local[Z].e[Y];
	cy.e[1][3] = cyl.center_pos.e[Y];
	cy.e[2][0] = local[X].e[Z];
	cy.e[2][1] = local[Y].e[Z];
	cy.e[2][2] = local[Z].e[Z];
	cy.e[2][3] = cyl.center_pos.e[Z];
	cy.e[3][0] = 0.0f;
	cy.e[3][1] = 0.0f;
	cy.e[3][2] = 0.0f;
	cy.e[3][3] = 1.0f;
	free(local);
	return (cy);
}
