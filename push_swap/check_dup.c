/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:24:20 by sihong            #+#    #+#             */
/*   Updated: 2023/12/26 11:24:22 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup(int arr_len, char **arr, int check_zero)
{
	int		i;
	int		func_returned;
	t_node	*tree;

	tree = 0;
	if (check_zero == 0)
		i = 1;
	else
		i = 0;
	while (i < arr_len)
	{
		func_returned = search_tree(&tree, ft_atoi(arr[i]));
		if (func_returned == -1 || func_returned == 1)
		{
			free_tree(tree);
			return (-1);
		}
		if (i % 20 == 0)
			balance_tree(&tree, 0);
		i++;
	}
	free_tree(tree);
	return (0);
}
