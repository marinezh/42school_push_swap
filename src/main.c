/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:36:35 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/09 21:19:04 by mzhivoto         ###   ########.fr       */
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
	else if (stack_a->size > 5)
		chunk_sort(stack_a, stack_b);
	// else if (stack_a->size >= 500)
	// 	chunk_sort_500(stack_a, stack_b);
}
int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = (t_stack *)ft_calloc(1, sizeof(t_stack));
	stack_b = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!stack_a || !stack_b)
		return (free_stacks(stack_a, stack_b), ft_putstr_fd("Error\n", 2), 1);
	stack_a->arr = parse_input(ac, av, &stack_a->size);
	if (!stack_a->arr)
		return (free_stacks(stack_a, stack_b), 1);
	if (!stack_a->arr)
		return (free_stacks(stack_a, stack_b), 1);
	if (stack_a->size > 0)
	{
		stack_b->arr = (int *)ft_calloc(stack_a->size, sizeof(int));
		if (!stack_b->arr)
		{
			free_stacks(stack_a, stack_b);
			return (ft_putstr_fd("Error\n", 2), 1);
		}
	}
	if (is_sorted(stack_a))
		return (free_stacks(stack_a, stack_b), 0);
	push_swap(stack_a, stack_b);
	return (free_stacks(stack_a, stack_b), 0);
}
// int	main(int ac, char **av)
// {
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;

// 	stack_a = (t_stack *)ft_calloc(1, sizeof(t_stack));
// 	if (!stack_a)
// 		return (ft_putstr_fd("Error\n", 2), 1);
// 	stack_a->arr = parse_input(ac, av, &stack_a->size);
// 	if (!stack_a->arr)
// 		return (free(stack_a), 1);
// 	stack_b = (t_stack *)ft_calloc(1, sizeof(t_stack));
// 	if (!stack_b)
// 	{
// 		free(stack_a->arr);
// 		return (free(stack_a), ft_putstr_fd("Error\n", 2), 1);
// 	}
// 	if (stack_a->size > 0)
// 		stack_b->arr = (int *)ft_calloc(stack_a->size, sizeof(int));
// 	else
// 		stack_b->arr = NULL;
// 	stack_b->size = 0;
// 	if (is_sorted(stack_a))
// 		return (free_stacks(stack_a, stack_b), 0);

// 	// ft_printf("before sorting A : ");
// 	// print_stack_a(stack_a);	
// 	push_swap(stack_a, stack_b);


// 	// ft_printf("Final sorted A : ");
// 	// print_stack_a(stack_a);
// 	// ft_printf("\n");
	
// 	// if(is_sorted(stack_a) == 1)
// 	// 	printf("YES\n");
// 	// else
// 	// 	printf("NO\n");
// 	free_stacks(stack_a, stack_b);
// 	return (0);
// }
