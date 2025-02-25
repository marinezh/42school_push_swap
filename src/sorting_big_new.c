/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:36:08 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/25 19:19:44 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void first_move(t_stack *stack_a, t_stack *stack_b) 
{
	int size = stack_a->size;
	(void)stack_b;
	int *sorted = sorted_array(stack_a); // Get a sorted copy of stack_a
	print_array(sorted, size);
	// int chunk_size = size / chunks;
	// int i = 0, rotated = 0;
	
	

 	free(sorted);
}
// void sort_stack_b(t_stack *stack_a, t_stack *stack_b)
// {
//     int count = stack_b->size;
// 	while (count--)
// 	{
// 		//int i = 0;
// 		int max_idx = find_max_index(stack_b); // Find the largest element in stack_b
// 		//printf("XXX max_ind %d and the digit is %d\n", max_idx, stack_b->arr[max_idx]);
// 		// Determine the best way to bring max to the top
// 		move_to_top(stack_b, max_idx);
// 		// print_stack_a(stack_a);
// 		// print_stack_b(stack_b);
// 		// Push max from stack_b to stack_a
// 		pa(stack_a, stack_b);
// 		// printf("Pushed from stack_b to stack_a: ");
//         // print_stack_a(stack_a);
// 		// print_stack_b(stack_b);
// 	}
// }

void chunk_sort(t_stack *stack_a, t_stack *stack_b) 
{
	first_move(stack_a, stack_b);
}


