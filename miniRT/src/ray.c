/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:58:43 by chansjeo          #+#    #+#             */
/*   Updated: 2024/06/29 18:29:10 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/vector.h"
#include "../header/miniRT.h"

t_col_info	get_fake_col(void)
{
	t_col_info	col;

	col.pos = get_vec3(0.0f, 0.0f, 0.0f);
	col.n_vec = get_vec3(0.0f, 0.0f, 0.0f);
	col.color = get_vec3(0.0f, 0.0f, 0.0f);
	return (col);
}

t_col_info	get_closer_coord(t_col_info v1, t_col_info v2)
{
	if (vec3_iszero(v1.n_vec) == TRUE && vec3_iszero(v2.n_vec) == TRUE)
		return (v1);
	else if (vec3_iszero(v1.n_vec) == TRUE && vec3_iszero(v2.n_vec) == FALSE)
		return (v2);
	else if (vec3_iszero(v1.n_vec) == FALSE && vec3_iszero(v2.n_vec) == TRUE)
		return (v1);
	else if (vec3_get_norm(v1.pos) > vec3_get_norm(v2.pos))
		return (v2);
	else
		return (v1);
}
