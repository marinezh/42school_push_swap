/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:22:58 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/07 17:40:15 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:12:47 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/15 15:21:51 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ra(t_stack *stack_a)
{
	int	i;
	int	temp;
	int	size;

	size = stack_a->size;
	if (size < 2)
		return ;
	i = 0;
	temp = stack_a->arr[0];
	while (i < size - 1)
	{
		stack_a->arr[i] = stack_a->arr[i + 1];
		i++;
	}
	stack_a->arr[size - 1] = temp;
	ft_putstr("ra\n");
}

void	rb(t_stack *stack_b)
{
	int	i;
	int	temp;
	int	size;

	size = stack_b->size;
	if (size < 2)
		return ;
	i = 0;
	temp = stack_b->arr[0];
	while (i < size - 1)
	{
		stack_b->arr[i] = stack_b->arr[i + 1];
		i++;
	}
	stack_b->arr[size - 1] = temp;
	ft_putstr("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_putstr("rr\n");
}
