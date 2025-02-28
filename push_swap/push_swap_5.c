/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:15:18 by sihong            #+#    #+#             */
/*   Updated: 2023/12/27 14:15:20 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	define_count(int triangle, t_stack **a, int *send_count)
{
	if (triangle / 3 <= 1)
	{
		if (*a == 0)
			*send_count = 1;
		else
			*send_count = triangle - 1;
	}
	else
		*send_count = triangle / 3;
}

void	move_triangle_a_to_b(t_stack **a, t_stack **b, int *i)
{
	if ((*b)->data <= (*b)->llink->data || *b == (*b)->llink)
		*i += 1;
	pa(a, b, 'o');
}

void	move_triangle_b_to_a(t_stack **a, t_stack **b, int *i)
{
	if ((*a)->data >= (*a)->llink->data || *a == (*a)->llink)
		*i += 1;
	pb(a, b, 'o');
}

void	merge_to_a(t_stack **a, t_stack **b)
{
	if ((*a)->rlink->data > (*b)->data)
	{
		reverse_rotate(a, 'a');
		if ((*a)->data < (*a)->rlink->data)
		{
			while (*b != 0 && (*a)->data > (*b)->data)
				pa(a, b, 'o');
		}
	}
	else if ((*a)->rlink->data < (*b)->data)
	{
		if (*b != 0)
			pa(a, b, 'o');
		if (*b == 0)
		{
			while (*a != 0 && (*a)->data > (*a)->rlink->data)
				reverse_rotate(a, 'a');
			return ;
		}
		if ((*a)->data < (*b)->data)
		{
			while (*a != 0 && (*a)->data > (*a)->rlink->data)
				reverse_rotate(a, 'a');
		}
	}
}

void	merge_to_b(t_stack **a, t_stack **b)
{
	if ((*b)->rlink->data < (*a)->data)
	{
		reverse_rotate(b, 'b');
		if ((*b)->data > (*b)->rlink->data)
		{
			while (*a != 0 && (*b)->data < (*a)->data)
				pb(a, b, 'o');
		}
	}
	else if ((*b)->rlink->data > (*a)->data)
	{
		if (*a != 0)
			pb(a, b, 'o');
		if (*a == 0)
		{
			while (*b != 0 && (*b)->data < (*b)->rlink->data)
				reverse_rotate(b, 'b');
			return ;
		}
		if ((*b)->data > (*a)->data)
		{
			while (*b != 0 && (*b)->data < (*b)->rlink->data)
				reverse_rotate(b, 'b');
		}
	}
}
