/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:36:08 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/12 19:14:33 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chunk_count(int size)
{
	if (size <= 10)
		return (2);
	else if (size <= 50)
		return (4);
	else if (size <= 100)
		return (8);
	else if (size < 500)
		return (12);
	else if (size == 500)
		return (20);
	else
		return (50);
}
void chanks_pushing_to_b(t_stack *stack_a, t_stack *stack_b, \
						t_chunk *chunk, int limit)
{
	int	best_cost_index;
	
	while (chunk->temp_chunk_size > 0)
	{
		best_cost_index = push_to_b_cost(stack_a, limit);
		move_to_top_a(stack_a, best_cost_index);
		print_stack_a(stack_a);
		print_stack_b(stack_b);
		pb(stack_a, stack_b);
		print_stack_a(stack_a);
		print_stack_b(stack_b);
		chunk->temp_chunk_size--;
	}
}

void	first_move(t_stack *stack_a, t_stack *stack_b)
{
	t_chunk	chunk;
	int	i;
	int	limit;
	int	*sorted;
	int	max;

	max = stack_a->size;
	chunk.chunks = chunk_count(stack_a->size);
	i = 0;
	sorted = sorted_array(stack_a->arr, stack_a->size);
	if (!sorted)
		return ;
	chunk.chunk_size = stack_a->size / chunk.chunks;
	printf("chunk size %d\n", chunk.chunk_size);
	while (i < chunk.chunks)
	{
		if (i == chunk.chunks - 1)
		{
			limit = max + 1;
			printf("XXX limit: %d\n", limit);
			printf("XXX max: %d\n", max);
		}
			
		else
		{
			limit = sorted[(i + 1) * chunk.chunk_size];

			printf("ZZZ limit: %d\n", limit);
			printf("ZZZ limit: %d\n", limit);
			printf("ZZZ max: %d\n", max);
		}
			

		printf("****** LIMITS ****** %d\n", limit);
		chunk.temp_chunk_size = chunk.chunk_size;
		chanks_pushing_to_b(stack_a, stack_b, &chunk, limit);
		i++;
	}
	free(sorted);
}

void	chunk_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	min_index;

	first_move(stack_a, stack_b);
	while (stack_a->size > 0)
	{
		min_index = find_min_index(stack_a);
		move_to_top_a(stack_a, min_index);
		pb(stack_a, stack_b);
	}
	push_all_to_a(stack_a, stack_b);
	printf("PUSH BACK TO A\n");
	print_stack_a(stack_a);
	print_stack_b(stack_b);
}
