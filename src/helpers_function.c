/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:29:24 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/17 17:40:55 by mzhivoto         ###   ########.fr       */
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

int find_min_indx(t_stack *stack_a)
{
	int i;
	int min_indx;
	
	min_indx = 0;
	i = 1;
	if (stack_a->size == 0)
		return 0;
	while(i < stack_a->size)
	{
		if(stack_a->arr[i] < stack_a->arr[min_indx])
		{
			min_indx = i;
		}
		i++;
	}
	return min_indx;
}
int is_sorted(t_stack *stack_a)
{
	int i;
	int *arr;
	int size;

	arr = stack_a->arr;
	size = stack_a->size;
	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			return 0;// Not sorted
		}
		i++;
	}
	return 1;  // Sorted
} 
void move_min_to_top(t_stack *stack_a)
{
	int	sizeA; 
	int	min_index; 
	
	sizeA = stack_a->size; 
	min_index = find_min_indx(stack_a);
	//printf("min_index %d is %d\n ", min_index, stack_a->arr[min_index]);
	// Decide the shortest way to bring the min to top
	if (min_index <= sizeA / 2)
	{
		while (min_index > 0)
		{
			ra(stack_a);
			min_index--;
		}
	}
	else
	{
		while (min_index < sizeA)
		{
			rra(stack_a);
			min_index++;
		}
	}
}

// int get_median(int *arr, int size)
// {
//     int sorted[size];
//     for (int i = 0; i < size; i++)
//         sorted[i] = arr[i];

//     // Simple Bubble Sort to get the middle element
//     for (int i = 0; i < size - 1; i++)
//         for (int j = 0; j < size - i - 1; j++)
//             if (sorted[j] > sorted[j + 1])
//             {
//                 int temp = sorted[j];
//                 sorted[j] = sorted[j + 1];
//                 sorted[j + 1] = temp;
//             }
    
//     return sorted[size / 2];
// }

