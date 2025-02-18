/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:29:24 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/18 16:56:38 by mzhivoto         ###   ########.fr       */
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
int find_max_indx(int *arr, int size)
{
	int i;
	int max_indx;
	
	max_indx = 0;
	i = 1;
	if (size == 0)
		return 0;
	while(i < size)
	{
		if(arr[i] > arr[max_indx])
		{
			max_indx = i;
		}
		i++;
	}
	return max_indx;
}

int find_min_indx(int *arr, int size)
{
	int i;
	int min_indx;
	
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

int get_median(int *arr, int size)
{
    int sorted[size];
    for (int i = 0; i < size; i++)
        sorted[i] = arr[i];

    // Simple Bubble Sort to get the middle element
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (sorted[j] > sorted[j + 1])
            {
                int temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
    
    return sorted[size / 2];
}

int get_median(t_stack *stack_a)
{
	int i = 0;
	int sorted[stack_a->size];
	while (i < stack_a->size)
	{
		sorted[i] = stack_a->arr[i];
		i++;
	}

	i = 0;
	while(i < stack_a->size - 1)
	{
		int j = 0;
		while(j < stack_a->size - i -1)
		{
			if(sorted[j] > sorted[j + 1])
			{
				int temp = sorted[j];    // change to ft_swap after switching libft lib
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	if (stack_a->size % 2 != 0)
        return sorted[stack_a->size / 2];  // Odd size -> middle element
    else
        return (sorted[(stack_a->size / 2) - 1] + sorted[stack_a->size / 2]) / 2.0;	
}

