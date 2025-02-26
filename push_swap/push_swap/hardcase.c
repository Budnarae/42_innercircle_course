/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 17:34:50 by sihong            #+#    #+#             */
/*   Updated: 2023/12/25 17:34:52 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_3(t_stack **a)
{
	t_stack	*temp;

	if (check_alignment(a))
		return ;
	temp = find_smallest_data_3(*a, (*a)->llink, (*a)->rlink);
	if (temp == *a)
	{
		swap(a, 'a');
		rotate(a, 'a');
	}
	else if (temp == (*a)->llink)
	{
		if ((*a)->data < (*a)->rlink->data)
			swap(a, 'a');
		else
			rotate(a, 'a');
	}
	case_3_2(a, temp);
}

void	case_3_2(t_stack **a, t_stack *temp)
{
	if (temp == (*a)->rlink)
	{
		if ((*a)->data > (*a)->llink->data)
		{
			swap(a, 'a');
			reverse_rotate(a, 'a');
		}
		else
		{
			rotate(a, 'a');
			rotate(a, 'a');
		}
	}
}

void	case_4(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (check_alignment(a) == 1)
		return ;
	temp = find_smallest_data_4(*a, (*a)->llink,
			(*a)->llink->llink, (*a)->rlink);
	if (temp == (*a)->rlink)
		reverse_rotate(a, 'a');
	while (temp != *a)
		rotate(a, 'a');
	pb(a, b, 'o');
	case_3(a);
	pa(a, b, 'o');
}

void	case_5(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (check_alignment(a) == 1)
		return ;
	temp = find_smallest_data_4(*a, (*a)->llink,
			(*a)->llink->llink, (*a)->rlink->rlink);
	if (temp->data > (*a)->rlink->data)
		reverse_rotate(a, 'a');
	else if (temp == (*a)->rlink->rlink)
	{
		reverse_rotate(a, 'a');
		reverse_rotate(a, 'a');
	}
	else
	{
		while (temp != *a)
			rotate(a, 'a');
	}
	pb(a, b, 'o');
	case_4(a, b);
	pa(a, b, 'o');
}
