/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:42:55 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/02/14 20:41:50 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void sa(int *a) {
	int temp = a[0];
	a[0] = a[1];
	a[1] = temp;
	printf("sa\n");
}

// void ra(int *a) {
// 	int temp = a[0];
// 	a[0] = a[1];
// 	a[1] = a[2];
// 	a[2] = temp;
// 	printf("ra\n");
// }

// void rra(int *a) {
// 	int temp = a[2];
// 	a[2] = a[1];
// 	a[1] = a[0];
// 	a[0] = temp;
// 	printf("rra\n");
// }
void ra(int *a, int size)
{
	int i;
	int temp;

	temp = a[0];
	// printf("temp is %d\n", temp);
	i = 0;
	while(i < size)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[size - 1] = temp;
	printf("ra\n");
}

void rra(int *a, int size) {
	
	int i;
	int temp;

	
	temp = a[size - 1];
	i = size - 1;
	while( i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = temp;
	//printf("temp : %d\n", temp);
	printf("rra\n");
}
void pb(int *a, int *b, int *sizeA, int *sizeB)
{ 
	printf("pb\n");
	b[*sizeB] = a[0];
	(*sizeB)++;
	(*sizeA)--;
	for (int i = 0; i < *sizeA; i++)
		a[i] = a[i+1];
}

void pa(int *a, int *b, int *sizeA, int *sizeB)
{ 
	printf("pa\n");
	for (int i = *sizeA; i > 0; i--) a[i] = a[i-1]; 
	a[0] = b[*sizeB - 1];
	(*sizeA)++;
	(*sizeB)--;
}


void sort_three(int *a, int size)
{
	if (a[0] > a[1] && a[1] > a[2]) 
	{  // 3 2 1
		printf("1");
		sa(a);
		rra(a , size);
	} else if (a[0] > a[2] && a[2] > a[1]) 
	{ // 3 1 2
		printf("2");
		ra(a, size);
	} 
	else if (a[1] > a[0] && a[0] > a[2]) 
	{ // 2 3 1
		printf("3");
		rra(a, size);
	} 
	else if (a[0] > a[1] && a[1] < a[2]) 
	{ // 2 1 3
		printf("4");
		sa(a);
	} 
	else if (a[0] < a[1] && a[1] > a[2]) 
	{ // 1 3 2
		printf("5");
		rra(a, size);
		sa(a);
	}
}

// void sort_five(int *a, int size)
// {
// 	int *b;
// 	int sizeA;
// 	int sizeB;
// 	int i;

// 	i = 0;
// 	int minA = find_min(a, size);
	

// }


// void sort_five(int *a, int size) 
// {
// 	int b[2], sizeA = 5, sizeB = 0;

// 	// Find and push the two smallest elements to stack B
// 	int i = 0;
// 	while(i < 2)
// 	{
// 		int min_idx = 0;
// 		int j = 1;
// 		while ( j < sizeA)
// 		{
// 			if (a[j] < a[min_idx])
// 				min_idx = j;
// 			j++;
// 		}
// 		while (min_idx > 0) {
// 			ra(a, sizeA);
// 			min_idx--;
// 		}
// 		pb(a, b, &sizeA, &sizeB);
// 		i++;
// 	}
// 	// Sort the remaining three numbers
// 	sort_three(a, size);

// 	// Push elements back from B to A
// 	pa(a, b, &sizeA, &sizeB);
// 	pa(a, b, &sizeA, &sizeB);
// }
int find_min_indx(int *arr, int size)
{
	int i;
	int min_indx = 0;
	
	min_indx = 0;
	i = 1;
	if (size == 0)
		return 0;
	while(i < size)
	{
		if(arr[i] < arr[min_indx])
		{
			min_indx = i;
		}
		i++;
	}
	return min_indx;
}
int is_sorted(int *arr, int size)
{
    int i = 0;
    while (i < size - 1) {
        if (arr[i] > arr[i + 1]) {
            return 0;  // Not sorted
        }
        i++;
    }
    return 1;  // Sorted
} 
void move_min_to_top(int *a, int *sizeA)
{
    int min_idx = find_min_indx(a, *sizeA);

    // Decide the shortest way to bring the min to top
    if (min_idx <= *sizeA / 2)
    {
        while (min_idx > 0)
        {
            ra(a, *sizeA);
            min_idx--;
        }
    }
    else
    {
        while (min_idx < *sizeA)
        {
            rra(a, *sizeA);
            min_idx++;
        }
    }
}


void sort_four_five(int *a, int size)
{
	int b[2], sizeA = size, sizeB = 0;
	int num_to_push = size - 3; // Push 1 element if size=4, Push 2 if size=5

	// Find and push the smallest elements to stack B
	if (is_sorted(a, size)) 
	{
        return;  // Skip sorting since it's already sorted
    }
	
    while (sizeB < num_to_push)
    {
        move_min_to_top(a, &sizeA);
        pb(a, b, &sizeA, &sizeB);
    }

	// Sort the remaining three numbers
	sort_three(a, 3);
	// Ensure `b` is sorted before pushing back
	if (sizeB == 2 && b[0] > b[1])
	{
		sa(b);
	}
	// Push elements back from B to A
	while (sizeB > 0)
	{
		pa(a, b, &sizeA, &sizeB);
	}
}
