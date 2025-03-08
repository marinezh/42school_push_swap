/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:32:13 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/08 14:21:46 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	bubble_sort(int *arr, int size)
{
	int i, j, temp, swapped;
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		swapped = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = 1;
			}
			j++;
		}
		if (!swapped) // Stops early if already sorted
			break ;
		i++;
	}
}
int	*sorted_array(int *arr, int size)
{
	int	*sorted;
	int	i;

	if (!arr || size == 0)
		return (NULL); // Edge case: Empty array
	sorted = (int *)malloc(size * sizeof(int));
	if (!sorted)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	// Copy elements using a loop
	i = 0;
	while (i < size)
	{
		sorted[i] = arr[i];
		i++;
	}
	bubble_sort(sorted, size);
	return (sorted); // Caller must free() the returned array
}

// Rank the numbers based on sorted order
void	rank_numbers(int *arr, int size)
{
	int	*sorted;

	int i, j;
	if (!arr || size == 0)
		return ;
	sorted = sorted_array(arr, size);
	if (!sorted)
		return ;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr[i] == sorted[j])
			{
				arr[i] = j + 1;
				break ;
			}
			j++;
		}
		i++;
	}
	free(sorted);
}
