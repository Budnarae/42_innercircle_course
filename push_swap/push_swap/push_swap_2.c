/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:41:12 by sihong            #+#    #+#             */
/*   Updated: 2023/12/25 14:41:14 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_smallest_data_4(t_stack *a, t_stack *b, t_stack *c, t_stack *d)
{
	t_stack	*output;

	output = a;
	if (b->data < output->data)
		output = b;
	if (c->data < output->data)
		output = c;
	if (d->data < output->data)
		output = d;
	return (output);
}

t_stack	*find_smallest_data_3(t_stack *a, t_stack *b, t_stack *c)
{
	t_stack	*output;

	output = a;
	if (b->data < output->data)
		output = b;
	if (c->data < output->data)
		output = c;
	return (output);
}

void	move_a_to_b(t_stack *best_node, t_stack **a, t_stack **b)
{
	if (best_node == *a)
		pb(a, b, 'o');
	else if (best_node == (*a)->llink)
	{
		swap(a, 'a');
		pb(a, b, 'o');
	}
	else if (best_node == (*a)->rlink)
	{
		reverse_rotate(a, 'a');
		pb(a, b, 'o');
	}
	else if (best_node == (*b)->rlink && *b != (*b)->rlink)
		reverse_rotate(b, 'b');
	else
		return ;
}

t_stack	*find_next_build(t_stack *a, t_stack *b)
{
	t_stack	*best_node;

	best_node = b;
	if (a->data > b->data)
		best_node = a;
	if (a->llink->data > b->data)
	{
		if (best_node == b || a->llink->data < best_node->data)
			best_node = a->llink;
	}
	if (a->rlink->data > b->data)
	{
		if (best_node == b || a->rlink-> data < best_node->data)
			best_node = a->rlink;
	}
	if (b->rlink->data > b->data)
	{
		if (best_node == b || b->rlink-> data < best_node->data)
			best_node = b->rlink;
	}
	return (best_node);
}

void	send_small_seed(t_stack **a, t_stack **b, int contain_b_bot)
{
	t_stack	*most_small;

	if (*a == 0)
		return ;
	if (contain_b_bot == 0)
		most_small = find_smallest_data_3(*a, (*a)->llink, (*a)->rlink);
	else
		most_small = find_smallest_data_4(*a, (*a)->llink,
				(*a)->rlink, (*b)->rlink);
	if (most_small == *a)
		pb(a, b, 'o');
	else if (most_small == (*a)->llink)
	{
		swap(a, 'a');
		pb(a, b, 'o');
	}
	else if (most_small == (*a)->rlink)
	{
		reverse_rotate(a, 'a');
		pb(a, b, 'o');
	}
	else if (most_small == (*b)->rlink && *b != (*b)->rlink)
		reverse_rotate(b, 'b');
}
