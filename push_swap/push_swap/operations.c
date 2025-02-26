/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:09:45 by sihong            #+#    #+#             */
/*   Updated: 2023/11/26 19:09:46 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **a, t_stack **b, char c)
{
	swap(a, 'x');
	swap(b, 'x');
	if (c == 'o')
		ft_printf("ss\n");
}

void	pa(t_stack **a, t_stack **b, char c)
{
	if (b == 0 || *b == 0)
		return ;
	if (push(a, pop(b)) == 0)
	{
		free_stack(a);
		free_stack(b);
		exit(1);
	}
	if (c == 'o')
		ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b, char c)
{
	if (a == 0 || *a == 0)
		return ;
	if (push(b, pop(a)) == 0)
	{
		free_stack(a);
		free_stack(b);
		exit(1);
	}
	if (c == 'o')
		ft_printf("pb\n");
}

void	rr(t_stack **a, t_stack **b, char c)
{
	rotate(a, 'x');
	rotate(b, 'x');
	if (c == 'o')
		ft_printf("rr\n");
}

void	rrr(t_stack **a, t_stack **b, char c)
{
	reverse_rotate(a, 'x');
	reverse_rotate(b, 'x');
	if (c == 'o')
		ft_printf("rrr");
}
