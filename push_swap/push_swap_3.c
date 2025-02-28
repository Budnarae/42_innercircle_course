/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:43:01 by sihong            #+#    #+#             */
/*   Updated: 2023/12/25 14:43:03 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_best_node_ascend(t_stack *target, t_stack *a,
		t_stack *b, t_stack *c)
{
	t_stack	*best_node;

	best_node = target;
	if (a -> data > target -> data)
		best_node = a;
	if (b -> data > target -> data)
	{
		if (best_node == target || b -> data < best_node -> data)
			best_node = b;
	}
	if (c -> data > target -> data)
	{
		if (best_node == target || c -> data < best_node -> data)
			best_node = c;
	}
	return (best_node);
}

t_stack	*find_best_node_descend(t_stack *target, t_stack *a,
		t_stack *b, t_stack *c)
{
	t_stack	*best_node;

	best_node = target;
	if (a -> data < target -> data)
		best_node = a;
	if (b -> data < target -> data)
	{
		if (best_node == target || b -> data > best_node -> data)
			best_node = b;
	}
	if (c -> data < target -> data)
	{
		if (best_node == target || c -> data > best_node -> data)
			best_node = c;
	}
	return (best_node);
}

int	check_triangles_at_b_bot(int stack_height, t_stack **b)
{
	t_stack	*top;
	t_stack	*bot;
	int		i;
	int		triangles;

	i = 0;
	triangles = 1;
	bot = (*b)->rlink;
	top = bot->rlink;
	while (i < stack_height / 3)
	{
		if (bot->data > top->data)
			triangles += 1;
		bot = top;
		top = top->rlink;
		i++;
	}
	if (triangles < stack_height / 100)
		return (0);
	else
		return (1);
}

void	sort_stack(t_stack **a, t_stack **b, int stack_height)
{
	if (stack_height < 6)
	{
		if (stack_height == 2)
			swap(a, 'a');
		else if (stack_height == 3)
			case_3(a);
		else if (stack_height == 4)
			case_4(a, b);
		else if (stack_height == 5)
			case_5(a, b);
	}
	else
		merge_triangle(make_initial_structure(a, b, stack_height), a, b);
}
