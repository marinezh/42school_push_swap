/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:36:35 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/07 21:32:55 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
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
	else if (stack_a->size >= 500)
		chunk_sort_500(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!stack_a)
		return (1);
	stack_a->arr = parse_input(ac, av, &stack_a->size);
	if (!stack_a->arr)
		return (free(stack_a), 1);
	// catch all possible leaks from erors from parsing here
	stack_b = (t_stack *)ft_calloc(1, sizeof(t_stack));
	// Allocate stack_b after we know stack_a->size
	if (!stack_b)
	{
		free(stack_a->arr);
		free(stack_a);
		return (1);
	}
	// Allocate stack_b->arr safely
	if (stack_a->size > 0)
		stack_b->arr = (int *)ft_calloc(stack_a->size, sizeof(int));
	else
		stack_b->arr = NULL;
	stack_b->size = 0; // Stack B starts empty
	if (is_sorted(stack_a))
	{
		free(stack_a->arr);
		free(stack_a);
		free(stack_b->arr);
		free(stack_b);
		return (0);
	}
	push_swap(stack_a, stack_b);
	free(stack_a->arr);
	free(stack_a);
	free(stack_b->arr);
	free(stack_b);
	return (0);
}

// print_stack_a(stack_a);
// if(is_sorted(stack_a) == 1)
// 	printf("YES");
// else
// 	printf("NO");
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