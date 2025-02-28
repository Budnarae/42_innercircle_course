/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:39:43 by sihong            #+#    #+#             */
/*   Updated: 2023/11/24 18:39:46 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_first_triangle(t_stack **a, t_stack **b)
{
	t_stack	*best_node;
	int		can_stack_at_top;
	int		can_stack_at_bot;

	send_small_seed(a, b, 0);
	can_stack_at_top = 1;
	can_stack_at_bot = 1;
	while (*a != 0 && (can_stack_at_top == 1 || can_stack_at_bot == 1))
	{
		make_first_triangle_2(&can_stack_at_top, &can_stack_at_bot, a, b);
		if (*a == 0)
			return ;
		best_node = find_best_node_descend((*b)->rlink,
				*a, (*a)->llink, (*a)->rlink);
		if (best_node == (*b)->rlink)
			can_stack_at_bot = 0;
		else
		{
			move_a_to_b(best_node, a, b);
			rotate(b, 'b');
			if (*a == 0)
				return ;
		}
	}
}

void	make_rest_triangles(t_stack **a,
		t_stack **b, int *triangle, int stack_height)
{
	t_stack	*best_node;
	int		send_to_b;
	int		use_bot;

	send_to_b = 0;
	while (*a != 0)
	{
		send_small_seed(a, b, 1);
		*triangle += 1;
		if (*a == 0)
			return ;
		while (1)
		{
			if (send_to_b < stack_height / 3)
				make_rest_triangles_2(&best_node, &send_to_b, a, b);
			else if (send_to_b == stack_height / 3)
				make_rest_triangles_3(&use_bot, &send_to_b, stack_height, b);
			else
				make_rest_triangles_4(use_bot, &best_node, a, b);
			if (check_triangle_number(best_node, triangle, a, b) == 0)
				break ;
		}
	}
	while ((*b)->rlink->data > (*b)->data)
		reverse_rotate(b, 'b');
}

int	make_initial_structure(t_stack **a, t_stack**b, int stack_height)
{
	int	triangle;

	make_first_triangle(a, b);
	triangle = 1;
	if (*a == 0)
		return (triangle);
	make_rest_triangles(a, b, &triangle, stack_height);
	return (triangle);
}

void	merge_triangle(int triangle, t_stack **a, t_stack **b)
{
	int	send_count;
	int	i;

	define_count(triangle, a, &send_count);
	i = 0;
	if (*a == 0)
		b_to_a_ctl(&i, send_count, a, b);
	else if (*b == 0)
	{
		while (i < send_count)
			move_triangle_b_to_a(a, b, &i);
		if (triangle - send_count == 1)
		{
			while (*b != 0)
				merge_to_a(a, b);
		}
		else
		{
			while (*a != 0)
				merge_to_b(a, b);
		}
	}
	if (send_count != 1 && !(triangle / 3 <= 1 && *b == 0))
		merge_triangle(send_count, a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc <= 1)
		return (0);
	a = 0;
	b = 0;
	if (argc == 2 && check_space(argv[1]) == 1)
	{
		if (when_get_big_data(&a, &b, argv[1]) == -1)
			return (-1);
	}
	else
	{
		test_error(argc, argv, 0);
		init_stack(&a, argc, argv, 0);
		if (check_alignment(&a) == 0)
			sort_stack(&a, &b, argc - 1);
	}
	free_stack(&a);
}
