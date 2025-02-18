/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:46:48 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/18 19:22:43 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// typedef struct s_stack {
//     int *arr;
//     int size;
// } t_stack;

// Push the smallest chunk of elements to stack B
// void push_chunks(t_stack *a, t_stack *b, int chunk_size)
// {
//     int i = 0;
//     int median = get_median(a->arr, a->size);

//     while (i < chunk_size && a->size > 3)
//     {
//         if (a->arr[0] <= median) // Push smaller elements to B
//         {
//             pb_big(a, b);
//             i++;
//         }
//         else
//             ra(a->arr, a->size); // Rotate to find next chunk element
//     }
// }

// Sort Stack B and push back to Stack A
// void push_back_to_a(t_stack *a, t_stack *b)
// {
//     while (b->size > 0)
//     {
//         int max_idx = find_max_indx(b->arr, b->size);

//         // Rotate B until the max element is on top
//         if (max_idx > b->size / 2)
//         {
//             while (max_idx++ < b->size)
//             {
//                 rrb(b->arr, b->size);
//                 max_idx++;
//             }
//         }
//         else
//         {
//             while (max_idx-- > 0)
//             {
//                  rb(b->arr, b->size);
//                  max_idx--;
//             }
//         }
//         pa_big(a, b);
//     }
// }

// Main sorting function (6-100 elements)
// void chunk_sort(t_stack *a)
// {
//     t_stack b;
//     b.size = 0;
//     b.arr = malloc(a->size * sizeof(int));
//     if(!b.arr)
//     {
//         printf("Memory allocation failed!\n");
//         exit(EXIT_FAILURE);
//     }
        

//     int chunk_size = a->size / 5 + 3; // Dynamically adjust chunk size

//     // Push elements in chunks to Stack B
//     while (a->size > 3)
//     {
//         push_chunks(a, &b, chunk_size);
//     }

//     // Sort remaining 3 numbers in Stack A
//     sort_three(a->arr, 3);

//     // Push elements back from B to A in correct order
//     push_back_to_a(a, &b);

//     free(b.arr);
// }
void first_move(t_stack *stack_a, t_stack *stack_b)
{
    int median;
    int i = 0;
    int count = stack_a->size;

    median = get_median(stack_a);
    
    while( count > 0)
    {
         printf("element we are checking %d\n", stack_a->arr[i]);
        if(stack_a->arr[i] < median)
        {
            printf("Pushing %d to stack_b\n", stack_a->arr[i]);
            pb(stack_a, stack_b);
           
            
            printf("stack_a: ");
            for (int k = 0; k < stack_a->size; k++)
            printf("%d ", stack_a->arr[k]);
            printf("\n");

            printf("stack_b: ");
            for (int j = 0; j < stack_b->size; j++)
            printf("%d ", stack_b->arr[j]);
            printf("\n");
        }
        else 
        {
            printf("Rotating %d to the bottom of stack_a\n", stack_a->arr[i]);
            ra(stack_a);
           

            printf("stack_a: ");
            for (int k = 0; k < stack_a->size; k++)
            printf("%d ", stack_a->arr[k]);
            printf("\n");

            printf("stack_b: ");
            for (int j = 0; j < stack_b->size; j++)
            printf("%d ", stack_b->arr[j]);
            printf("\n");
        } 
        count--;
    }
}
void first_move(t_stack *stack_a, t_stack *stack_b) 
{
    int median = get_median(stack_a);
    int count = stack_a->size; 

    while (count > 0) {
        if (stack_a->arr[0] < median)
        {
            pb(stack_a, stack_b); // Push to stack_b if less than median
        } else 
        {
            ra(stack_a); // Rotate stack_a if greater or equal
        }
        count--;
    }
}
