/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:36:08 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/08 19:13:11 by mzhivoto         ###   ########.fr       */
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

// void	first_move(t_stack *stack_a, t_stack *stack_b)
// {
// 	t_chunk	chunk;
// 	int		i;
// 	int		limit;
// 	int		*sorted;

// 	chunk.chunks = chunk_count(stack_a->size);
// 	i = 0;
// 	sorted = sorted_array(stack_a->arr, stack_a->size);
// 	if (!sorted)
// 		return ;
// 	chunk.chunk_size = stack_a->size / chunk.chunks;
// 	while (i < chunk.chunks)
// 	{

// 		limit = sorted[(i + 1) * chunk.chunk_size];
// 		printf("limit %d\n", limit);
// 		chunk.temp_chunk_size = chunk.chunk_size;
// 		while (chunk.temp_chunk_size > 0)
// 		{
// 			move_to_top_a(stack_a, push_to_b_cost(stack_a, limit));
// 			pb(stack_a, stack_b);
// 			chunk.temp_chunk_size--;
// 		}
// 		i++;
// 	}
// 	free(sorted);
// }

void	compute_chunk_limits(int *sorted, int *limits, int chunk_size,
		int chunks, int stack_size)
{
	int	i;
	int	index;

	i = 0;
	//printf("stack_size %d\n", stack_size);
	while (i < chunks)
	{
		index = (i + 1) * chunk_size;
		if (index >= stack_size)
			index = stack_size - 1;
		limits[i] = sorted[index];
		
		//printf("limits %d\n", limits[i]);
		i++;
	}
}

void	first_move(t_stack *stack_a, t_stack *stack_b)
{
	t_chunk	chunk;
	int		i;
	int		*sorted;
	int		*limits;
	int		limit;

	chunk.chunks = chunk_count(stack_a->size);
	sorted = sorted_array(stack_a->arr, stack_a->size);
	if (!sorted)
		return ;
	chunk.chunk_size = stack_a->size / chunk.chunks;
	limits = malloc(sizeof(int) * chunk.chunks);
	if (!limits)
	{
		free(sorted);
		return ;
	}
	// Precompute chunk limits
	compute_chunk_limits(sorted, limits, chunk.chunk_size, chunk.chunks,
		stack_a->size);
	for (i = 0; i < chunk.chunks; i++)
	{
		limit = limits[i];
		chunk.temp_chunk_size = chunk.chunk_size;
		while (chunk.temp_chunk_size > 0)
		{
			move_to_top_a(stack_a, push_to_b_cost(stack_a, limit));
			pb(stack_a, stack_b);
			chunk.temp_chunk_size--;
		}
	}
	free(sorted);
	free(limits);
}

void	chunk_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	min_index;

	first_move(stack_a, stack_b);
	while (stack_a->size > 3)
	{
		min_index = find_min_index(stack_a);
		move_to_top_a(stack_a, min_index);
		pb(stack_a, stack_b);
	}
	if (!is_sorted(stack_a))
	{
		if (stack_a->size == 2)
			sa(stack_a);
		else if (stack_a->size == 3)
			sort_three(stack_a);
	}
	push_all_to_a(stack_a, stack_b);
}
