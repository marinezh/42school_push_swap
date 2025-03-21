/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:13:37 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/08 16:12:23 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	*convert_and_validate(char **args, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (ft_putstr_fd("Error\n", 2), NULL);
	i = 0;
	while (i < size)
	{
		if (!is_valid_number(args[i]) || !safe_atoi(args[i], &arr[i]))
		{
			ft_putstr_fd("Error\n", 2);
			return (free(arr), NULL);
		}
		i++;
	}
	if (has_duplicates(arr, size))
	{
		ft_putstr_fd("Error\n", 2);
		return (free(arr), NULL);
	}
	return (arr);
}

static int	*parse_string(char *av, int *size)
{
	int		*arr;
	char	**args;

	args = ft_split(av, ' ');
	if (!args)
		return (free_args(args), NULL);
	*size = count_words(av);
	arr = convert_and_validate(args, *size);
	free_args(args);
	return (arr);
}
static int	*parse_args(int ac, char **av, int *size)
{
	*size = ac - 1;
	return (convert_and_validate(av + 1, *size));
}
int	*parse_input(int ac, char **av, int *size)
{
	int	*arr;
	int	i;

	arr = NULL;
	i = 0;
	while (av[i] != NULL)
	{
		if (av[i][0] == '\0' || av[i][0] == ' ')
			return (ft_putstr_fd("Error\n", 2), NULL);
		i++;
	}
	if (ac == 2)
		arr = parse_string(av[1], size);
	else if (ac > 2)
		arr = parse_args(ac, av, size);
	if (!arr)
		return (NULL);
	rank_numbers(arr, *size);
	return (arr);
}
