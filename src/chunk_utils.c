/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:38:25 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/12 18:53:39 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_to_top(t_stack *stack, int index)
{
	int	cost;

	if (index <= stack->size / 2)
		cost = index;
	else
		cost = stack->size - index;
	return (cost);
}
int	push_to_b_cost(t_stack *stack_a, int limit)
{
	int	i;
	int	min_cost;
	int	current_cost;
	int	best_cost_index;

	i = 0;
	min_cost = stack_a->size;
	//printf("min cost %d\n", min_cost);
	current_cost = 0;
	best_cost_index = 0;
	while (i < stack_a->size)
	{
		if (stack_a->arr[i] < limit)
		{
			current_cost = cost_to_top(stack_a, i);
			printf("Index: %d, Value: %d, Cost: %d\n", i, stack_a->arr[i], current_cost);
			if (current_cost < min_cost)
			{
				min_cost = current_cost;
				best_cost_index = i;
			}
		}
		i++;
	}
	printf("Best index to move: %d (Value: %d, Cost: %d)\n", best_cost_index, stack_a->arr[best_cost_index], min_cost);
	return (best_cost_index);
}

void	push_all_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	count;

	count = stack_b->size;
	while (count--)
	{
		move_to_top_b(stack_b, find_max_index(stack_b));
		//printf("PUSHING BACK TO A");
		// print_stack_a(stack_a);
		// print_stack_b(stack_b);
		pa(stack_a, stack_b);
		// print_stack_a(stack_a);
		// print_stack_b(stack_b);
	}
}

