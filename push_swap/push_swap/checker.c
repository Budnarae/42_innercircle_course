/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:23:32 by sihong            #+#    #+#             */
/*   Updated: 2023/11/26 19:24:09 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	execute_operation(char *operation, t_stack **a, t_stack **b)
{
	if (ft_memcmp(operation, "sa\n", 3) == 0)
		swap(a, 'x');
	else if (ft_memcmp(operation, "sb\n", 4) == 0)
		swap(b, 'x');
	else if (ft_memcmp(operation, "ss\n", 4) == 0)
		ss(a, b, 'x');
	else if (ft_memcmp(operation, "pa\n", 4) == 0)
		pa(a, b, 'x');
	else if (ft_memcmp(operation, "pb\n", 4) == 0)
		pb(a, b, 'x');
	else if (ft_memcmp(operation, "ra\n", 4) == 0)
		rotate(a, 'x');
	else if (ft_memcmp(operation, "rb\n", 4) == 0)
		rotate(b, 'x');
	else if (ft_memcmp(operation, "rra\n", 5) == 0)
		reverse_rotate(a, 'x');
	else if (ft_memcmp(operation, "rrb\n", 5) == 0)
		reverse_rotate(b, 'x');
	else if (ft_memcmp(operation, "rrr\n", 5) == 0)
		rrr(a, b, 'x');
	else if (ft_memcmp(operation, "rr\n", 4) == 0)
		rr(a, b, 'x');
	else
		return (0);
	return (1);
}

int	init_checker(t_stack **a, int argc, char **argv)
{
	char	**buffer;
	int		buf_len;

	if (argc == 2 && check_space(argv[1]) == 1)
	{
		buffer = ft_split(argv[1], ' ');
		if (buffer == 0)
			return (0);
		buf_len = find_buf_len(buffer);
		if (buf_len == 0)
		{
			free_buffer(buffer);
			return (0);
		}
		test_error(buf_len, buffer, 1);
		init_stack(a, buf_len, buffer, 1);
		free_buffer(buffer);
	}
	else
	{
		test_error(argc, argv, 0);
		init_stack(a, argc, argv, 0);
	}
	return (1);
}

int	input_command(t_stack **a, t_stack **b)
{
	char	*operation;

	operation = (char *)1;
	while (operation)
	{
		operation = get_next_line(0);
		if (operation == 0)
			break ;
		if (execute_operation(operation, a, b) == 0)
		{
			write(2, "Error\n", 6);
			free_stack(a);
			free_stack(b);
			return (0);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc <= 1)
		return (0);
	a = 0;
	b = 0;
	if (init_checker(&a, argc, argv) == 0)
		return (-1);
	if (input_command(&a, &b) == 0)
		return (-1);
	if (b == 0 && check_alignment(&a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
}
