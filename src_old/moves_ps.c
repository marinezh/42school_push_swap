/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:12:47 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/16 16:10:24 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sa(int *a)
{
	int temp;

	// if (sizeA < 2)
	// 	return;
	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
	printf("sa\n");
}

void sb(int *b)
{
	int temp;

	// if (sizeB < 2)
	// 	return;
	temp = b[0];
	b[0] = b[1];
	b[1] = temp;
	printf("sb\n");
}
void ss(int *a, int *b)
{
	sa(a);
	sb(b);
	printf("ss\n");
}

void pb(int *a, int *b, int *sizeA, int *sizeB)
{ 
	int i;

	b[*sizeB] = a[0];
	(*sizeB)++;
	(*sizeA)--;
	i = 0;
	while (i < *sizeA)
	{
		a[i] = a[i+1];
		i++;
	}
	printf("pb\n");
}

void pa(int *a, int *b, int *sizeA, int *sizeB)
{ 
	int i;

	i = *sizeA;
	while (i > 0)
	{
		a[i] = a[i-1];
		i--;
	}
	a[0] = b[*sizeB - 1];
	(*sizeA)++;
	(*sizeB)--;
	printf("pa\n");
}

void pb_big(t_stack *a, t_stack *b)
{
    if (a->size == 0)
        return;
    // Shift elements in B to make space
    for (int i = b->size; i > 0; i--)
        b->arr[i] = b->arr[i - 1];

    // Move the top of A to B
    b->arr[0] = a->arr[0];
    b->size++;
    a->size--;

    // Shift elements in A upwards
    for (int i = 0; i < a->size; i++)
        a->arr[i] = a->arr[i + 1];

    printf("pb\n");
}
void pa_big(t_stack *a, t_stack *b)
{
    if (b->size == 0)
        return;
    // Shift elements in A to make space
    for (int i = a->size; i > 0; i--)
        a->arr[i] = a->arr[i - 1];

    // Move the top of B to A
    a->arr[0] = b->arr[0];
    a->size++;
    b->size--;

    // Shift elements in B upwards
    for (int i = 0; i < b->size; i++)
        b->arr[i] = b->arr[i + 1];

    printf("pa\n");
}

