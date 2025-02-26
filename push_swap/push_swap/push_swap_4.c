/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:16:43 by sihong            #+#    #+#             */
/*   Updated: 2023/12/27 13:16:45 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_first_triangle_2(int *can_stack_at_top,
		int *can_stack_at_bot, t_stack **a, t_stack **b)
{
	t_stack	*best_node;

	*can_stack_at_top = 1;
	*can_stack_at_bot = 1;
	best_node = find_best_node_ascend(*b, *a, (*a)->llink, (*a)->rlink);
	if (best_node == *b)
		*can_stack_at_top = 0;
	else
		move_a_to_b(best_node, a, b);
}

void	make_rest_triangles_2(t_stack **best_node, int *send_to_b,
		t_stack **a, t_stack **b)
{
	*best_node = find_best_node_ascend(*b,
			*a, (*a)->llink, (*a)->rlink);
	*send_to_b += 1;
}

void	make_rest_triangles_3(int *use_bot, int *send_to_b,
		int stack_height, t_stack **b)
{
	*use_bot = check_triangles_at_b_bot(stack_height, b);
	*send_to_b += 1;
}

void	make_rest_triangles_4(int use_bot, t_stack **best_node,
		t_stack **a, t_stack **b)
{
	if (use_bot)
		*best_node = find_next_build(*a, *b);
	else
		*best_node = find_best_node_ascend(*b,
				*a, (*a)->llink, (*a)->rlink);
}

int	check_triangle_number(t_stack *best_node, int *triangle,
		t_stack **a, t_stack **b)
{
	int	before_move;
	int	after_move;

	before_move = 0;
	after_move = 0;
	if (best_node == (*b))
		return (0);
	if ((*b)->rlink->data > (*b)->rlink->rlink->data)
		before_move = 1;
	move_a_to_b(best_node, a, b);
	if ((*b)->rlink->data < (*b)->rlink->rlink->data)
		after_move = 1;
	if (before_move && after_move)
		*triangle -= 1;
	if (*a == 0)
		return (0);
	return (1);
}
