/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:43:21 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/05 15:01:29 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	rra(t_stack *stack_a)
{
	int	i;
	int	temp;
	int	size;

	size = stack_a->size;
	if (size < 2)
		return ;
	temp = stack_a->arr[size - 1];
	i = size - 1;
	while (i > 0)
	{
		stack_a->arr[i] = stack_a->arr[i - 1];
		i--;
	}
	stack_a->arr[0] = temp;
	ft_putstr("rra\n");
}

void	rrb(t_stack *stack_b)
{
	int	i;
	int	temp;
	int	size;

	size = stack_b->size;
	if (size < 2)
		return ;
	temp = stack_b->arr[size - 1];
	i = size - 1;
	while (i > 0)
	{
		stack_b->arr[i] = stack_b->arr[i - 1];
		i--;
	}
	stack_b->arr[0] = temp;
	ft_putstr("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size < 2 && stack_b->size < 2)
		return ;
	rra(stack_a);
	rrb(stack_b);
	ft_putstr("rrr\n");
}
