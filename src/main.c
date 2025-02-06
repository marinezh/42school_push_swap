/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:07:04 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/06 16:07:19 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




typedef struct s_node
{
    int value;
    struct s_node *next;
} t_node;

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
