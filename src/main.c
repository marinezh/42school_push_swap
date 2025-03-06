/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:36:35 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/07 01:25:44 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"






int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;

    // Allocate stack_a and check for failure
    stack_a = (t_stack *)calloc(1, sizeof(t_stack));
    if (!stack_a)
    {
        ft_putstr_fd("Error\n", 2);
        exit(1);
    }

    stack_a->arr = parse_input(ac, av, &stack_a->size);

    // Allocate stack_b after we know stack_a->size
    stack_b = (t_stack *)calloc(1, sizeof(t_stack));
    if (!stack_b)
    {
        free(stack_a->arr);
        free(stack_a);
        ft_putstr_fd("Error\n", 2);
        exit(1);
    }

    // Allocate stack_b->arr safely
    if (stack_a->size > 0)
        stack_b->arr = (int *)calloc(stack_a->size, sizeof(int));
    else
        stack_b->arr = NULL;

    stack_b->size = 0;  // Stack B starts empty

    // If already sorted, free everything and exit
    if (is_sorted(stack_a))
    {
        free(stack_a->arr);
        free(stack_a);
        free(stack_b->arr);
        free(stack_b);
        return 0;
    }

    // Sorting logic
    if (stack_a->size == 1)  
        ft_putstr_fd("Error\n", 2);
    else if (stack_a->size == 2)
        sort_two(stack_a);
    else if (stack_a->size == 3)
        sort_three(stack_a);
    else if (stack_a->size == 4 || stack_a->size == 5)
        sort_four_five(stack_a, stack_b);
    else if (stack_a->size < 500)
        chunk_sort_100(stack_a, stack_b);
    else if (stack_a->size == 500)
        chunk_sort_500(stack_a, stack_b);
    else
        chunk_sort_500(stack_a, stack_b);


	// print_stack_a(stack_a);
	// if(is_sorted(stack_a) == 1)
	// 	printf("YES");
	// else 
	// 	printf("NO");

    free(stack_a->arr);
    free(stack_a);
    free(stack_b->arr);
    free(stack_b);

    return 0;
}

	// int i = 0;
	// printf("Final sorted A : ");
	// while(i < stack_a->size)
	// {
	// 	printf("%d ", stack_a->arr[i]);
	// 	i++;
	// }
	// printf("\n");
	// //int median = get_median(stack_a);
    
	// if(is_sorted(stack_a) == 1)
	// 	printf("YES");
	// else 
	// 	printf("NO");