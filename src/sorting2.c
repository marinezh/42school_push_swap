/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:42:55 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/13 14:54:55 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void sa(int *a) {
	int temp = a[0];
	a[0] = a[1];
	a[1] = temp;
	printf("sa\n");
}

void ra(int *a) {
	int temp = a[0];
	a[0] = a[1];
	a[1] = a[2];
	a[2] = temp;
	printf("ra\n");
}

void rra(int *a) {
	int temp = a[2];
	a[2] = a[1];
	a[1] = a[0];
	a[0] = temp;
	printf("rra\n");
}

void pb(int *a, int *b, int *sizeA, int *sizeB)
{ 
	printf("pb\n");
	b[*sizeB] = a[0];
	(*sizeB)++;
	(*sizeA)--;
	for (int i = 0; i < *sizeA; i++)
		a[i] = a[i+1];
}

void pa(int *a, int *b, int *sizeA, int *sizeB)
{ 
	printf("pa\n");
	for (int i = *sizeA; i > 0; i--) a[i] = a[i-1]; 
	a[0] = b[*sizeB - 1];
	(*sizeA)++;
	(*sizeB)--;
}


void sort_three(int *a)
{
	if (a[0] > a[1] && a[1] > a[2]) 
	{  // 3 2 1
		sa(a);
		rra(a);
	} else if (a[0] > a[2] && a[2] > a[1]) 
	{ // 3 1 2
		ra(a);
	} 
	else if (a[1] > a[0] && a[0] > a[2]) 
	{ // 2 3 1
		rra(a);
	} 
	else if (a[1] > a[2] && a[2] > a[0]) 
	{ // 2 1 3
		sa(a);
	} 
	else if (a[2] > a[0] && a[0] > a[1]) 
	{ // 1 3 2
		rra(a);
	}
}


void sort_five(int *a)
{
	int b[2], sizeA = 5, sizeB = 0;

	pb(a, b, &sizeA, &sizeB);
	pb(a, b, &sizeA, &sizeB);
	sort_three(a);
	pa(a, b, &sizeA, &sizeB);
	pa(a, b, &sizeA, &sizeB);
}


