/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:12:51 by sihong            #+#    #+#             */
/*   Updated: 2023/12/27 12:12:55 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tree(t_node *tree)
{
	if (tree == 0)
		return ;
	if (tree -> right)
		free_tree(tree -> right);
	if (tree -> left)
		free_tree(tree -> left);
	if (tree)
		free(tree);
}

int	search_tree(t_node **tree, int s)
{
	if (*tree == 0)
	{
		*tree = (t_node *)ft_calloc(1, sizeof(t_node));
		if (*tree == 0)
			return (-1);
		(*tree)->data = s;
		return (0);
	}
	else
	{
		if ((*tree)->data < s)
			return (search_tree(&((*tree)->right), s));
		else if ((*tree)->data == s)
			return (1);
		else
			return (search_tree(&((*tree)->left), s));
	}
}

void	left_case(t_node **tree)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if ((*tree)->left != 0)
	{
		if ((*tree)->left->right != 0)
		{
			if ((*tree)->left->left == 0)
			{
				tmp1 = (*tree)->left;
				tmp2 = (*tree)->left->right;
				(*tree)->left = tmp2;
				tmp2 = (*tree)->left->left;
				(*tree)->left->left = tmp1;
				(*tree)->left->left->right = tmp2;
			}
		}
	}
	tmp1 = *tree;
	tmp2 = (*tree)->left;
	*tree = tmp2;
	tmp2 = (*tree)->right;
	(*tree)->right = tmp1;
	if ((*tree)->right != 0)
		(*tree)->right->left = tmp2;
}

void	right_case(t_node **tree)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if ((*tree)->right != 0)
	{
		if ((*tree)->right->left != 0)
		{
			if ((*tree)->right->right == 0)
			{
				tmp1 = (*tree)->right;
				tmp2 = (*tree)->right->left;
				(*tree)->right = tmp2;
				tmp2 = (*tree)->right->right;
				(*tree)->right->right = tmp1;
				(*tree)->right->right->left = tmp2;
			}
		}
	}
	tmp1 = *tree;
	tmp2 = (*tree)->right;
	*tree = tmp2;
	tmp2 = (*tree)->left;
	(*tree)->left = tmp1;
	if ((*tree)->left != 0)
		(*tree)->left->right = tmp2;
}

int	balance_tree(t_node **tree, int depht)
{
	int	balance_parameter;
	int	depht_l;
	int	depht_r;

	if (*tree == 0)
		return (depht);
	depht_l = balance_tree(&((*tree)->left), depht + 1);
	depht_r = balance_tree(&((*tree)->right), depht + 1);
	balance_parameter = depht_r - depht_l;
	if (balance_parameter < -1)
	{
		left_case(tree);
		return (depht_l - 1);
	}
	else if (balance_parameter > 1)
	{
		right_case(tree);
		return (depht_r - 1);
	}
	if (depht_l > depht_r)
		return (depht_l);
	else
		return (depht_r);
}
