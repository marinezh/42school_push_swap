/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:36:35 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/20 14:57:12 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// typedef struct s_stack {
// 	int *arr;
// 	int size;
// } t_stack;

int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = (t_stack *)calloc(1, sizeof(t_stack));
	stack_b = (t_stack *)calloc(1, sizeof(t_stack));

	stack_a->arr = parse_input(ac, av, &stack_a->size);

	// Allocate array for stack_b (same size as stack_a, max needed)
	stack_b->arr = (int *)calloc(stack_a->size, sizeof(int));
	stack_b->size = 0;  // Stack B starts empty

	
	// printf("size of stack a %d\n", stack_a->size);
	if (stack_a->size == 2)
	{
		sort_two(stack_a);
	}
	else if (stack_a->size == 3)
	{
		sort_three(stack_a);
	}
	else if (stack_a->size == 4 || stack_a->size == 5)
	{
		sort_four_five(stack_a, stack_b);
	}
	else if (stack_a->size > 5)
	{
		chunk_sort(stack_a);
	}

	int i = 0;
	while(i < stack_a->size)
	{
		printf("%d\n", stack_a->arr[i]);
		i++;
	}
	//int median = get_median(stack_a);
    
    
	free(stack_a->arr);
	free(stack_b->arr);
	free(stack_a);
	free(stack_b);
	return 0;
}
