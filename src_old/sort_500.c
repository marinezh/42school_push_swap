// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   sort_500.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/02/27 18:27:50 by mzhivoto          #+#    #+#             */
// /*   Updated: 2025/02/27 18:47:49 by mzhivoto         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>

// #include "../includes/push_swap.h"

// // Function to calculate cost to bring an index to the top
// int cost_to_top_550(t_stack *stack, int index) {
//     int cost;
    
//     if (index <= stack->size / 2) {
//         cost = index;  // Forward rotation (ra)
//     } else {
//         cost = stack->size - index;  // Reverse rotation (rra)
//     }
    
//     printf("Cost to bring index %d to top: %d\n", index, cost);
//     return cost;
// }

// // Function to find the best position in stack_a for a given number from stack_b
// int find_best_insert_pos_550(t_stack *stack_a, int num)
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
    
//     return best_index;
// }

// // Function to find the best index to push back to A with minimal cost
// int push_to_a_cost_550(t_stack *stack_b, t_stack *stack_a)
// {
//     int i = 0;
//     int min_cost = __INT_MAX__;
//     int best_cost_index = -1;
    
//     while (i < stack_b->size) {
//         int target_pos = find_best_insert_pos(stack_a, stack_b->arr[i]);
//         int cost_b = cost_to_top_550(stack_b, i);
//         int cost_a = cost_to_top_550(stack_a, target_pos);
//         int total_cost = cost_b + cost_a;
        
//         if (total_cost < min_cost) {
//             min_cost = total_cost;
//             best_cost_index = i;
//         }
//         i++;
//     }
    
//     printf("Best index to push back to A: %d with cost %d\n", best_cost_index, min_cost);
//     return best_cost_index;
// }

// // Function to find the best index to push based on cost
// int push_to_b_cost_550(t_stack *stack_a)
// {
//     int i = 0;
//     int min_cost = stack_a->size;
//     int current_cost;
//     int best_cost_index = -1;

//     while (i < stack_a->size) {
//         current_cost = cost_to_top_550(stack_a, i);
//         if (current_cost < min_cost) {
//             min_cost = current_cost;
//             best_cost_index = i;
//         }
//         i++;
//     }
    
//     printf("Best index to push: %d\n", best_cost_index);
//     return best_cost_index;
// }

// // Function to push everything from stack A to stack B with minimum cost
// void push_all_to_b_550(t_stack *stack_a, t_stack *stack_b)
//  {
//     int size = stack_a->size;
//     while (size--)
//     {
//         int best_index = push_to_b_cost_550(stack_a);
//         if (best_index == -1) break;
        
//         move_to_top(stack_a, best_index);
//         pb(stack_a, stack_b);
//     }
// }

// // Function to push everything back to stack A in sorted order using push_to_a_cost
// void push_all_to_a_550(t_stack *stack_a, t_stack *stack_b)
// {
//     int size = stack_b->size;
//     while (size--)
//     {
//         int best_index = push_to_a_cost_550(stack_b, stack_a);
//         if (best_index == -1) break;
        
//         move_to_top(stack_b, best_index);
//         pa(stack_a, stack_b);
//     }
// }

// // Wrapper function to start sorting
// void chunk_sort_500(t_stack *stack_a, t_stack *stack_b) {
//     push_all_to_b_550(stack_a, stack_b);
//     push_all_to_a_550(stack_a, stack_b);
//     print_stack_a(stack_a);
//     print_stack_b(stack_b);
//     printf("check this\n");
// }
