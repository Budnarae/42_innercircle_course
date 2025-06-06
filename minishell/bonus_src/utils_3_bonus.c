/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:43:58 by sihong            #+#    #+#             */
/*   Updated: 2024/02/15 17:44:01 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

DIR	*opendir_adv(char *s)
{
	DIR	*dp;

	dp = opendir(s);
	if (dp == 0)
		print_error_exit("minishell", 1);
	return (dp);
}
