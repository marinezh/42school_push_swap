/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:12:47 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/07 17:43:26 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	int	temp;

	if (stack_a->size < 2)
		return ;
	temp = stack_a->arr[0];
	stack_a->arr[0] = stack_a->arr[1];
	stack_a->arr[1] = temp;
	ft_putstr("sa\n");
}

void	sb(t_stack *stack_b)
{
	sa(stack_b);
	ft_putstr("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_putstr("ss\n");
}

// void	pa(t_stack *stack_a, t_stack *stack_b)
// {
// 	int	i;

// 	if (stack_b->size == 0)
// 		return ;
// 	i = stack_a->size;
// 	while (i > 0)
// 	{
// 		stack_a->arr[i] = stack_a->arr[i - 1];
// 		i--;
// 	}
// 	stack_a->arr[0] = stack_b->arr[stack_b->size - 1];
// 	(stack_a->size)++;
// 	(stack_b->size)--;
// 	printf("pa\n");
// }
void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	// Check if stack_b is empty
	if (stack_b->size == 0)
		return ;
	// Shift stack_a elements UP to make space for new element at index 0
	i = stack_a->size;
	while (i > 0)
	{
		stack_a->arr[i] = stack_a->arr[i - 1];
		i--;
	}
	// Move the top element from stack_b to the top of stack_a
	stack_a->arr[0] = stack_b->arr[0];
	(stack_a->size)++;
	// Shift stack_b elements LEFT after removing the top element
	i = 0;
	while (i < stack_b->size - 1)
	{
		stack_b->arr[i] = stack_b->arr[i + 1];
		i++;
	}
	(stack_b->size)--;
	// Print operation
	ft_putstr("pa\n");
}

// void	pb(t_stack *stack_a, t_stack *stack_b)
// {
// 	int	i;

// 	if (stack_a->size == 0)
// 		return ;
// 	stack_b->arr[stack_b->size] = stack_a->arr[0];
// 	(stack_b->size)++;
// 	(stack_a->size)--;
// 	i = 0;
// 	while (i < stack_a->size)
// 	{
// 		stack_a->arr[i] = stack_a->arr[i + 1];
// 		i++;
// 	}
// 	printf("pb\n");
// }

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	// Check if stack_a is empty
	if (stack_a->size == 0)
		return ;
	// Shift stack_b elements UP to make space for new element at index 0
	i = stack_b->size;
	while (i > 0)
	{
		stack_b->arr[i] = stack_b->arr[i - 1];
		i--;
	}
	// Move the top element from stack_a to the top of stack_b
	stack_b->arr[0] = stack_a->arr[0];
	(stack_b->size)++;
	// Shift stack_a elements LEFT after removing the top element
	i = 0;
	while (i < stack_a->size - 1)
	{
		stack_a->arr[i] = stack_a->arr[i + 1];
		i++;
	}
	(stack_a->size)--;
	// Print operation
	ft_putstr("pb\n");
}
