/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:46:48 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/23 18:20:28 by mzhivoto         ###   ########.fr       */
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

//**Push elements in chunks to Stack B**
// void push_chunks(t_stack *stack_a, t_stack *stack_b, int chunk_size)
// {
// 	int i = 0;
// 	int median = get_median(stack_a);
	
// 	printf("median check %d\n", median);
 
// 	while (i < chunk_size && stack_a->size > 3)
// 	{
// 		if (stack_a->arr[0] <= median) // Push smaller elements to B
// 		{
// 			pb(stack_a, stack_b);
// 			i++;
// 		}
// 		else
// 		{
// 			ra(stack_a); // Rotate to find next chunk element
// 		}
// 	}
// 	printf("stack_a: ");
//     for (int k = 0; k < stack_a->size; k++)
//     printf("%d\n ", stack_a->arr[k]);

//     printf("stack_b: ");
//     for (int j = 0; j < stack_b->size; j++)
//     printf("%d\n ", stack_b->arr[j]);
// }


void push_chunks(t_stack *stack_a, t_stack *stack_b, int chunk_size)
{
    int i = 0;
    int median = get_median(stack_a); // Find median for chunk division
    printf("\n--- Pushing Chunk (size: %d, median: %d) ---\n", chunk_size, median);
    printf("Chunk Elements (moving to B): ");

    while (i < chunk_size && stack_a->size > 3)
    {
        printf("\nStep %d: Checking %d (Top of A)\n", i + 1, stack_a->arr[0]);

        if (stack_a->arr[0] <= median) // Push smaller elements to B
        {
            printf("  -> Pushing %d to B (pb)\n", stack_a->arr[0]);
            printf("  [Chunk] %d ", stack_a->arr[0]); // Print chunk contents
            pb(stack_a, stack_b);
        }
        else
        {
            printf("  -> Rotating A (ra)\n");
            ra(stack_a);
        }
        i++;

        // Print current stacks after each step
        printf("\n  Stack A: ");
        for (int j = 0; j < stack_a->size; j++)
            printf("%d ", stack_a->arr[j]);
        printf("\n");

        printf("  Stack B: ");
        for (int j = 0; j < stack_b->size; j++)
            printf("%d ", stack_b->arr[j]);
        printf("\n");
    }
    printf("\n--- Chunk Complete! ---\n");
}



void push_back_to_a(t_stack *a, t_stack *b)
{
	while (b->size > 0)
	{
		int max_idx = find_max_index(b);
		printf("[Find Max] Index: %d | Value: %d\n", max_idx, b->arr[max_idx]);
		// Rotate B until the max element is on top
		if (max_idx > b->size / 2)
		{
			while (max_idx < b->size)
			{
				 printf("[Step] Reverse Rotate B (rrb)\n");
				rrb(b);
				max_idx++;
			}
		}
		else
		{
			while (max_idx > 0)
			{
				printf("[Step] Rotate B (rb)\n");
				rb(b);
				max_idx--;
			}
		}
		printf("[Step] Pushing %d from B to A\n", b->arr[0]);
        pa(a, b);

        printf("[Step] Stack A Now: ");
        print_stack(a);
        printf("[Step] Stack B Now: ");
        print_stack(b);
	}
}

// ✅ **Main sorting function (6-100 elements)**
// void chunk_sort(t_stack *stack_a)
// {

// 	t_stack b;
   
// 	b.arr = malloc(stack_a->size * sizeof(int));
// 	b.size = 0;
// 	if (!b.arr)
// 	{
// 		printf("Memory allocation failed!\n");
// 		exit(EXIT_FAILURE);
// 	}

// 	//int chunk_size = stack_a->size / 5 + 3;
// 	int chunk_size = (stack_a->size / 5 > 3) ? stack_a->size / 5 : 3;
// 	// Push elements in chunks to Stack B
// 	// while (stack_a->size > 3)
// 	// {
// 	// 	push_chunks(stack_a, &b, chunk_size);
// 	// }
// 	push_chunks(stack_a, &b, chunk_size);
// 	sort_three(stack_a);

// 	push_back_to_a(stack_a, &b);

// 	free(b.arr);
// }
void chunk_sort(t_stack *stack_a)
{
    t_stack b;
    b.arr = malloc(stack_a->size * sizeof(int));
    b.size = 0;

    if (!b.arr)
    {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    int chunk_size = stack_a->size / 5 + 3; // Calculate chunk size

    printf("\n=== CHUNK SORT START ===\n");
    printf("!!!Chunk Size: %d\n", chunk_size);
    printf("Initial Stack A: ");
    for (int j = 0; j < stack_a->size; j++)
        printf("%d ", stack_a->arr[j]);
    printf("\n");

    int chunk_count = 1;
    while (stack_a->size > 3)
    {
        printf("\n>>> Processing Chunk %d <<<\n", chunk_count++);
        push_chunks(stack_a, &b, chunk_size);
    }

    printf("\nSorting last 3 elements in A...\n");
    sort_three(stack_a);

    printf("\n=== Pushing Chunks Back to A ===\n");
    push_back_to_a(stack_a, &b);

    printf("\n=== FINAL SORTED STACK A ===\n");
    for (int j = 0; j < stack_a->size; j++)
        printf("%d ", stack_a->arr[j]);
    printf("\n");

    free(b.arr);
}
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
int main()
{
    int arrA[] = {8, 3, 6, 7, 4, 2, 1, 5, 9}; // Unsorted array
    t_stack stackA = {arrA, 9};

    chunk_sort(&stackA); // Sort the array

    printf("Sorted Stack A: ");
    for (int i = 0; i < stackA.size; i++)
        printf("%d ", stackA.arr[i]);
    printf("\n");

    return 0;
}