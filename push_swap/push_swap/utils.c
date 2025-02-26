/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:40:27 by sihong            #+#    #+#             */
/*   Updated: 2023/11/26 19:40:29 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **top)
{
	if (top == 0 || *top == 0)
		return ;
	while (*top)
		pop(top);
}

void	init_stack(t_stack **top, int argc, char **argv, int check_zero)
{
	int	i;
	int	end;

	if (check_zero == 0)
		end = 0;
	else
		end = -1;
	i = argc - 1;
	while (i > end)
	{
		if (push(top, ft_atoi(argv[i])) == 0)
		{
			free_stack(top);
			exit(1);
		}
		i--;
	}
}

void	show_error_terminate(int is_buffer, char **buffer)
{
	if (is_buffer == 1)
		free_buffer(buffer);
	write(2, "Error\n", 6);
	exit(1);
}

int	check_int_range(int i, int *j, int is_minus, char **argv)
{
	unsigned long long	total;

	total = 0;
	while (argv[i][*j])
	{
		if (argv[i][*j] < '0' || argv[i][*j] > '9')
			return (0);
		else
			total = total * 10 + (argv[i][*j] - '0');
		if (is_minus)
		{
			if (total > 2147483648)
				return (0);
		}
		else
		{
			if (total > 2147483647)
				return (0);
		}
		(*j)++;
	}
	return (1);
}

void	test_error(int argc, char **argv, int check_zero)
{
	int	i;
	int	j;
	int	is_minus;
	int	func_returned;

	i = 0;
	if (check_zero == 0)
		i = 1;
	while (i < argc)
	{
		j = 0;
		is_minus = 0;
		if (argv[i][j] == '-')
		{
			check_minus(i, j, argv, check_zero);
			is_minus = 1;
			j++;
		}
		if (check_int_range(i, &j, is_minus, argv) == 0)
			show_error_terminate(check_zero, argv);
		i++;
	}
	func_returned = check_dup(argc, argv, check_zero);
	if (func_returned == -1)
		show_error_terminate(check_zero, argv);
}
