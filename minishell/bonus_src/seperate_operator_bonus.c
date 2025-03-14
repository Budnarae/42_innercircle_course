/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seperate_operator_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:20:18 by sihong            #+#    #+#             */
/*   Updated: 2024/02/06 18:20:26 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	check_operator(char *s)
{
	if ((s[0] == '<' && s[1] != '<')
		|| (s[0] == '>' && s[1] != '>')
		|| (s[0] == '<' && s[1] == '<')
		|| (s[0] == '>' && s[1] == '>')
		|| (s[0] == '|' && s[1] != '|')
		|| (s[0] == '|' && s[1] == '|')
		|| (s[0] == '&' && s[1] == '&')
		|| s[0] == '(' || s[0] == ')')
		return (1);
	return (0);
}

void	parse_none_operator(char *s, int *i, t_parse_list **lst2_tmp)
{
	int	anchor;

	anchor = *i;
	while (s[*i] != 0 && check_operator(&s[*i]) == 0)
		*i += 1;
	(*lst2_tmp)->s = ft_substr_adv(s, anchor, *i - anchor);
	(*lst2_tmp)->token_type = args;
}

void	parse_operator_2(char *s, t_parse_list **lst2_tmp, int *i)
{
	if ((s[*i] == '<' && s[*i + 1] != '<')
		|| (s[*i] == '>' && s[*i + 1] != '>'))
	{
		(*lst2_tmp)->s = ft_substr_adv(s, *i, 1);
		(*lst2_tmp)->token_type = redirection;
	}
	else if (s[*i] == '|' && s[*i + 1] != '|')
	{
		(*lst2_tmp)->s = ft_substr_adv(s, *i, 1);
		(*lst2_tmp)->token_type = pipex;
	}
	else if ((s[*i] == '<' && s[*i + 1] == '<')
		|| (s[*i] == '>' && s[*i + 1] == '>'))
	{
		(*lst2_tmp)->s = ft_substr_adv(s, *i, 2);
		(*lst2_tmp)->token_type = redirection;
		*i += 1;
	}
	else if ((s[*i] == '|' && s[*i + 1] == '|')
		|| (s[*i] == '&' && s[*i + 1] == '&'))
	{
		(*lst2_tmp)->s = ft_substr_adv(s, *i, 2);
		(*lst2_tmp)->token_type = logical;
		*i += 1;
	}
}

void	parse_operator(char *s, t_parse_list **lst2_tmp)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (check_operator(&s[i]) == 1)
		{
			parse_operator_2(s, lst2_tmp, &i);
			parse_operator_3(s, lst2_tmp, &i);
			i += 1;
		}
		else
			parse_none_operator(s, &i, lst2_tmp);
		(*lst2_tmp)->next = ft_calloc_adv(1, sizeof(t_parse_list));
		*lst2_tmp = (*lst2_tmp)->next;
	}
}

t_parse_list	*seperate_operator(t_parse_list *lst1_head)
{
	t_parse_list	*lst2_head;
	t_parse_list	*lst1_tmp;
	t_parse_list	*lst2_tmp;

	lst2_head = ft_calloc_adv(1, sizeof(t_parse_list));
	lst2_tmp = lst2_head;
	while (lst1_head)
	{
		if (lst1_head->token_type == single_quote \
			|| lst1_head->token_type == double_quote)
		{
			lst2_tmp->s = lst1_head->s;
			lst2_tmp->token_type = lst1_head->token_type;
			lst2_tmp->next = ft_calloc_adv(1, sizeof(t_parse_list));
			lst2_tmp = lst2_tmp->next;
		}
		else if (lst1_head->s != 0)
			parse_operator(lst1_head->s, &lst2_tmp);
		lst1_tmp = lst1_head;
		lst1_head = lst1_head->next;
		free(lst1_tmp);
	}
	return (lst2_head);
}
