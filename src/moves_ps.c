/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:12:47 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/17 17:52:10 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sa(t_stack *stack_a)
{
	int temp;

	if (stack_a->size < 2)
		return;
	temp = stack_a->arr[0];
	stack_a->arr[0] = stack_a->arr[1];
	stack_a->arr[1] = temp;
	printf("sa\n");
}
void sb(t_stack *stack_b)
{
	sa(stack_b);
	printf("sb\n");
}
void ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	printf("ss\n");
}

void pa(t_stack *stack_a, t_stack *stack_b)
{ 
	int i;
	if (stack_b->size == 0)
		return;  // No element to push
	i = stack_a->size;
	while (i > 0)
	{
		stack_a->arr[i] = stack_a->arr[i-1];
		i--;
	}
	stack_a->arr[0] = stack_b->arr[stack_b->size - 1];
	(stack_a->size)++;
	(stack_b->size)--;
	printf("pa\n");
}
void pb(t_stack *stack_a, t_stack *stack_b)
{ 
	int i;

	if (stack_a->size == 0)
		return; 
	
	stack_b->arr[stack_b->size] = stack_a->arr[0];
	(stack_b->size)++;
	(stack_a->size)--;
	i = 0;
	while (i < stack_a->size)
	{
		stack_a->arr[i] = stack_a->arr[i+1];
		i++;
	}
	printf("pb\n");
}


