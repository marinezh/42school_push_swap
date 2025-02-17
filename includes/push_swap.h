/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:20:43 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/17 15:22:06 by mzhivoto         ###   ########.fr       */
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
// void	sort_three(int *numbers);
// void	sort_five(int *numbers);
//void sort_five(int *a, int size);
//void sort_four_five(int *a, int size);
// void sort_three(int *a, int size);
void sort_three(t_stack *stack_a);
void sort_two(t_stack *stack_a);
//void sort_two(int *a, int size);
//void sa(int *a);
void sa(t_stack *stack_a);
void sb(t_stack *stack_b);
// void sb(int *b);
// void ra(int *a, int sizeA);
void ra(t_stack *stack_a);
void rb(int *b, int sizeB);
void rr(int *a, int *b, int sizeA, int sizeB);
void rra(t_stack *stack_a);
// void rra(int *a, int sizeA);
void rrb(int *b, int sizeB);
void rrr(int *a, int *b,int sizeA, int sizeB);
//void pb(int *a, int *b, int *sizeA, int *sizeB);
// void pa(int *a, int *b, int *sizeA, int *sizeB);
void pa(t_stack *stack_a, t_stack *stack_b);
void pb(t_stack *stack_a, t_stack *stack_b);
// void pa_big(t_stack *a, t_stack *b);
// void pb_big(t_stack *a, t_stack *b);
// int find_max(int *arr, int size);
// int find_min(int *arr, int size);
//int find_min_indx(int *arr, int size);
int find_min_indx(stack_t *stack_a);
int find_max_indx(int *arr, int size);
//int is_sorted(int *arr, int size);
int is_sorted(t_stack *stack_a);
void move_min_to_top(t_stack *stack_a);
int get_median(int *arr, int size);
void push_chunks(t_stack *a, t_stack *b, int chunk_size);
void push_back_to_a(t_stack *a, t_stack *b);
void chunk_sort(t_stack *a);



#endif
