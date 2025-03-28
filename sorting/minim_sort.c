/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minim_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:45:20 by lumugot           #+#    #+#             */
/*   Updated: 2025/03/28 13:40:57 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int	find_position(t_list *stack, int value)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->number == value)
			return (position);
		stack = stack->next;
		position++;
	}
	return (-1);
}

void	sort_2_values(t_list **stack_a)
{
	if ((*stack_a)->number > (*stack_a)->next->number)
		swap_a(stack_a);
}

void	sort_3_values(t_list **stack_a)
{
	if ((*stack_a)->number < (*stack_a)->next->number)
	{
		if ((*stack_a)->number > (*stack_a)->next->next->number)
			reverse_rotate_a(stack_a);
		else
		{
			reverse_rotate_a(stack_a);
			swap_a(stack_a);
		}
		return ;
	}
	if ((*stack_a)->next->number > (*stack_a)->next->next->number)
	{
		rotate_a(stack_a);
		swap_a(stack_a);
		return ;
	}
	else
	{
		if ((*stack_a)->number < (*stack_a)->next->next->number)
			swap_a(stack_a);
		else
			rotate_a(stack_a);
	}
}

void	sort_4_values(t_list **stack_a, t_list **stack_b)
{
	int	min_value;

	min_value = find_min_value(*stack_a);
	if (find_position(*stack_a, min_value) <= stack_size(*stack_a) / 2)
	{
		while ((*stack_a)->number != min_value)
			rotate_a(stack_a);
	}
	else
	{
		while ((*stack_a)->number != min_value)
			reverse_rotate_a(stack_a);
	}
	push_b(stack_b, stack_a);
	if (!check_sorted(*stack_a))
		sort_3_values(stack_a);
	push_a(stack_a, stack_b);
}

void	sort_5_values(t_list **stack_a, t_list **stack_b)
{
	int	index;
	int	min_value;

	index = -1;
	while (++index < 2)
	{
		min_value = find_min_value(*stack_a);
		if (find_position(*stack_a, min_value) <= stack_size(*stack_a) / 2)
		{
			while ((*stack_a)->number != min_value)
				rotate_a(stack_a);
		}
		else
		{
			while ((*stack_a)->number != min_value)
				reverse_rotate_a(stack_a);
		}
		push_b(stack_b, stack_a);
	}
	if (!check_sorted(*stack_a))
		sort_3_values(stack_a);
	if ((*stack_b)->number < (*stack_b)->next->number)
		swap_b(stack_b);
	push_a(stack_b, stack_a);
	push_a(stack_b, stack_a);
}
