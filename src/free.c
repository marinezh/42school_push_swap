/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:47:32 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/09 21:19:22 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
	{
		if (stack_a->arr)
			free(stack_a->arr);
		free(stack_a);
	}
	if (stack_b)
	{
		if (stack_b->arr)
			free(stack_b->arr);
		free(stack_b);
	}
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	if (!args) // Prevent freeing NULL pointer
		return ;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
