/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:43:21 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/15 16:19:33 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void rra(int *a, int sizeA)
{
	int i;
	int temp;

	if (sizeA < 2)
		return;
	temp = a[sizeA - 1];
	i = sizeA - 1;
	while( i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = temp;
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

void rrr(int *a, int *b,int sizeA, int sizeB)
{
	if (sizeA < 2 && sizeB < 2)
		return;
	rra(a, sizeA);
	rrb(b, sizeB);
	printf("rrr\n");
}
