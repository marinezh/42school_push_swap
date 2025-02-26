/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_500.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:36:08 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/26 19:05:57 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Function to check if there are any elements in stack_a belonging to the current chunk
int has_chunk_element(t_stack *stack_a, int limit)
{
	int i = 0;

	while (i < stack_a->size)
	{
		if (stack_a->arr[i] <= limit)
			return 1;
	}
	return 0;
}
int cost_to_top(t_stack *stack, int index)
{
	int cost = 0;

	if (index <= stack->size / 2)
	{
		while (index > 0)
		{
			cost++;
			index--;
		}
	}
	else
	{
		while (index < stack->size)
		{
			cost++;
			index++;
		}
	}
	return cost;
}
int push_to_b_cost(t_stack *stack_a, int limit)
{
	int i = 0;
	int min_cost = stack_a->size;
	int current_cost = 0;
	int best_cost_index = 0;
	while(i < stack_a->size)
	{
		if(stack_a->arr[i] < limit)
		{
			current_cost = cost_to_top(stack_a, i);
			//printf("current cost %d\n", current_cost);
			if (current_cost < min_cost)
			{
				min_cost = current_cost;
				best_cost_index = i;
			}
		}
		i++;
	}
	return (best_cost_index);
}
void sort_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	int min = find_min_index(stack_b);
	int max = find_max_index(stack_b);

	int min_cost = push_to_b_cost(stack_b, stack_b->arr[min]);
	int max_cost = push_to_b_cost(stack_b, stack_b->arr[max]);
	int count = stack_b->size;
	while (count--)
	{
		int max_idx = find_max_index(stack_b); // Find the largest element in stack_b
		//printf("XXX max_ind %d and the digit is %d\n", max_idx, stack_b->arr[max_idx]);
		// Determine the best way to bring max to the top
		move_to_top(stack_b, max_idx);
		// print_stack_a(stack_a);
		// print_stack_b(stack_b);
		//Push max from stack_b to stack_a
		pa(stack_a, stack_b);
		// printf("Pushed from stack_b to stack_a: ");
		// print_stack_a(stack_a);
		// print_stack_b(stack_b);
	}
}

void first_move_500(t_stack *stack_a, t_stack *stack_b)
{
	int size = stack_a->size;
	int chunks = 0;
	int chunk_size;
	// int *chunk_limits;
	int i, j;
	int *sorted = sorted_array(stack_a); //sorted copy of stack_a
	print_array(sorted, size);
	
	
	if(size <= 100)
		chunks = 8;
	else
		chunks = 15;
	chunk_size = size / chunks;
	printf("chunks number %d\n", chunks);
	printf("chunks size %d\n", chunk_size);
	// printf("stack a size %d\n", size);

	// chunk_limits = malloc(chunks * sizeof(int));
	// if (!chunk_limits)
	// {
	// 	free(sorted);
	// 	return;
	// }

	i = 0;
	j = 0;

	int limit ;
	// printf("limit %d\n", limit);
	while (i < chunks)
	{
		// chunk_limits[i] = sorted[(i + 1) * chunk_size - 1];
		limit = sorted[(i + 1) * chunk_size];
		printf("Chunk %d limit: %d\n", i + 1, limit);
		int temp_chunk_size = chunk_size;
		// printf("limits %d\n", limit);
		while(temp_chunk_size > 0)
		{
			printf("temp chunk size %d\n", temp_chunk_size);
			// j = 0;
			// while(j < stack_a->size)
			// {
				// if(stack_a->arr[j] <= limit)
				// {
					move_to_top(stack_a, push_to_b_cost(stack_a, limit));
					pb(stack_a, stack_b);
				// }
			// 	j++;
			// }
			temp_chunk_size--;
		}
		
		i++;
	}
	// print_stack_a(stack_a);
	// print_stack_b(stack_b);
	sort_stack_b(stack_a, stack_b);
	print_stack_a(stack_a);
	print_stack_b(stack_b);


	
 	free(sorted);
	// free(chunk_limits);
}
// // void sort_stack_b_500(t_stack *stack_a, t_stack *stack_b)
// // {
// //     int count = stack_b->size;
// // 	while (count--)
// // 	{
// // 		//int i = 0;
// // 		int max_idx = find_max_index(stack_b); // Find the largest element in stack_b
// // 		//printf("XXX max_ind %d and the digit is %d\n", max_idx, stack_b->arr[max_idx]);
// // 		// Determine the best way to bring max to the top
// // 		move_to_top(stack_b, max_idx);
// // 		// print_stack_a(stack_a);
// // 		// print_stack_b(stack_b);
// // 		// Push max from stack_b to stack_a
// // 		pa(stack_a, stack_b);
// // 		// printf("Pushed from stack_b to stack_a: ");
// //         // print_stack_a(stack_a);
// // 		// print_stack_b(stack_b);
// // 	}
// // }

void chunk_sort_500(t_stack *stack_a, t_stack *stack_b) 
{
	first_move_500(stack_a, stack_b);
}


