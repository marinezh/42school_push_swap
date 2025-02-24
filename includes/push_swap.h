/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:20:43 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/24 14:55:22 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
#include <limits.h>
#include <ctype.h>

typedef struct s_node
{
	int value;
	struct s_node *next;
} t_node;

// typedef struct s_node
// {
// 	int				num;
// 	int				index;
// 	int				flag;
// 	struct s_node	*next;
// 	struct s_node	*prev;
// } t_node;

// typedef struct s_all
// {
// 	t_node	*stack_a;
// 	t_node	*stack_b;
// 	int		mib_a;
// 	int 	med;
// 	int 	len_a;
// 	int 	len_b;
// }

typedef struct s_stack {
	int *arr;
	int size;
} t_stack;

void	putstr(char *str);
int	is_valid_number(char *str);
int	safe_atoi(char *str, int *num);
int	has_duplicates(int *arr, int size);
int	*parse_input(int ac, char **av, int *size);
void sort_two(t_stack *stack_a);
void sort_three(t_stack *stack_a);
void sort_four_five(t_stack *stack_a, t_stack *stack_b);
void sort_large(t_stack *stack_a, t_stack *stack_b);
void sa(t_stack *stack_a);
void sb(t_stack *stack_b);
void ss(t_stack *stack_a, t_stack *stack_b);
void pa(t_stack *stack_a, t_stack *stack_b);
void pb(t_stack *stack_a, t_stack *stack_b);
void ra(t_stack *stack_a);
void rb(t_stack *stack_b);
void rr(t_stack *stack_a, t_stack *stack_b);
void rra(t_stack *stack_a);
void rrb(t_stack *stack_b);
void rrr(t_stack *stack_a, t_stack *stack_b);
int find_min_index(t_stack *stack_a);
int find_max_index(t_stack *stack_a);
int is_sorted(t_stack *stack_a);
//void move_min_to_top(t_stack *stack_a);
void move_to_top(t_stack *stack, int index);
int get_median(t_stack *stack_a);
// int get_median(int *arr, int size);
void first_move(t_stack *stack_a, t_stack *stack_b);
void push_chunks(t_stack *a, t_stack *b, int chunk_size);
void push_back_to_a(t_stack *a, t_stack *b);

void push_back_to_a(t_stack *stack_a, t_stack *stack_b);
void push_chunks_to_b(t_stack *stack_a, t_stack *stack_b, int chunk_size);
int *copy_and_sort(t_stack *stack);
void push_chunks(t_stack *stack_a, t_stack *stack_b, int chunk_size);
void push_back_to_a(t_stack *stack_a, t_stack *stack_b);

void push_chunks(t_stack *stack_a, t_stack *stack_b, int chunk_size);
void push_back_to_a(t_stack *a, t_stack *b);
void sort_stack_b_to_a(t_stack *stack_a, t_stack *stack_b);
//void chunk_sort(t_stack *stack_a);
void chunk_sort(t_stack *stack_a, t_stack *stack_b);
int *sorted_array(t_stack *stack);

int find_index(t_stack *stack, int num);
void find_min_max(t_stack *stack, int start, int end, int *min, int *max);
//void chunk_sort(t_stack *a, t_stack *b, int chunk_size);
//void print_stack(t_stack *stack, char *name);
//void print_stack(t_stack *stack);
int is_sorted_descending(t_stack *stack_b);
void print_stack_a(t_stack *stack);
void print_stack_b(t_stack *stack);

#endif
