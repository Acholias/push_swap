/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:48:00 by lumugot           #+#    #+#             */
/*   Updated: 2025/03/03 18:13:48 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_list *stack)
{
	t_list	*current;
	int		size;

	current = stack;
	size = 0;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

int	check_sorted(t_list *stack)
{
	int	temp;

	while (stack->next)
	{
		temp = stack->number;
		stack = stack->next;
		if (temp > stack->number)
			return (0);
	}
	return (1);
}

int	find_min_value(t_list *stack_a)
{
	t_list	*current;
	int		min_value;

	current = stack_a;
	min_value = stack_a->number;
	while (current)
	{
		if (current->number < min_value)
			min_value = current->number;
		current = current->next;
	}
	return (min_value);
}

int	select_sort(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !(*stack_a))
		return (0);
	if ((stack_size(*stack_a)) == 2)
		sort_2_values(stack_a);
	else if (stack_size(*stack_a) == 3)
		sort_3_values(stack_a);
	else if (stack_size(*stack_a) == 4)
		sort_4_values(stack_a, stack_b);
	else if (stack_size(*stack_a) == 5)
		sort_5_values(stack_a, stack_b);
	else
		full_sort_stack(stack_a, stack_b);
	return (1);
}
