/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:23:36 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/23 22:23:33 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_stack(t_stack *stack)
{
	printf("[Stack] ");
	for (int i = 0; i < stack->size; i++)
		printf("%d ", stack->arr[i]);
	printf("\n");
}

// void first_move(t_stack *stack_a, t_stack *stack_b) 
// {
// 	int median = get_median(stack_a);
// 	printf("MEDIAN is: %d\n", median);
// 	int count = stack_a->size; 

// 	while (count > 0) {
// 		if (stack_a->arr[0] < median)
// 		{
// 			pb(stack_a, stack_b); // Push to stack_b if less than median
// 		} else 
// 		{
// 			ra(stack_a); // Rotate stack_a if greater or equal
// 		}
// 		count--;
// 	}
// 	print_stack(stack_a);
// 	print_stack(stack_b);
// }
void first_move(t_stack *stack_a, t_stack *stack_b) {
    // Example: If we move the smallest element or based on some condition
    int min_index = find_min_index(stack_a); // Find element to move
    move_to_top(stack_a, min_index); // Move it to the top if needed
    pb(stack_a, stack_b); // Push it to stack_b
}
// void sort_stack_b(t_stack *stack_a, t_stack *stack_b)
// {
//     // Sort stack_b in descending order
//     int i = 0;
//     while (!is_sorted_descending(stack_b))
//     {
		
//         int max_idx = find_max_index(stack_b);
//         printf("XXX max_ind %d and the digit is %d\n", max_idx, stack_b->arr[i]);
//         // Bring the maximum element to the top
//         while (max_idx >= 0)
//         {
//             rb(stack_b); // Rotate stack_b until max element is on top
//             max_idx--;
//         }
		
//         // Push the largest element to stack_a
//         pa(stack_a, stack_b);
//         printf("Pushed from stack_b to stack_a: ");
//         print_stack(stack_a);
//         print_stack(stack_b);
//     }
// }
void sort_stack_b(t_stack *stack_a, t_stack *stack_b) {
	while (stack_b->size > 0)
	{  
		//int i = 0;
		int max_idx = find_max_index(stack_b); // Find the largest element in stack_b
		printf("XXX max_ind %d and the digit is %d\n", max_idx, stack_b->arr[max_idx]);
		// Determine the best way to bring max to the top
		move_to_top(stack_b, max_idx);
		print_stack(stack_b);
		// Push max from stack_b to stack_a
		pa(stack_a, stack_b);
		printf("Pushed from stack_b to stack_a: ");
		print_stack(stack_a);
	}
}



void chunk_sort(t_stack *stack_a, t_stack *stack_b) {
	// First move: push elements smaller than the median to stack_b
	while(stack_a->size >= 1)
	{
		// printf("Before first_move, stack_a: ");
        // print_stack(stack_a);
        // printf("Before first_move, stack_b: ");
        // print_stack(stack_b);

        first_move(stack_a, stack_b);

        // Check sizes after each move
        // printf("After first_move, stack_a size: %d, stack_b size: %d\n", stack_a->size, stack_b->size);
        // printf("After first_move, stack_a: ");
        // print_stack(stack_a);
        // printf("After first_move, stack_b: ");
        // print_stack(stack_b);
	}
}

// Utility function to check if stack_b is sorted in descending order
int is_sorted_descending(t_stack *stack_b) {
	for (int i = 0; i < stack_b->size - 1; i++) {
		if (stack_b->arr[i] < stack_b->arr[i + 1]) {
			return 0; // Not sorted in descending order
		}
	}
	return 1; // Sorted in descending order
}

