/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:58:54 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/23 17:10:56 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
// #include "../includes/push_swap.h"



// int find_index(t_stack *stack, int num) {
//     int i = 0;
//     while (i < stack->size) {
//         if (stack->arr[i] == num)
//             return i;
//         i++;
//     }
//     return -1;
// }

// // Функция для нахождения минимального и максимального значений в чанке
// void find_min_max(t_stack *stack, int start, int end, int *min, int *max) {
//     int i = start;
//     *min = stack->arr[start];
//     *max = stack->arr[start];

//     while (i < end) {
//         if (stack->arr[i] < *min)
//             *min = stack->arr[i];
//         if (stack->arr[i] > *max)
//             *max = stack->arr[i];
//         i++;
//     }
// }

// // Функция сортировки чанками
// void chunk_sort(t_stack *a, t_stack *b, int chunk_size) {
//     int i = 0;

//     while (i < a->size) {
//         int start = i;
//         int end = (i + chunk_size < a->size) ? i + chunk_size : a->size;
        
//         int min, max;
//         find_min_max(a, start, end, &min, &max);

//         int j = start;
//         while (j < end) {
//             int index = find_index(a, a->arr[start]); // Находим индекс элемента
            
//             while (index > 0) { // Перемещаем нужный элемент вверх
//                 ra(a);
//                 index--;
//             }
//             pb(a, b); // Отправляем элемент в stack_b
//             j++;
//         }
//         i += chunk_size;
//     }

//     // Возвращаем элементы обратно в stack_a
//     while (b->size > 0) {
//         pa(a, b);
//     }
// }

// Функция для вывода стека
// void print_stack(t_stack *stack, char *name) {
//     printf("%s: ", name);
//     int i = 0;
//     while (i < stack->size) {
//         printf("%d ", stack->arr[i]);
//         i++;
//     }
//     printf("\n");
// }

// void push_chunks(t_stack *stack_a, t_stack *stack_b, int chunk_size)
// {
// 	//int i = 0;
// 	int *sorted = sorted_array(stack_a); // Get sorted version of stack_a
// 	int chunk_index = stack_a->size / chunk_size;
	
// 	while (stack_a->size > 3)
// 	{
// 		if (stack_a->arr[0] <= sorted[chunk_index]) // Compare with chunk threshold
// 		{
// 			pb(stack_a, stack_b);
// 			chunk_index++; // Move to next chunk
// 		}
// 		else
// 		{
// 			ra(stack_a);
// 		}
// 	}

// 	free(sorted); // Free memory
// }