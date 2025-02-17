/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:13:37 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/17 20:26:34 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	safe_atoi(char *str, int *num)
{
	long	temp;

	temp = atol(str);
	if (temp > INT_MAX || temp < INT_MIN)
		return (0);
	*num = (int)temp;
	return (1);
}

int	has_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size -1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	validate_input(char **av, int *arr, int *size)
{
	int	i;

	i = 0;
	while (i < *size)
	{
		if (!is_valid_number(av[i]))
		{
			printf("Error 4: Invalid number '%s'\n", av[i]);
			free(arr);
			exit(1);
		}
		if (!safe_atoi(av[i], &arr[i]))
		{
			printf("Error 5: Number '%s' is out of range\n", av[i]);
			free(arr);
			exit(1);
		}
		i++;
	}
	if (has_duplicates(arr, *size))
	{
		putstr("Error 3\n");
		free(arr);
		exit(1);
	}
}

int	*parse_input(int ac, char **av, int *size)
{
	int	*arr;

	if (ac < 2)
	{
		putstr("Error 1\n");
		exit(1);
	}
	*size = ac - 1;
	arr = malloc(sizeof(int) * (*size));
	if (!arr)
	{
		putstr("Error 2\n");
		exit(1);
	}
	validate_input(av + 1, arr, size);
	return (arr);
}
