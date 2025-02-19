/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:46:48 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/18 23:40:14 by mzhivoto         ###   ########.fr       */
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
// void first_move(t_stack *stack_a, t_stack *stack_b)
// {
//     int median;
//     int i = 0;
//     int count = stack_a->size;

//     median = get_median(stack_a);
    
//     while( count > 0)
//     {
//          printf("element we are checking %d\n", stack_a->arr[i]);
//         if(stack_a->arr[i] < median)
//         {
//             printf("Pushing %d to stack_b\n", stack_a->arr[i]);
//             pb(stack_a, stack_b);
           
            
//             printf("stack_a: ");
//             for (int k = 0; k < stack_a->size; k++)
//             printf("%d ", stack_a->arr[k]);
//             printf("\n");

//             printf("stack_b: ");
//             for (int j = 0; j < stack_b->size; j++)
//             printf("%d ", stack_b->arr[j]);
//             printf("\n");
//         }
//         else 
//         {
//             printf("Rotating %d to the bottom of stack_a\n", stack_a->arr[i]);
//             ra(stack_a);
           

//             printf("stack_a: ");
//             for (int k = 0; k < stack_a->size; k++)
//             printf("%d ", stack_a->arr[k]);
//             printf("\n");

//             printf("stack_b: ");
//             for (int j = 0; j < stack_b->size; j++)
//             printf("%d ", stack_b->arr[j]);
//             printf("\n");
//         } 
//         count--;
//     }
// }
// void first_move(t_stack *stack_a, t_stack *stack_b) 
// {
//     int median = get_median(stack_a);
//     int count = stack_a->size; 

//     while (count > 0) {
//         if (stack_a->arr[0] < median)
//         {
//             pb(stack_a, stack_b); // Push to stack_b if less than median
//         } else 
//         {
//             ra(stack_a); // Rotate stack_a if greater or equal
//         }
//         count--;
//     }
// }
int *copy_and_sort(t_stack *stack)
{
    int *sorted = malloc(stack->size * sizeof(int));
    if (!sorted)
        return NULL;
    
    for (int i = 0; i < stack->size; i++)
        sorted[i] = stack->arr[i];
    
    for (int i = 0; i < stack->size - 1; i++)
    {
        for (int j = 0; j < stack->size - i - 1; j++)
        {
            if (sorted[j] > sorted[j + 1])
            {
                int temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }
    
    return sorted;
}

void push_chunks_to_b(t_stack *stack_a, t_stack *stack_b, int chunk_size)
{
    int chunk_start = 0;
    int chunk_end;
    int *sorted = copy_and_sort(stack_a);
    
    while (chunk_start < stack_a->size)
    {
        chunk_end = chunk_start + chunk_size;
        if (chunk_end > stack_a->size)
            chunk_end = stack_a->size;
        
        int pushed = 0;
        int count = stack_a->size;
        while (count--)
        {
            if (stack_a->arr[0] >= sorted[chunk_start] && stack_a->arr[0] < sorted[chunk_end])
            {
                pb(stack_a, stack_b);
                pushed = 1;
            }
            else
            {
                ra(stack_a);
            }
        }
        if (!pushed)
            break;
        chunk_start = chunk_end;
    }
    free(sorted);
}


void push_back_to_a(t_stack *stack_a, t_stack *stack_b)
{
    while (stack_b->size > 0)
    {
        int max_index = find_max_index(stack_b);
        
        while (stack_b->arr[0] != stack_b->arr[max_index])
        {
            if (max_index <= stack_b->size / 2)
                rb(stack_b);
            else
                rrb(stack_b);
        }
        pa(stack_a, stack_b);
    }
}

void sort_large(t_stack *stack_a, t_stack *stack_b)
{
    int chunk_size = (stack_a->size > 100) ? (stack_a->size / 10) : (stack_a->size / 5);
    push_chunks_to_b(stack_a, stack_b, chunk_size);
    push_back_to_a(stack_a, stack_b);
}
