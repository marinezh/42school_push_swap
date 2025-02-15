/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:29:24 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/15 15:09:29 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void putstr(char *str)
{
	int len;

	len = 0;
	while(str[len])
		len++;
	write(1, str, len);
}
int find_max(int *arr, int size)
{
	int i;
	int max;
	
	max = arr[0];
	i = 1;
	if (size == 0)
		return 0;
	while(i < size)
	{
		if(arr[i] > max)
		{
			max = arr[i];
		}
		i++;
	}
	return max;
}
int find_min(int *arr, int size)
{
	int i;
	int min;
	
	min = arr[0];
	i = 1;
	if (size == 0)
		return 0;
	while(i < size)
	{
		if(arr[i] < min)
		{
			min = arr[i];
		}
		i++;
	}
	return min;
}
int find_min_indx(int *arr, int size)
{
	int i;
	int min_indx = 0;
	
	min_indx = 0;
	i = 1;
	if (size == 0)
		return 0;
	while(i < size)
	{
		if(arr[i] < arr[min_indx])
		{
			min_indx = i;
		}
		i++;
	}
	return min_indx;
}
int is_sorted(int *arr, int size)
{
	int i = 0;
	while (i < size - 1) {
		if (arr[i] > arr[i + 1]) {
			return 0;  // Not sorted
		}
		i++;
	}
	return 1;  // Sorted
} 
void move_min_to_top(int *a, int *sizeA)
{
	int min_idx = find_min_indx(a, *sizeA);

	// Decide the shortest way to bring the min to top
	if (min_idx <= *sizeA / 2)
	{
		while (min_idx > 0)
		{
			ra(a, *sizeA);
			min_idx--;
		}
	}
	else
	{
		while (min_idx < *sizeA)
		{
			rra(a, *sizeA);
			min_idx++;
		}
	}
}
