/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:13:37 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/12 18:20:06 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int is_valid_number(char *str) 
{
    int i = 0;
    
    // Allow negative numbers
    if (str[i] == '-' || str[i] == '+') i++;

    // Ensure the rest are digits
    while (str[i]) {
        if (!isdigit(str[i])) return 0;
        i++;
    }
    
    return 1;
}

// Convert string to int and check for overflow
int safe_atoi(char *str, int *num) 
{
    long temp = atol(str); // Convert to long first

    if (temp > INT_MAX || temp < INT_MIN) {
        return 0; // Overflow detected
    }

    *num = (int)temp;
    return 1;
}

// Check for duplicates in the array
int has_duplicates(int *arr, int size) 
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) return 1; // Duplicate found
        }
    }
    return 0;
}

int *parse_input(int ac, char **av, int *size) 
{
	if (ac < 2) {
	    putstr("Error 1\n");
	    exit(1);
	}

	*size = ac - 1;
	int *numbers = malloc(sizeof(int) * (*size));

	if (!numbers) {
		putstr("Error 2\n");
		exit(1);
	}

	for (int i = 0; i < *size; i++)
	{
		if (!is_valid_number(av[i + 1])) {
			printf("Error 4: Invalid number '%s'\n", av[i + 1]);
			free(numbers);
			exit(1);
		}

		if (!safe_atoi(av[i + 1], &numbers[i]))
		{
			printf("Error 5: Number '%s' is out of range\n", av[i + 1]);
			free(numbers);
			exit(1);
		}
	}

	if (has_duplicates(numbers, *size))
	{
		putstr("Error 3\n");
		free(numbers);
		exit(1);
	}


	return numbers;
}




