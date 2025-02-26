/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   most_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:03:33 by sihong            #+#    #+#             */
/*   Updated: 2023/11/26 19:03:35 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **top, char c)
{
	if (top == 0 || *top == 0 || *top == (*top)->rlink)
		return ;
	*top = (*top)->rlink;
	if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
}

void	rotate(t_stack **top, char c)
{
	if (top == 0 || *top == 0 || *top == (*top)->llink)
		return ;
	*top = (*top)->llink;
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
}

void	swap(t_stack **top, char c)
{
	t_stack	*block_b;
	t_stack	*block_c;
	t_stack	*block_last;

	if (top == 0 || *top == 0 || *top == (*top)->llink)
		return ;
	block_b = (*top)->llink;
	block_c = block_b->llink;
	block_last = (*top)->rlink;
	if (*top == block_c)
	{
		case_only_2_data(top, c);
		return ;
	}
	block_b->rlink = block_last;
	block_last->llink = block_b;
	block_c->rlink = *top;
	block_b->llink = *top;
	(*top)->llink = block_c;
	(*top)->rlink = block_b;
	*top = block_b;
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb\n");
}

int	pop(t_stack **top)
{
	int		output;
	t_stack	*tmp;

	output = (*top)->data;
	(*top)->llink->rlink = (*top)->rlink;
	(*top)->rlink->llink = (*top)->llink;
	if (*top == (*top)->llink)
	{
		free(*top);
		*top = 0;
	}
	else
	{
		tmp = *top;
		*top = (*top)->llink;
		free(tmp);
	}
	return (output);
}

int	push(t_stack **top, int data)
{
	t_stack	*new;

	new = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (new == 0)
		return (0);
	new->data = data;
	if (*top == 0)
	{
		*top = new;
		(*top)->llink = *top;
		(*top)->rlink = *top;
	}
	else
	{
		new->llink = (*top);
		new->rlink = (*top)->rlink;
		(new->rlink)->llink = new;
		(*top)->rlink = new;
		*top = new;
	}
	return (1);
}
