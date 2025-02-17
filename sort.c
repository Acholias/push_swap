/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 01:06:24 by lumugot           #+#    #+#             */
/*   Updated: 2025/02/17 01:56:11 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// vérifie si le nombre est dans les bornes du chunk.
int	check_range_number_for_chunk(t_list *stack, int min, int max)
{
	while (stack)
	{
		if (stack->number >= min &&  stack->number < max)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void separate_stack_by_chunks(t_list **stack_a, t_list **stack_b)
{
	int size;
	int chunk_size;
	int *array;
	int min_limit;
	int max_limit;
	int index;
	int chunk_med;

	size = stack_size(*stack_a);
	array = list_to_array(*stack_a, size);
	if (!array)
		return ;
	quicksort(array, 0, size - 1);
	chunk_size = size / CHUNK;
	index = 0;
	while (index < CHUNK)
	{
		if (index == CHUNK - 1)
			max_limit = array[size - 1] + 1;
		else
			max_limit = array[(index + 1) * chunk_size];
		min_limit = array[index * chunk_size];
		chunk_med = array[index * chunk_size + (chunk_size / 2)];
		while (check_range_number_for_chunk(*stack_a, min_limit, max_limit))
		{
			if ((*stack_a)->number >= min_limit && (*stack_a)->number < max_limit)
			{
				if ((*stack_a)->number >= chunk_med)
				{
					push_b(stack_b, stack_a);
					rotate_b(stack_b);
				}
				else
					push_b(stack_b, stack_a);
			}
			else
				rotate_a(stack_a);
		}
		index++;
	}
	free(array);
}

///////////////////////////////////////////////////////////:

#include <stdio.h>
int	find_position_for_target(t_list *stack_b, int value)
{
	t_list	*current;
	int		pos;

	current = stack_b;
	pos = 0;
	while (current)
	{
		if (current->number == value)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}

int find_max(t_list *stack)
{
    t_list  *current;
    int     max;

    if (!stack)
        return (-1);
    current = stack;
    max = current->number;
    while (current)
    {
        if (current->number > max)
            max = current->number;
        current = current->next;
    }
    return max;
}

int find_next_target(t_list *stack_b, t_list *stack_a)
{
    int     max;
    t_list  *current;
    int     best_choice;

    if (!stack_b)
        return (-1);
    if (stack_a)
        max = find_max(stack_a);
    else
        max = find_max(stack_b);
    current = stack_b;
    best_choice = current->number;
    while (current)
    {
        if (current->number < max && current->number > best_choice)
            best_choice = current->number;
        current = current->next;
    }
    return best_choice;
}

void move_target_to_top(t_list **stack_b, int target)
{
    int pos;
    int size_stack_b;

    pos = find_position_for_target(*stack_b, target);
    size_stack_b = stack_size(*stack_b) - 1;
    if (pos == -1)
        return ;
    if (pos <= size_stack_b / 2)
    {
        while ((*stack_b)->number != target)
            rotate_b(stack_b);
    }
    else
    {
        while ((*stack_b)->number != target)
            reverse_rotate_b(stack_b);
    }
}
	
void push_back_to_stack_a(t_list **stack_a, t_list **stack_b)
{
    int target;

    while (*stack_b)
    {
        target = find_next_target(*stack_b, *stack_a);
		printf("target [%d]\n", target);
        move_target_to_top(stack_b, target);
        if ((*stack_a) && (*stack_a)->next && (*stack_a)->next->number == find_max(*stack_a))
        {
            push_a(stack_a, stack_b);
            reverse_rotate_a(stack_a);
        }
        else
        {
            push_a(stack_a, stack_b);
        }
    }
}

void	print_stack(t_list **stack)
{
	t_list *current;
	int		index;

	if (!(*stack))
		printf("\033[1;0;31m is empty !\033[0m\n\n");
	current = *stack;
	index = 0;
	while (current)
	{
		printf("index (%d) number is [%d]\n", index, current->number);
		current = current->next;
		index++;
	}
}

void full_sort_stack(t_list **stack_a, t_list **stack_b)
{
	printf("stack_a :\n");
	print_stack(stack_a);
	printf("\033[1;0;31mstack_b\033[0m");
	print_stack(stack_b);
    separate_stack_by_chunks(stack_a, stack_b);
    printf("\033[1;0;34mSize de stack_a après la séparation en chunks[%d]\033[0m\n", stack_size(*stack_a));
    printf("\033[1;0;34mSize de stack_b après la séparation en chunks[%d]\033[0m\n", stack_size(*stack_b));
	push_back_to_stack_a(stack_a, stack_b);
    printf("\033[1;0;32mstack_a size après le push des valeurs dans stack_a[%d]\033[0m\n", stack_size(*stack_a));
    printf("\033[1;0;32mstack_b size après le push des valeurs dans stack_a[%d]\033[0m\n", stack_size(*stack_b));
	printf("\nstack_a :\n");	
	print_stack(stack_a);
	printf("\033[1;0;31mstack_b\033[0m");
	print_stack(stack_b);
}
