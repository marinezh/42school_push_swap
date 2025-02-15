/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:22:58 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/15 16:05:32 by mzhivoto         ###   ########.fr       */
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

void ra(int *a, int sizeA)
{
	int i;
	int temp;

	if (sizeA < 2)
		return; 
	i = 0;
	temp = a[0];
	while(i < sizeA - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[sizeA - 1] = temp;
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

void rr(int *a, int *b, int sizeA, int sizeB)
{
	ra(a, sizeA);
	rb(b, sizeB);
	printf("rr\n");
}



