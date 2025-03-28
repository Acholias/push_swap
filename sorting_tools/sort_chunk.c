/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:42:35 by lumugot           #+#    #+#             */
/*   Updated: 2025/03/28 13:41:11 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	init_chunk_limits(t_chunk *chunk, int *array, int index, int size)
{
	int		chunk_size;

	chunk_size = size / chunk->count;
	chunk->min = array[index * chunk_size];
	if (index == chunk->count - 1)
		chunk->max = array[size - 1] + 1;
	else
		chunk->max = array [(index + 1) * chunk_size];
	chunk->median = array[index * chunk_size + (chunk_size / 2)];
}

int	check_range_number_for_chunk(t_list *stack, int min, int max)
{
	while (stack)
	{
		if (stack->number >= min && stack->number < max)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	push_to_stack_b(t_list **stack_a, t_list **stack_b, t_chunk *chunk)
{
	while (check_range_number_for_chunk(*stack_a, chunk->min, chunk->max))
	{
		if ((*stack_a)->number >= chunk->min && (*stack_a)->number < chunk->max)
		{
			push_b(stack_b, stack_a);
			if ((*stack_b)->number >= chunk->median)
				rotate_b(stack_b);
		}
		else
			rotate_a(stack_a);
	}
}

void	process_chunks(t_list **stack_a, t_list **stack_b, int *array, int len)
{
	t_chunk	chunk;
	int		index;

	index = 0;
	define_number_of_chunk(&chunk, len);
	while (index < chunk.count)
	{
		init_chunk_limits(&chunk, array, index, len);
		push_to_stack_b(stack_a, stack_b, &chunk);
		index++;
	}
}

void	separate_stack_by_chunk(t_list **stack_a, t_list **stack_b)
{
	int		size;
	int		*array;

	size = stack_size(*stack_a);
	array = list_to_array(*stack_a, size);
	if (!array)
		return ;
	quicksort(array, 0, size -1);
	process_chunks(stack_a, stack_b, array, size);
	free(array);
}
