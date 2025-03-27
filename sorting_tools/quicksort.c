/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:39:09 by lumugot           #+#    #+#             */
/*   Updated: 2025/03/27 16:50:13 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_value(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partitions(int *tab, int start, int end)
{
	int	pivot;
	int	start_tab;

	start_tab = start;
	pivot = tab[start];
	start++;
	while (start <= end)
	{
		while (start <= end && tab[start] < pivot)
			start++;
		while (start <= end && tab[end] > pivot)
			end--;
		if (start < end)
			swap_value(&tab[start], &tab[end]);
		start++;
	}
	swap_value(&tab[start_tab], &tab[end]);
	return (end);
}

void	quicksort(int *tab, int start, int end)
{
	int	pivot_index;

	if (start < end)
	{
		pivot_index = partitions(tab, start, end);
		quicksort(tab, start, pivot_index - 1);
		quicksort(tab, pivot_index + 1, end);
	}
}

int	calculate_median(int *stack, int size)
{
	int	*temp_tab;
	int	median;
	int	index;

	if (size <= 0)
		return (0);
	index = 0;
	temp_tab = (int *)malloc(sizeof(int) * size);
	if (!temp_tab)
		return (0);
	while (index < size)
	{
		temp_tab[index] = stack[index];
		index++;
	}
	quicksort(temp_tab, 0, size - 1);
	if (size % 2 == 0)
		median = (temp_tab[size / 2 - 1] + temp_tab[size / 2]) / 2;
	else
		median = temp_tab[size / 2];
	free(temp_tab);
	return (median);
}

int	*list_to_array(t_list *stack, int size)
{
	int	*array;
	int	index;

	index = 0;
	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	while (stack && index < size)
	{
		array[index] = stack->number;
		stack = stack->next;
		index++;
	}
	return (array);
}
