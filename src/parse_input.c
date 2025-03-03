/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:13:37 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/03 17:27:23 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"


int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
int	count_words(char *str)
{
	int	count = 0;
	int	in_word = 0;

	while (*str)
	{
		if (*str != ' ' && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*str == ' ')
			in_word = 0;
		str++;
	}
	return (count);
}

int	safe_atoi(char *str, int *num)
{
	long	temp;
	
	temp = atoi(str);
	printf("TEMP IS : %ld\n", temp);

	if (temp > INT_MAX || temp < INT_MIN)
		return (0);
	*num = temp;
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
			printf("Error\n");
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
		ft_putstr_fd("Error 3\n", 2);
		free(arr);
		exit(1);
	}
}

int	*parse_input(int ac, char **av, int *size)
{
	int	*arr;
	char **args;
		
	if (ac < 2)
	{
		putstr("Error 1\n");
		exit(1);
	}
	
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
		args = av + 1;
	
	*size = (ac == 2) ? count_words(av[1]) : ac - 1;
	arr = malloc(sizeof(int) * (*size));
	if (!arr)
	{
		putstr("Error 2\n");
		exit(1);
	}
	validate_input(args, arr, size);
	return (arr);
}

