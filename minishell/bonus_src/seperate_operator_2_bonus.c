/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seperate_operator_2_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:57:17 by sihong            #+#    #+#             */
/*   Updated: 2024/02/07 17:57:21 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	parse_operator_3(char *s, t_parse_list **lst2_tmp, int *i)
{
	if (s[*i] == '(' || s[*i] == ')')
	{
		(*lst2_tmp)->s = ft_substr_adv(s, *i, 1);
		(*lst2_tmp)->token_type = parenthesis;
	}
}
