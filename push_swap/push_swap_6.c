/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:48:24 by sihong            #+#    #+#             */
/*   Updated: 2023/12/27 14:48:26 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_to_a_ctl(int *i, int send_count, t_stack **a, t_stack **b)
{
	while (*i < send_count)
		move_triangle_a_to_b(a, b, i);
	while (*b != 0)
		merge_to_a(a, b);
}

int	when_get_big_data(t_stack **a, t_stack **b, char *argv_1)
{
	char	**buffer;
	int		buf_len;

	buffer = ft_split(argv_1, ' ');
	if (buffer == 0)
		return (-1);
	buf_len = find_buf_len(buffer);
	if (buf_len == 0)
	{
		free_buffer(buffer);
		return (-1);
	}
	test_error(buf_len, buffer, 1);
	init_stack(a, buf_len, buffer, 1);
	free_buffer(buffer);
	if (check_alignment(a) == 0)
		sort_stack(a, b, buf_len);
	return (0);
}
