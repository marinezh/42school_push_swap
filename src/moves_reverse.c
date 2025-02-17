/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:43:21 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/17 18:10:33 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void rra(t_stack *stack_a)
{
	int i;
	int temp;
	int sizeA;
	
	sizeA = stack_a->size;
	if (sizeA < 2)
		return;
	temp = stack_a->arr[sizeA - 1];
	i = sizeA - 1;
	while( i > 0)
	{
		stack_a->arr[i] = stack_a->arr[i - 1];
		i--;
	}
	stack_a->arr[0] = temp;
	printf("rra\n");
}
void rrb(t_stack *stack_b)
{
	int i;
	int temp;
	int sizeB;

	sizeB = stack_b->size;
	if (sizeB < 2)
		return;
	temp = stack_b->arr[sizeB - 1];
	i = sizeB - 1;
	while( i > 0)
	{
		stack_b->arr[i] = stack_b->arr[i - 1];
		i--;
	}
	stack_b->arr[0] = temp;
	printf("rrb\n");
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size < 2 && stack_b->size < 2)
		return;
	rra(stack_a);
	rrb(stack_b);
	printf("rrr\n");
}
