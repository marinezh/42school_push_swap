/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:38:25 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/24 15:39:27 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"



void first_move(t_stack *stack_a, t_stack *stack_b) 
{
	int median = get_median(stack_a);
	printf("MEDIAN is: %d\n", median);
	int count = stack_a->size;
    int rotated = 0; 

	while (count > 0) {
		if (stack_a->arr[0] < median)
		{
			pb(stack_a, stack_b); // Push to stack_b if less than median
		}
        else 
		{
			ra(stack_a); // Rotate stack_a if greater or equal
            rotated++;
		}
		count--;
	}
    // Reverse rotate stack_a back to the original position to avoid
    // unnecessary rotations
    while (rotated-- > 0) {
        rra(stack_a);
    }
	// print_stack_a(stack_a);
	// print_stack_b(stack_b);
}

void sort_stack_b(t_stack *stack_a, t_stack *stack_b)
{
    // Sort stack_b in descending order
     while (stack_b->size > 0)
    {
        int max_idx = find_max_index(stack_b);

        // Optimize rotation: decide whether to rotate up (rb) or down (rrb)
        if (max_idx <= stack_b->size / 2) {
            while (max_idx-- > 0) {
                rb(stack_b);
            }
        } else {
            max_idx = stack_b->size - max_idx;
            while (max_idx-- > 0) {
                rrb(stack_b);
            }
        }
        // Push the max element to stack_a
        pa(stack_a, stack_b);
    }
}



void chunk_sort(t_stack *stack_a, t_stack *stack_b) {
	// First move: push elements smaller than the median to stack_b
	while(stack_a->size > 3)
	{
		printf("Before first_move, stack_a: ");
        print_stack_a(stack_a);
        printf("Before first_move, stack_b: ");
        print_stack_b(stack_b);

        first_move(stack_a, stack_b);
       
        // Check sizes after each move
        printf("After first_move, stack_a size: %d, stack_b size: %d\n", stack_a->size, stack_b->size);
        printf("After first_move, stack_a: ");
        print_stack_a(stack_a);
        printf("After first_move, stack_b: ");
        print_stack_b(stack_b);
	}
	sort_three(stack_a);
    sort_stack_b(stack_a, stack_b);
    //printf("After sorting stack_b and pushing back to stack_a: ");
}



// void sort_stack_b(t_stack *stack_a, t_stack *stack_b)
// {
//     int count = stack_b->size;
// 	while (count--)
// 	{
// 		//int i = 0;
// 		int max_idx = find_max_index(stack_b); // Find the largest element in stack_b
// 		printf("XXX max_ind %d and the digit is %d\n", max_idx, stack_b->arr[max_idx]);
// 		// Determine the best way to bring max to the top
// 		move_to_top(stack_b, max_idx);
// 		print_stack_b(stack_b);
// 		// Push max from stack_b to stack_a
// 		pa(stack_a, stack_b);
// 		printf("Pushed from stack_b to stack_a: ");
// 		print_stack_b(stack_a);
// 	}
// }