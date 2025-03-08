/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:42:55 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/05 17:33:03 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void sort_two(t_stack *stack_a)
{
	// int size;
	// size = stack_a->size;
	//if(!is_sorted(stack_a))
	sa(stack_a);
	
}

void sort_three(t_stack *stack_a)
{
	int *a = stack_a->arr;
	if (a[0] > a[1] && a[1] > a[2])
	{
		sa(stack_a);
		rra(stack_a); // 3 2 1
	} 
	else if (a[0] > a[2] && a[2] > a[1])
		ra(stack_a); // 3 1 2
	else if (a[1] > a[0] && a[0] > a[2])
		rra(stack_a); // 2 3 1

	else if (a[0] > a[1] && a[1] < a[2])
		sa(stack_a); // 2 1 3
	else if (a[0] < a[1] && a[1] > a[2])
	{ 
		rra(stack_a); // 1 3 2
		sa(stack_a);
	}
	//printf("sort three\n");
}

void sort_four_five(t_stack *stack_a, t_stack *stack_b)
{
	int num_to_push = stack_a->size - 3; 
	int min_index;

	// if (is_sorted(stack_a)) 
	// 	return;  
	while (stack_b->size < num_to_push)
	{
		min_index = find_min_index(stack_a);
		//printf("min inx is %d digits %d\n", min_index, stack_a->arr[i]);
		move_to_top_a(stack_a, min_index);
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);

	if (stack_b->size == 2 && stack_b->arr[0] < stack_b->arr[1])
		sb(stack_b);
	
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
	
}
