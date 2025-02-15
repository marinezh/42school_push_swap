/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:46:48 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/15 19:38:51 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// typedef struct s_stack {
//     int *arr;
//     int size;
// } t_stack;

// Push the smallest chunk of elements to stack B
void push_chunks(t_stack *a, t_stack *b, int chunk_size)
{
    int i = 0;
    int median = get_median(a->arr, a->size);

    while (i < chunk_size && a->size > 3)
    {
        if (a->arr[0] <= median) // Push smaller elements to B
            pb(a, b);
        else
            ra(a->arr, a->size); // Rotate to find next chunk element
        i++;
    }
}

// Sort Stack B and push back to Stack A
void push_back_to_a(t_stack *a, t_stack *b)
{
    while (b->size > 0)
    {
        int max_idx = find_max_indx(b->arr, b->size);

        // Rotate B until the max element is on top
        if (max_idx > b->size / 2)
        {
            while (max_idx++ < b->size)
                rrb(b->arr, b->size);
        }
        else
        {
            while (max_idx-- > 0)
                rb(b->arr, b->size);
        }
        pa(a, b);
    }
}

// Main sorting function (6-100 elements)
void chunk_sort(t_stack *a)
{
    t_stack b;
    b.arr = malloc(a->size * sizeof(int));
    b.size = 0;

    int chunk_size = a->size / 5 + 3; // Dynamically adjust chunk size

    // Push elements in chunks to Stack B
    while (a->size > 3)
    {
        push_chunks(a, &b, chunk_size);
    }

    // Sort remaining 3 numbers in Stack A
    sort_three(a->arr, a->size);

    // Push elements back from B to A in correct order
    push_back_to_a(a, &b);

    free(b.arr);
}
