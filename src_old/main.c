/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:36:35 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/21 17:15:05 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
	//int i = 0;
	int size;
	int *numbers = parse_input(argc, argv, &size);
	//printf("min_ind :%d\n", find_min_indx(numbers, size));
	t_stack a;
    a.arr = numbers;
    a.size = size;
    a.capacity = size;
	
	if(size == 2)
		sort_two(a.arr, size);
	else if (size == 3)
	{
		sort_three(a.arr, size);
	} else if (size == 4 || size == 5)
	{
		sort_four_five(a.arr, size);
	} 
	else
	{
		chunk_sort(stack_a, stack_b);
	}
	// while(i < size)
	// {
	// 	printf("%d ", a.arr[i]);
	// 	i++;
	// }
	//printf("\n");
	//printf("max :%d\n", find_max(numbers, size));
	//printf("min :%d\n", find_min(numbers, size));
	
	free(numbers);
	return 0;
}
