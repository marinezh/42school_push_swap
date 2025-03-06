/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:32:13 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/06 22:46:40 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	rank_numbers(int *arr, int size)
{
	int	*sorted;
	int	i, j;

	// Step 1: Allocate memory for sorted copy
	sorted = (int *)malloc(size * sizeof(int));
	if (!sorted)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}

	// Step 2: Copy original array to sorted array
	for (i = 0; i < size; i++)
		sorted[i] = arr[i];

	// Step 3: Sort the copied array (simple Bubble Sort for small inputs)
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (sorted[j] > sorted[j + 1])
			{
				int temp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = temp;
			}
		}
	}

	// Step 4: Replace original array with ranks
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (arr[i] == sorted[j])
			{
				arr[i] = j + 1; // Assign the rank
				break;
			}
		}
	}

	free(sorted);
}
