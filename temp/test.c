/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:07:04 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/27 13:56:33 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <limits.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
#include "../includes/push_swap.h"

// Check if a string is a valid integer
int is_number(const char *str)
{
	if (!str || *str == '\0') return 0;  // Empty string is invalid

	int i = 0;
	if (str[i] == '-' || str[i] == '+')  // Handle optional sign
		i++;

	if (!isdigit(str[i]))  // Must have at least one digit
		return 0;

	while (str[i])
	{
		if (!isdigit(str[i]))
			return 0;
		i++;
	}
	return 1;
}

// Convert string to integer with error handling (overflow/underflow)
int safe_atoi(const char *str, int *error)
{
	long num = strtol(str, NULL, 10);
	if (num > INT_MAX || num < INT_MIN)
		*error = 1;
	return (int)num;
}

// typedef struct s_node
// {
//     int value;
//     struct s_node *next;
// } t_node;

// Create a new node
t_node *new_node(int value)
{
	t_node *node = malloc(sizeof(t_node));
	if (!node)
		return NULL;
	node->value = value;
	node->next = NULL;
	return node;
}

// Append node at the end of the list
void append_node(t_node **head, int value)
{
	t_node *new = new_node(value);
	if (!new) return;

	if (!*head)
	{
		*head = new;
		return;
	}
	t_node *tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

// Check for duplicate values
int has_duplicate(t_node *head, int num)
{
	while (head)
	{
		if (head->value == num)
			return 1;
		head = head->next;
	}
	return 0;
}


void parse_input(int argc, char **argv, t_node **stack)
{
	int i = 1;
	int error = 0;
	int num;

	while (i < argc)
	{
		if (!is_number(argv[i]))
		{
			printf("Error: Invalid input '%s'\n", argv[i]);
			exit(EXIT_FAILURE);
		}

		num = safe_atoi(argv[i], &error);
		if (error)
		{
			printf("Error: Integer overflow/underflow '%s'\n", argv[i]);
			exit(EXIT_FAILURE);
		}

		if (has_duplicate(*stack, num))
		{
			printf("Error: Duplicate number '%d'\n", num);
			exit(EXIT_FAILURE);
		}

		append_node(stack, num);
		i++;
	}
}



int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Usage: ./push_swap <numbers>\n");
		return 1;
	}

	t_node *stack_a = NULL;
	parse_input(argc, argv, &stack_a);

	// Print the stack to verify input
	t_node *tmp = stack_a;
	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}

	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_500.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:36:08 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/27 13:36:50 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Function to check if there are any elements in stack_a belonging to the current chunk
int has_chunk_element(t_stack *stack_a, int limit)
{
	int i = 0;

	while (i < stack_a->size)
	{
		if (stack_a->arr[i] <= limit)
			return 1;
	}
	return 0;
}
int cost_to_top(t_stack *stack, int index)
{
	int cost = 0;

	if (index <= stack->size / 2)
	{
		while (index > 0)
		{
			cost++;
			index--;
		}
	}
	else
	{
		while (index < stack->size)
		{
			cost++;
			index++;
		}
	}
	return cost;
}
int push_to_b_cost(t_stack *stack_a, int limit)
{
	int i = 0;
	int min_cost = stack_a->size;
	int current_cost = 0;
	int best_cost_index = 0;
	while(i < stack_a->size)
	{
		if(stack_a->arr[i] < limit)
		{
			current_cost = cost_to_top(stack_a, i);
			//printf("current cost %d\n", current_cost);
			if (current_cost < min_cost)
			{
				min_cost = current_cost;
				best_cost_index = i;
			}
		}
		i++;
	}
	return (best_cost_index);
}

void first_move_500(t_stack *stack_a, t_stack *stack_b)
{
	int size = stack_a->size;
	int chunks = 0;
	int chunk_size;
	int i;
	int *sorted = sorted_array(stack_a); //sorted copy of stack_a
	print_array(sorted, size);
	
	
	if(size <= 100)
		chunks = 5;
	else
		chunks = 15;
	chunk_size = size / chunks;
	
	i = 0;
	
	int limit ;
	
	while (i < chunks)
	{
		limit = sorted[(i + 1) * chunk_size];
		printf("Chunk %d limit: %d\n", i + 1, limit);
		int temp_chunk_size = chunk_size;
				while(temp_chunk_size > 0)
		{
			move_to_top(stack_a, push_to_b_cost(stack_a, limit));			
			pb(stack_a, stack_b);
			temp_chunk_size--;
		}
		i++;
	}
	sort_stack_b(stack_a, stack_b);
	print_stack_a(stack_a);
	print_stack_b(stack_b);

 	free(sorted);
}

void chunk_sort_500(t_stack *stack_a, t_stack *stack_b) 
{
	first_move_500(stack_a, stack_b);
}


