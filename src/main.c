/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:36:35 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/15 16:38:55 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
	int i = 0;
	int size;
	int *numbers = parse_input(argc, argv, &size);
	//printf("min_ind :%d\n", find_min_indx(numbers, size));
	
	if(size == 2)
		sort_two(numbers, size);
	else if (size == 3)
	{
		sort_three(numbers, size);
	} else if (size <= 100)
	{
		sort_four_five(numbers, size);
	} 
	else
	{
		printf("Error: Only 3 or 5 numbers are supported\n");
	}
	while(i < size)
	{
		printf("%d ", numbers[i]);
		i++;
	}
	printf("\n");
	//printf("max :%d\n", find_max(numbers, size));
	//printf("min :%d\n", find_min(numbers, size));
	
	free(numbers);
	return 0;
}
