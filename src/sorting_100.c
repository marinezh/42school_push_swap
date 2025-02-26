/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:38:25 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/26 18:48:59 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"



void first_move(t_stack *stack_a, t_stack *stack_b) 
{
	int median = get_median(stack_a);
	int count = stack_a->size;

	// printf("*** MEDIAN *** is: %d\n", median);
	// print_stack_a(stack_a);
	// print_stack_b(stack_b);

		while (count--)
		{
			if (stack_a->size == 3 && is_sorted(stack_a))
				break;
			if (stack_a->arr[0] < median)
			{
				pb(stack_a, stack_b);
				// print_stack_a(stack_a);
				// print_stack_b(stack_b);
			}
			else 
			{ 
				ra(stack_a); 
				// print_stack_a(stack_a);
				// print_stack_b(stack_b);
			}
		}
}

// void first_move(t_stack *stack_a, t_stack *stack_b) 
// {
// 	int median = get_median(stack_a);
// 	printf("*** MEDIAN *** is: %d\n", median);
	
// 	int initial_size = stack_a->size; // Store original size before starting
// 	int moves = 0; // Track number of operations
// 	print_stack_a(stack_a);
// 	print_stack_b(stack_b);
// 	while (stack_a->size > 3 && moves < initial_size) 
// 	{
// 		if (stack_a->size == 3 && is_sorted(stack_a))
// 			break;
			
// 		if (stack_a->arr[0] < median)
// 		{
// 			pb(stack_a, stack_b); // Push to stack_b if less than median
// 			print_stack_a(stack_a);
// 			print_stack_b(stack_b);
// 		}
// 		else 
// 		{ 
// 			ra(stack_a); // Rotate stack_a if greater or equal
// 			print_stack_a(stack_a);
// 			print_stack_b(stack_b);
// 		}
// 		moves++; // Ensure we don't loop infinitely
// 	}
// }


void sort_stack_b(t_stack *stack_a, t_stack *stack_b)
{
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

void chunk_sort(t_stack *stack_a, t_stack *stack_b)
{
	// First move: push elements smaller than the median to stack_b
	while(stack_a->size > 3)
	{
		first_move(stack_a, stack_b);
	}
	if(!is_sorted(stack_a))
		sort_three(stack_a);

	sort_stack_b(stack_a, stack_b);
	
}


// void sort_stack_b(t_stack *stack_a, t_stack *stack_b)
// {
//     // Sort stack_b in descending order
//      while (stack_b->size > 0)
//     {
//         int max_idx = find_max_index(stack_b);

//         // Optimize rotation: decide whether to rotate up (rb) or down (rrb)
//         if (max_idx <= stack_b->size / 2) {
//             while (max_idx-- > 0) {
//                 rb(stack_b);
//             }
//         } else {
//             max_idx = stack_b->size - max_idx;
//             while (max_idx-- > 0) {
//                 rrb(stack_b);
//             }
//         }
//         // Push the max element to stack_a
//         pa(stack_a, stack_b);
//     }
// }
