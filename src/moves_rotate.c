/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:22:58 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/17 01:36:01 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:12:47 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/15 15:21:51 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ra(t_stack *stack_a)
{
	int i;
	int temp;
	int sizeA = stack_a->size;

	if (sizeA < 2)
		return; 
	i = 0;
	temp = stack_a->arr[0];
	while(i < sizeA - 1)
	{
		stack_a->arr[i] = stack_a->arr[i + 1];
		i++;
	}
	stack_a->arr[sizeA - 1] = temp;
	printf("ra\n");
}
void rb(int *b, int sizeB)
{
	int i;
	int temp;

	if (sizeB < 2)
		return;
	i = 0;
	temp = b[0];
	while(i < sizeB - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[sizeB - 1] = temp;
	printf("rb\n");
}

// void rr(int *a, int *b, int sizeA, int sizeB)
// {
// 	ra(a);
// 	rb(b, sizeB);
// 	printf("rr\n");
// }



