/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:29:24 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/09 17:39:27 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	find_max_index(t_stack *stack_a)
{
	int	i;
	int	max_indx;

	i = 0;
	max_indx = 0;
	if (stack_a->size == 0)
		return (0);
	while (i < stack_a->size)
	{
		if (stack_a->arr[i] > stack_a->arr[max_indx])
		{
			max_indx = i;
		}
		i++;
	}
	return (max_indx);
}

int	find_min_index(t_stack *stack_a)
{
	int	i;
	int	min_indx;

	if (stack_a->size == 0)
		return (0);
	min_indx = 0;
	i = 1;
	while (i < stack_a->size)
	{
		if (stack_a->arr[i] < stack_a->arr[min_indx])
		{
			min_indx = i;
		}
		i++;
	}
	return (min_indx);
}
int	is_sorted(t_stack *stack_a)
{
	int	i;
	int	*arr;
	int	size;

	arr = stack_a->arr;
	size = stack_a->size;
	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	move_to_top_a(t_stack *stack, int index)
{
	if (index <= stack->size / 2)
	{
		while (index > 0)
		{
			ra(stack);
			index--;
		}
	}
	else
	{
		while (index < stack->size)
		{
			rra(stack);
			index++;
		}
	}
}
void	move_to_top_b(t_stack *stack, int index)
{
	if (index <= stack->size / 2)
	{
		while (index > 0)
		{
			rb(stack);
			index--;
		}
	}
	else
	{
		while (index < stack->size)
		{
			rrb(stack);
			index++;
		}
	}
}
// void print_stack_a(t_stack *stack)
// {
// 	ft_printf("[Stack A] ");
// 	for (int i = 0; i < stack->size; i++)
// 		ft_printf("%d ", stack->arr[i]);
// 	printf("\n");
// }
// void print_stack_b(t_stack *stack)
// {
// 	ft_printf("[Stack B] ");
// 	for (int i = 0; i < stack->size; i++)
// 		ft_printf("%d ", stack->arr[i]);
// 	ft_printf("\n");
// }
// void print_array(int *arr, int size)
// {
// 	ft_printf("[array] ");
// 	for (int i = 0; i < size; i++)
// 		ft_printf("%d ", arr[i]);
// 	ft_printf("\n");
// }