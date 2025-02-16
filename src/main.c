/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:36:35 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/17 01:39:43 by mzhivoto         ###   ########.fr       */
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

	int i = 0;
	printf("size of stack a %d\n", stack_a->size);
	if (stack_a->size == 3)
	{
		sort_three(stack_a);
	}
	while(i < stack_a->size)
	{
		printf("%d\n", stack_a->arr[i]);
		i++;
	}
	free(stack_a);
	free(stack_b);
	return 0;
}
