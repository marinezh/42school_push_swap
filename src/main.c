/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:36:35 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/12 17:28:47 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"



int main(int argc, char **argv) {
    int size;
    int *numbers = parse_input(argc, argv, &size);

    if (size == 3) {
        //sort_three(numbers);
    } else if (size == 5) {
        //sort_five(numbers);
    } else {
        printf("Error: Only 3 or 5 numbers are supported\n");
    }

    free(numbers);
    return 0;
}