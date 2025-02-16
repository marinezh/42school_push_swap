/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:43:21 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/17 01:35:35 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void rra(t_stack *stack_a)
{
	int i;
	int temp;
	int sizeA = stack_a->size;

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
void rrb(int *b, int sizeB)
{
	int i;
	int temp;

	if (sizeB < 2)
		return;
	temp = b[sizeB - 1];
	i = sizeB - 1;
	while( i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = temp;
	printf("rrb\n");
}

// void rrr(int *a, int *b,int sizeA, int sizeB)
// {
// 	if (sizeA < 2 && sizeB < 2)
// 		return;
// 	rra(a);
// 	rrb(b, sizeB);
// 	printf("rrr\n");
// }
