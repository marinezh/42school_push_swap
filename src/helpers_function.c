/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:29:24 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/20 15:27:46 by mzhivoto         ###   ########.fr       */
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
// int find_max_index(t_stack *stack_a)
// {
// 	int i;
// 	int max_indx;
	
// 	max_indx = 0;
// 	i = 1;
// 	if (stack_a->size == 0)
// 		return 0;
// 	while(i < stack_a->size)
// 	{
// 		if(stack_a->arr[i] > stack_a->arr[max_indx])
// 		{
// 			max_indx = i;
// 		}
// 		i++;
// 	}
// 	return max_indx;
// }
int find_max_index(t_stack *stack)
{
    if (stack->size == 0) return -1;  // Handle empty stack

    int max_idx = 0;
    int max_value = stack->arr[0];

    for (int i = 1; i < stack->size; i++)
    {
        if (stack->arr[i] > max_value)
        {
            max_value = stack->arr[i];
            max_idx = i;
        }
    }
    return max_idx;
}

int find_min_index(t_stack *stack_a)
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
	min_index = find_min_index(stack_a);
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
// int get_median(t_stack *stack_a)
// {
// 	int i = 0;
// 	int sorted[stack_a->size];
// 	while (i < stack_a->size)
// 	{
// 		sorted[i] = stack_a->arr[i];
// 		i++;
// 	}
// 	i = 0;
// 	while(i < stack_a->size - 1)
// 	{
// 		if(sorted[i] > sorted[i + 1])
// 		{
// 			int temp = sorted[i];    // change to ft_swap after switching libft lib
// 			sorted[i] = sorted[i + 1];
// 			sorted[i + 1] = temp;
// 			i = 0;
// 		}
// 		else
// 			i++;
// 	}
// 	if (stack_a->size % 2 != 0)
// 		return sorted[stack_a->size / 2];  // Odd size -> middle element
// 	else
// 		return (sorted[(stack_a->size / 2) - 1] + sorted[stack_a->size / 2]) / 2.0;
// }