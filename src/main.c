/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:36:35 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/06 00:26:15 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"






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
	if (is_sorted(stack_a))
		return 0;
	if (!stack_a)
		ft_putstr_fd("Error\n", 2);
	else if (stack_a->size == 1)	
		ft_putstr_fd("Error\n", 2);
	else if (stack_a->size == 2)
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
	else if (stack_a->size <= 100)
	{
		chunk_sort_100(stack_a, stack_b);
	}
	else if (stack_a->size <= 500)
	{
		chunk_sort_500(stack_a, stack_b);
	}
	else if (stack_a->size > 500)
	{
		//chunk_sort(stack_a, stack_b);
		chunk_sort_500(stack_a, stack_b);
	}

    
	free(stack_a->arr);
	free(stack_b->arr);
	free(stack_a);
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