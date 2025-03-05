/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_500.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:36:08 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/05 01:31:23 by mzhivoto         ###   ########.fr       */
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
// int cost_to_top(t_stack *stack, int index)
// {
// 	int cost = 0;
// 	int i = 0;
// 	if (index <= stack->size / 2)
// 	{
// 		while (index > 0)
// 		{
// 			cost++;
// 			index--;
// 		}
// 	}
// 	else
// 	{
// 		while (index < stack->size)
// 		{
// 			cost++;
// 			index++;
// 		}
// 	}
// 	printf("Cost to bring digit %d with index %d to top: %d\n", stack->arr[i], index, cost);
// 	return cost;
// }

// int push_to_b_cost(t_stack *stack_a, int limit) {
//     int i = 0;
// 	int j = 0;
//     int min_cost = stack_a->size;
//     int current_cost;
//     int best_cost_index = -1;

//     while (i < stack_a->size) {
//         if (stack_a->arr[i] < limit) {
//             current_cost = cost_to_top(stack_a, i);
//             if (current_cost < min_cost) {
//                 min_cost = current_cost;
//                 best_cost_index = i;
//             }
//         }
//         i++;
//     }
	
//     printf("Best index to push digit %d is: %d\n",stack_a->arr[j], best_cost_index);
//     return best_cost_index;
// }
int cost_to_top(t_stack *stack, int index) {
	int cost;
	//int i = 0;

	if (index <= stack->size / 2) {
		cost = index;  // Forward rotation (ra)
		//printf("Cost to bring digit %d with index %d to bottom (ra): %d\n", stack->arr[i], index, cost);
	} else {
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
	int best_cost_index = 0;
	
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
// Function to find the best position in stack_a for a given number from stack_b
// int find_best_insert_pos(t_stack *stack_a, int num)
// {
//     int i = 0;
//     int best_index = 0;
//     int best_diff = __INT_MAX__;
    
//     while (i < stack_a->size) {
//         int diff = stack_a->arr[i] - num;
//         if (diff > 0 && diff < best_diff) {
//             best_diff = diff;
//             best_index = i;
//         }
//         i++;
//     }
// 	// int j = 0;
//     // printf("BEST index to push digit %d is: %d\n",stack_a->arr[j], best_index);
//     return best_index;
// }
void push_all_to_a(t_stack *stack_a, t_stack *stack_b)
{
	
	int count = stack_b->size;
	while (count--)
	{
		// int i = 0;
		// int best_index = push_to_b_cost(stack_b, INT_MAX);
		// 	if (best_index == -1) break;
		// printf("BEST INDEX of %d is %d\n", stack_b->arr[i], best_index);
		move_to_top(stack_b, find_max_index(stack_b));
		//printf("push to a\n");
		pa(stack_a, stack_b);
		
		
	}
	
}


void first_move_500(t_stack *stack_a, t_stack *stack_b)
{
	int size = stack_a->size;
	int chunks = 0;
	int chunk_size;
	// int *chunk_limits;
	int i = 0;
	int *sorted = sorted_array(stack_a); //sorted copy of stack_a
	//print_array(sorted, size);
	
	
	if(size <= 10)
		chunks = 2;
	else if (size <= 20)
		chunks = 3;
	else if (size <= 100)
		chunks = 6;
	else if (size <=500)
		chunks = 15;
	chunk_size = size / chunks;
	// printf("chunks number %d\n", chunks);
	// printf("chunks size %d\n", chunk_size);
	// printf("stack a size %d\n", size);

	int limit ;
	
	while (i < chunks)
	{
		// chunk_limits[i] = sorted[(i + 1) * chunk_size - 1];
		limit = sorted[(i + 1) * chunk_size];
		//printf("-*********Chunk %d limit**********: %d\n", i + 1, limit);
		int temp_chunk_size = chunk_size;
		//printf("limits %d\n", limit);
		while(temp_chunk_size > 0)
		{
			//printf("temp chunk size %d\n", temp_chunk_size);
			//printf("find_best_insert_pos %d\n", find_best_insert_pos(stack_a, limit));
			move_to_top(stack_a, push_to_b_cost(stack_a, limit));
			// print_stack_a(stack_a);
			// print_stack_b(stack_b);
			pb(stack_a, stack_b);
			// print_stack_a(stack_a);
			// print_stack_b(stack_b);

			//printf("temp chunk size %d\n", temp_chunk_size);
			temp_chunk_size--;
		}
		
		i++;
	}
	
	
 	free(sorted);
}

void chunk_sort_500(t_stack *stack_a, t_stack *stack_b) 
{
	first_move_500(stack_a, stack_b);
	//sort_stack_b(stack_a, stack_b);
	push_all_to_a(stack_a, stack_b);
	print_stack_a(stack_a);
	print_stack_b(stack_b);
}


