/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:41:49 by chansjeo          #+#    #+#             */
/*   Updated: 2024/03/06 18:45:28 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	is_valid(char *param)
{
	int	i;

	i = 0;
	while (param && param[i])
	{
		if (!ft_isalnum(param[i]) && param[i] != '_')
			return (0);
		i++;
	}
	return (1);
}
