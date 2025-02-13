/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:20:43 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/13 13:46:52 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
#include <limits.h>
#include <ctype.h>

typedef struct s_node
{
	int value;
	struct s_node *next;
} t_node;

// typedef struct s_node
// {
// 	int				num;
// 	int				index;
// 	int				flag;
// 	struct s_node	*next;
// 	struct s_node	*prev;
// } t_node;

// typedef struct s_all
// {
// 	t_node	*stack_a;
// 	t_node	*stack_b;
// 	int		mib_a;
// 	int 	med;
// 	int 	len_a;
// 	int 	len_b;
// }


void	putstr(char *str);
int	is_valid_number(char *str);
int	safe_atoi(char *str, int *num);
int	has_duplicates(int *arr, int size);
int	*parse_input(int ac, char **av, int *size);
// void	sort_three(int *numbers);
// void	sort_five(int *numbers);
void sort_five(int *a);

#endif
