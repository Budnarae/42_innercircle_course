/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relocate_to_view_space_bonus_2.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:48:31 by sihong            #+#    #+#             */
/*   Updated: 2024/07/02 17:48:37 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/factor_bonus.h"
#include "../header_bonus/miniRT_bonus.h"

void	relocate_cones_to_view_space(int co_num, t_cone *co, \
		t_mat4x4 view)
{
	t_vec3	tmp;
	int		i;

	i = 0;
	while (i < co_num)
	{
		tmp = vec3_add(co[i].center_pos, co[i].unit_vec);
		tmp = relocate_vertex_to_view_space(tmp, view);
		co[i].center_pos = \
			relocate_vertex_to_view_space(co[i].center_pos, view);
		co[i].unit_vec = vec3_sub(tmp, co[i].center_pos);
		i += 1;
	}
}
