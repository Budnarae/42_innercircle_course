/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:33:00 by sihong            #+#    #+#             */
/*   Updated: 2023/11/24 18:33:02 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int				data;
	struct s_stack	*rlink;
	struct s_stack	*llink;
}	t_stack;

typedef struct s_node
{
	int				data;
	struct s_node	*right;
	struct s_node	*left;
}	t_node;

//most_basic.c
void	reverse_rotate(t_stack **top, char c);
void	rotate(t_stack **top, char c);
void	swap(t_stack **top, char c);
int		pop(t_stack **top);
int		push(t_stack **top, int data);
//most_basic_2.c
void	case_only_2_data(t_stack **top, char c);
//operations.c
void	ss(t_stack **a, t_stack **b, char c);
void	pa(t_stack **a, t_stack **b, char c);
void	pb(t_stack **a, t_stack **b, char c);
void	rr(t_stack **a, t_stack **b, char c);
void	rrr(t_stack **a, t_stack **b, char c);
//utils.c
void	free_stack(t_stack **top);
void	init_stack(t_stack **top, int argc, char **argv, int check_zero);
void	show_error_terminate(int is_buffer, char **buffer);
int		check_int_range(int i, int *j, int is_minus, char **argv);
void	test_error(int argc, char **argv, int check_zero);
//utils_2.c
int		check_space(char *s);
void	free_buffer(char **buffer);
int		find_buf_len(char **buffer);
int		check_alignment(t_stack **a);
void	check_minus(int i, int j, char **argv, int check_zero);
//push_swap.c
void	make_first_triangle(t_stack **a, t_stack **b);
void	make_rest_triangles(t_stack **a,
			t_stack **b, int *triangle, int stack_height);
int		make_initial_structure(t_stack **a, t_stack**b, int stack_height);
void	merge_triangle(int triangle, t_stack **a, t_stack **b);
//push_swap_2.c
t_stack	*find_smallest_data_4(t_stack *a, t_stack *b, t_stack *c, t_stack *d);
t_stack	*find_smallest_data_3(t_stack *a, t_stack *b, t_stack *c);
void	move_a_to_b(t_stack *best_node, t_stack **a, t_stack **b);
t_stack	*find_next_build(t_stack *a, t_stack *b);
void	send_small_seed(t_stack **a, t_stack **b, int contain_b_bot);
//push_swap_3.c
t_stack	*find_best_node_ascend(t_stack *target, t_stack *a,
			t_stack *b, t_stack *c);
t_stack	*find_best_node_descend(t_stack *target, t_stack *a,
			t_stack *b, t_stack *c);
int		check_triangles_at_b_bot(int stack_height, t_stack **b);
void	sort_stack(t_stack **a, t_stack **b, int stack_height);
//push_swap_4.c
void	make_first_triangle_2(int *can_stack_at_top,
			int *can_stack_at_bot, t_stack **a, t_stack **b);
void	make_rest_triangles_2(t_stack **best_node, int *send_to_b,
			t_stack **a, t_stack **b);
void	make_rest_triangles_3(int *use_bot, int *send_to_b,
			int stack_height, t_stack **b);
void	make_rest_triangles_4(int use_bot, t_stack **best_node,
			t_stack **a, t_stack **b);
int		check_triangle_number(t_stack *best_node, int *triangle,
			t_stack **a, t_stack **b);
//push_swap_5.c
void	define_count(int triangle, t_stack **a, int *send_count);
void	move_triangle_a_to_b(t_stack **a, t_stack **b, int *i);
void	move_triangle_b_to_a(t_stack **a, t_stack **b, int *i);
void	merge_to_a(t_stack **a, t_stack **b);
void	merge_to_b(t_stack **a, t_stack **b);
//push_swap_6.c
void	b_to_a_ctl(int *i, int send_count, t_stack **a, t_stack **b);
int		when_get_big_data(t_stack **a, t_stack **b, char *argv_1);
//hardcase.c
void	case_3(t_stack **a);
void	case_3_2(t_stack **a, t_stack *temp);
void	case_4(t_stack **a, t_stack **b);
void	case_5(t_stack **a, t_stack **b);
//check_dup_utils.c
void	free_tree(t_node *tree);
int		search_tree(t_node **tree, int s);
void	left_case(t_node **tree);
void	right_case(t_node **tree);
int		balance_tree(t_node **tree, int depht);
//check_dup.c
int		check_dup(int arr_len, char **arr, int check_zero);

#endif