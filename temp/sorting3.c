/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:52:07 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/14 16:36:40 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:42:55 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/14 13:57:04 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// void sa(int *a)
// {
// 	int temp = a[0];
// 	a[0] = a[1];
// 	a[1] = temp;
// 	printf("sa\n");
// }

// void ra(int *a, int size)
// {
// 	int i;
// 	int temp;

// 	temp = a[0];
// 	// printf("temp is %d\n", temp);
// 	i = 0;
// 	while(i < size)
// 	{
// 		a[i] = a[i + 1];
// 		i++;
// 	}
// 	a[size - 1] = temp;
// 	printf("ra\n");
// }

// void rra(int *a, int size) {
	
// 	int i;
// 	int temp;

	
// 	temp = a[size - 1];
// 	i = size - 1;
// 	while( i > 0)
// 	{
// 		a[i] = a[i - 1];
// 		i--;
// 	}
// 	a[0] = temp;
// 	printf("temp : %d\n", temp);
// 	printf("rra\n");
// }

// void pb(int *a, int *b, int *sizeA, int *sizeB)
// { 
// 	printf("pb\n");
// 	b[*sizeB] = a[0];
// 	(*sizeB)++;
// 	(*sizeA)--;
// 	for (int i = 0; i < *sizeA; i++)
// 		a[i] = a[i+1];
// }

// void pa(int *a, int *b, int *sizeA, int *sizeB)
// { 
// 	printf("pa\n");
// 	for (int i = *sizeA; i > 0; i--) a[i] = a[i-1]; 
// 	a[0] = b[*sizeB - 1];
// 	(*sizeA)++;
// 	(*sizeB)--;
// }


// int main()
// {
// 	int arr[] = {5,4,3,2,1};
// 	int size = sizeof(arr) / sizeof(arr[0]);
// 	//ra(arr, size);
// 	rra(arr, size);
// 	int i = 0;
// 	while(arr[i])
// 	{
// 		if(i < size)
// 		{
// 			printf("arr: %d\n", arr[i]);
// 			i++;
// 		}    
// 	}
// }





