/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:29:24 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/14 20:09:04 by mzhivoto         ###   ########.fr       */
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
