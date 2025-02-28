/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:20:00 by sihong            #+#    #+#             */
/*   Updated: 2023/12/25 14:20:02 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_space(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

void	free_buffer(char **buffer)
{
	int	i;

	i = 0;
	if (buffer != 0)
	{
		while (buffer[i])
		{
			free(buffer[i]);
			i++;
		}
		free(buffer);
	}
}

int	find_buf_len(char **buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
		i++;
	return (i);
}

int	check_alignment(t_stack **a)
{
	t_stack	*top;
	t_stack	*bot;
	t_stack	*tmp;

	top = *a;
	bot = (*a)->llink;
	tmp = top;
	while (bot != tmp)
	{
		if (top->data > bot->data)
			return (0);
		top = bot;
		bot = bot->llink;
	}
	return (1);
}

void	check_minus(int i, int j, char **argv, int check_zero)
{
	if (argv[i][j + 1] < '0' || argv[i][j + 1] > '9')
		show_error_terminate(check_zero, argv);
}
