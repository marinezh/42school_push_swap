/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_500.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:36:08 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/09 16:55:50 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int cost_to_top(t_stack *stack, int index)
{
	int cost;
	//int i = 0;

	if (index <= stack->size / 2)
	{
		cost = index;  // Forward rotation (ra)
		//printf("Cost to bring digit %d with index %d to bottom (ra): %d\n", stack->arr[i], index, cost);
	} else
	{
		cost = stack->size - index;  // Reverse rotation (rra)
		//printf("Cost to bring digit %d with index %d to top (rra): %d\n", stack->arr[i], index, cost);
	}
	//printf("Cost to bring digit %d with index %d to top: %d\n", stack->arr[i], index, cost);
	return cost;
}
int push_to_b_cost(t_stack *stack_a, int limit)
{
	int i = 0;
	
	int min_cost = stack_a->size;
	int current_cost = 0;
	int best_cost_index = -1;
	
	while(i < stack_a->size)
	{
		//printf("XXX LIMIT IS XXX %d\n", limit);
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
	//int j = 0;
	//printf("Best index to push digit %d is: %d\n",stack_a->arr[j], best_cost_index);
	return (best_cost_index);
}

void push_all_to_a(t_stack *stack_a, t_stack *stack_b)
{
	
	int count = stack_b->size;
	while (count > 0)
	{
		// int i = 0;
		// int best_index = push_to_b_cost(stack_b, INT_MAX);
		// 	if (best_index == -1) break;
		// printf("BEST INDEX of %d is %d\n", stack_b->arr[i], best_index);
		move_to_top_b(stack_b, find_max_index(stack_b));
		// print_stack_a(stack_a);
		// print_stack_b(stack_b);
		

		// printf("PUSHING BACK TO A\n");
		pa(stack_a, stack_b);
		// printf("PUSHING BACK TO A\n");
		// print_stack_a(stack_a);
		// print_stack_b(stack_b);
	}
}
// int chunk_count(int size)
// {
// 	int chunks = 0;

// 	if(size <= 10)
// 		chunks = 2;
// 	// else if (size <= 11)
// 	// 	chunks = 3;
// 	else if (size <= 50)
// 		chunks = 4;
// 	else if (size <= 100)
// 		chunks = 10;
// 	else if (size < 500)
// 		chunks = 15;

// 	else if (size == 500)
// 		chunks = 20;
// 	else if (size > 500)
// 		chunks = 50;
// 	return chunks;
// }
int chunk_count(int size)
{
	if (size <= 10)
		return 2;
	else if (size <= 50)
		return 4;
	else if (size <= 100)
		return 8;  // Changed from 10
	else if (size < 500)
		return 12; // Changed from 15
	else if (size == 500)
		return 20;
	else
		return 50;
}

void first_move_500(t_stack *stack_a, t_stack *stack_b)
{
	int size = stack_a->size;
	int chunks = chunk_count(size);
	int chunk_size;
	// int *chunk_limits;
	int i = 0;
	// printf("A BEFORE SORTING");
	// print_stack_a(stack_a);
	int *sorted = sorted_array(stack_a->arr, size); //sorted copy of stack_a
	if (!sorted) return;
	// printf("A AFTER SORTING");
	// print_array(sorted, size);

	chunk_size = size / chunks;
	// printf("chunks number %d\n", chunks);
	// printf("chunks size %d\n", chunk_size);
	// printf("stack a size %d\n", size);

	int limit ;
	while (i < chunks)
	{
		// chunk_limits[i] = sorted[(i + 1) * chunk_size - 1];
		limit = sorted[((i + 1) * chunk_size) - 1];
		// printf("-XXXXXXXX*********CHUNK LIMIT %d **********XXXXXXXXX: %d\n", i + 1, limit);
		int temp_chunk_size = chunk_size;
		while(temp_chunk_size > 0)
		{
			//printf("find_best_insert_pos %d\n", find_best_insert_pos(stack_a, limit));
			int push_b_cost = push_to_b_cost(stack_a, limit);
			//int push_b_cost_2 = find_best_insert_pos(stack_a, limit);
			// printf("!!!push to be cost %d, num is %d\n", push_b_cost, stack_a->arr[push_b_cost]);
			// printf("!!!push to be cost_2 %d, num is %d\n", push_b_cost_2, stack_a->arr[push_b_cost]);
			// printf("MOVING TO B");
			
			move_to_top_a(stack_a, push_b_cost);
				// print_stack_a(stack_a);
				// print_stack_b(stack_b);
			pb(stack_a, stack_b);
				// print_stack_a(stack_a);
				// print_stack_b(stack_b);
			// printf("temp chunk size %d\n", temp_chunk_size);
			temp_chunk_size--;
		}
		i++;
	}
 	free(sorted);
}
// void first_move_chunk_sort(t_stack *stack_a, t_stack *stack_b)
// {
// 	int size = stack_a->size;
// 	int chunks = chunk_count(size);
// 	int chunk_size = size / chunks;
// 	int i = 0;
// 	int *sorted = sorted_array(stack_a->arr, size); // Sorted copy of stack_a

// 	if (!sorted)
// 		return;

// 	while (i < chunks)
// 	{
// 		int limit_index = ((i + 1) * chunk_size) - 1;
// 		if (limit_index >= size) 
// 			limit_index = size - 1;
		
// 		int limit = sorted[limit_index];
// 		int temp_chunk_size = chunk_size;

// 		while (temp_chunk_size > 0)
// 		{
// 			int push_b_cost = push_to_b_cost(stack_a, limit);
// 			if (push_b_cost == -1) 
// 				break;

// 			move_to_top_a(stack_a, push_b_cost);
// 			pb(stack_a, stack_b);
// 			temp_chunk_size--;
// 		}
// 		i++;
// 	}
// 	free(sorted);
// }

void chunk_sort_100(t_stack *stack_a, t_stack *stack_b) 
{
	first_move_500(stack_a, stack_b);
	//sort_stack_b(stack_a, stack_b);
	// printf("stack A size check %d\n", stack_a->size);

	while(stack_a->size > 3)
	{
        int min_index = find_min_index(stack_a);
        //printf("Min index to move: %d, Value: %d\n", min_index, stack_a->arr[min_index]);
        move_to_top_a(stack_a, min_index);
        //print_stack_a(stack_a);
        //printf("Pushing %d to B\n", stack_a->arr[0]);
        pb(stack_a, stack_b);
        // print_stack_a(stack_a);
        // print_stack_b(stack_b);	
	}
	
	if(!is_sorted(stack_a))
	{
		if(stack_a->size == 2)
			sa(stack_a);
		else if(stack_a->size == 3)
			sort_three(stack_a);

	}
	push_all_to_a(stack_a, stack_b);
}

void chunk_sort_500(t_stack *stack_a, t_stack *stack_b) 
{
	first_move_500(stack_a, stack_b);
	//sort_stack_b(stack_a, stack_b);
	push_all_to_a(stack_a, stack_b);
	
	// print_stack_a(stack_a);
	// print_stack_b(stack_b);
}
