/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:49:29 by lumugot           #+#    #+#             */
/*   Updated: 2025/03/15 17:51:03 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	handle_first_half(t_list **stack_a, t_list **stack_b, t_chunk *data)
{
	while (data->max_i-- > 0)
	{
		if ((*stack_b)->number == data->max_n - 1)
		{
			push_a(stack_a, stack_b);
			data->flag = 1;
		}
		if ((*stack_b)->number == data->max_n)
			push_a(stack_a, stack_b);
		rotate_b(stack_b);
	}
	if (data->flag == 1)
	{
		swap_a(stack_a);
		data->flag = 0;
	}
}

void	handle_second_half(t_list **stack_a, t_list **stack_b, t_chunk *data)
{
	data->max_i = data->size - data->max_i;
	while (data->max_i-- > 0)
	{
		if ((*stack_b)->number == data->max_n - 1)
		{
			push_a(stack_a, stack_b);
			data->flag = 1;
		}
		if ((*stack_b)->number == data->max_n)
			push_a(stack_a, stack_b);
		reverse_rotate_b(stack_b);
	}
}

void	push_to_stack_a(t_list **stack_a, t_list **stack_b)
{
	t_chunk	data;

	data.flag = 0;
	while (*stack_b)
	{
		search_max_and_index(stack_b, &data.max_i, &data.max_n);
		data.size = stack_size(*stack_b);
		if (data.max_i <= data.size / 2)
			handle_first_half(stack_a, stack_b, &data);
		else
			handle_second_half(stack_a, stack_b, &data);
		if (*stack_b && (*stack_b)->number == data.max_n)
			push_a(stack_a, stack_b);
		if (data.flag == 1)
		{
			swap_a(stack_a);
			data.flag = 0;
		}
	}
}
