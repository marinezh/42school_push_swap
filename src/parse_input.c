/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:13:37 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/06 00:33:48 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include "libft.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i] || ft_strlen(str) > 11) // 11 is the max length for "-2147483648"
		return (0);
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
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
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

long long	safe_atoi(char *str, int *num)
{
	long long	res;
	int			sign;
	int			i;

	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!ft_isdigit(str[i])) // Ensure at least one digit is present
        return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		res = res * 10 + (str[i] - '0');
		if ((res * sign) > INT_MAX || (res * sign) < INT_MIN)
			return (0);
		i++;
	}
	*num = res * sign;
	return (1);
}

int	has_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
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

void	free_split(char **splits)
{
	int	i;

	i = 0;
	if (!splits) // Prevent freeing NULL pointer
        return;
	while (splits[i])
	{
		free(splits[i]);
		i++;
	}
	free(splits);
}

// void	validate_input(char **av, int *arr, int *size)
// {
// 	int	i;

// 	i = 0;
// 	while (i < *size)
// 	{
// 		if (!is_valid_number(av[i]))
// 		{
// 			ft_putstr_fd("Error\n", 2);
// 			free(arr);
// 			exit(1);
// 		}
// 		if (!safe_atoi(av[i], &arr[i]))
// 		{
// 			ft_putstr_fd("Error\n", 2);
// 			//printf("Error 5: Number '%s' is out of range\n", av[i]);
// 			free(arr);
// 			exit(1);
// 		}
// 		i++;
// 	}
// 	if (has_duplicates(arr, *size))
// 	{
// 		ft_putstr_fd("Error\n", 2);
// 		free(arr);
// 		exit(1);
// 	}
// }
void	validate_input(char **av, int *arr, int *size, int should_free)
{
    int	i;

    i = 0;
    while (i < *size)
    {
        if (!is_valid_number(av[i]) || !safe_atoi(av[i], &arr[i]))
        {
            ft_putstr_fd("Error\n", 2);
            if (should_free)
                free(arr);
            exit(1);
        }
        i++;
    }
    if (has_duplicates(arr, *size))
    {
        ft_putstr_fd("Error\n", 2);
        if (should_free)
            free(arr);
        exit(1);
    }
}


// int	*parse_input(int ac, char **av, int *size)
// {
// 	int		*arr;
// 	char	**args;

// 	if (ac == 2)
// 	{
// 		args = ft_split(av[1], ' ');
// 		 if (!args)
//     	{
//         	ft_putstr_fd("Error\n", 2);
//         	exit(1);
//     	}
// 		*size = count_words(av[1]);
// 	}
// 	else if (ac > 2)
// 	{
// 		args = av + 1;
// 		*size = ac - 1;
// 	}
// 	arr = malloc(sizeof(int) * (*size));
// 	if (!arr)
// 	{
// 		ft_putstr("Error\n");
// 		exit(1);
// 	}
// 	validate_input(args, arr, size, 1);
// 	if (ac == 2)
// 		free_split(args);
// 	return (arr);
// }
int	*parse_input(int ac, char **av, int *size)
{
	int		*arr;
	char	**args;
	int		should_free;

	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		if (!args)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		*size = count_words(av[1]);
		should_free = 1; // We must free `arr` in case of error
	}
	else if (ac > 2)
	{
		args = av + 1;
		*size = ac - 1;
		should_free = 0; // `args` is not dynamically allocated, do not free
	}

	arr = malloc(sizeof(int) * (*size));
	if (!arr)
	{
		ft_putstr_fd("Error\n", 2);
		if (ac == 2) // Free dynamically allocated `args`
			free_split(args);
		exit(1);
	}

	validate_input(args, arr, size, should_free);

	if (ac == 2)
		free_split(args);
	rank_numbers(arr, *size);
	return (arr);
}

