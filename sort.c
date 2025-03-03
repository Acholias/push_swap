/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 01:06:24 by lumugot           #+#    #+#             */
/*   Updated: 2025/03/03 18:56:27 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	define_number_of_chunk(t_chunk *chunk, int size)
{
	if (size > 5 && size < 100)
		chunk->count = 3;
	if (size >= 100 && size < 200)
		chunk->count = 5;
	if (size >= 200 && size < 300)
		chunk->count = 6;
	if (size >= 300 && size < 400)
		chunk->count = 7;
	if (size >= 400 && size <= 500)
		chunk->count = 9;
	return (chunk->count);
}

void	search_max_and_index(t_list **stack_b, int *max_i, int *max_n)
{
	t_list	*current;
	int		index;

	if (!(*stack_b))
		return ;
	current = *stack_b;
	*max_n = current->number;
	*max_i = 0;
	index = 0;
	while (current)
	{
		if (current->number > *max_n)
		{
			*max_n = current->number;
			*max_i = index;
		}
		current = current->next;
		index++;
	}
}

void	push_to_stack_a(t_list **stack_a, t_list **stack_b)
{
	int	max_i;
	int	max_n;
	int	size;
	int	flag;

	flag = 0;
	while (*stack_b)
	{
		search_max_and_index(stack_b, &max_i, &max_n);
		size = stack_size(*stack_b);
		if (max_i <= size / 2)
		{
			while (max_i-- > 0)
			{
				if ((*stack_b)->number == max_n -1)
				{
					push_a(stack_a, stack_b);
					flag = 1;
				}
				if ((*stack_b)->number == max_n)
					push_a(stack_a, stack_b);
				rotate_b(stack_b);
			}
			if (flag == 1)
			{
				swap_a(stack_a);
				flag = 0;
			}
		}
		else
		{
			max_i = size - max_i;
			while (max_i-- > 0)
			{
				if ((*stack_b)->number == max_n -1)
				{
					push_a(stack_a, stack_b);
					flag = 1;
				}
				if ((*stack_b)->number == max_n)
					push_a(stack_a, stack_b);
				reverse_rotate_b(stack_b);
			}
		}
		if ((*stack_b)->number == max_n)
			push_a(stack_a, stack_b);
		if (flag == 1)
		{
			swap_a(stack_a);
			flag = 0;
		}
	}
}


void	full_sort_stack(t_list **stack_a, t_list **stack_b)
{
	separate_stack_by_chunk(stack_a, stack_b);
	push_to_stack_a(stack_a, stack_b);
}
