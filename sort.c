/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 01:06:24 by lumugot           #+#    #+#             */
/*   Updated: 2025/02/21 16:18:03 by lumugot          ###   ########.fr       */
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

//Fonction pour trouver la valeur max de la stack_b ainsi que sont index pour facilité la recherche
void	search_max_number_and_index(t_list **stack_b, int *max_index, int *max_number)
{
	t_list *current;
	int		index;

	if (!(*stack_b))
		return ;
	current = *stack_b;	
	*max_number = current->number;
	*max_index = 0;
	index = 0;
	while (current)
	{
		if (current->number > *max_number)
		{
			*max_number = current->number;
			*max_index = index;
		}
		current = current->next;
		index++;
	}
}

//Fonction qui va prendre la plus grosse valeur de la stack_b pour la mettre en haut de la stack_b,
// Pour ensuite l'envoyer dans la stack_a

void	push_to_stack_a(t_list **stack_a, t_list **stack_b)
{
	int	max_index;
	int	max_number;
	int	size;	

	while (*stack_b)
	{
		search_max_number_and_index(stack_b, &max_index, &max_number);
		size = stack_size(*stack_b);
		if (max_index <= size / 2)
		{
			while (max_index-- > 0)
				rotate_b(stack_b);
		}
		else
		{
			max_index = size - max_index;
			while (max_index-- > 0)
				reverse_rotate_b(stack_b);
		}
		push_a(stack_a, stack_b);
	}
}

///////////////////// FONCTION DE DEBUG //////////////////////

#include <stdio.h>

#define RESET   "\x1b[0m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1b[37m"

void	print_stack(t_list **stack)
{
	t_list *current;

	current = *stack;
	if (!(*stack))
		printf("Stack is empty\n");
	while (current)
	{
		printf("[%d]\n", current->number);
		current = current->next;
	}
}

//////////////////////////////////////////////////////////////

void full_sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (!check_sorted(*stack_a))
	{
		printf("La liste n'est pas correctement triée 👎\n");
		print_stack(stack_a);
		printf("\n\n");
	}
	separate_stack_by_chunks(stack_a, stack_b);
	push_to_stack_a(stack_a, stack_b);
	if (check_sorted(*stack_a))
	{
		printf(CYAN "\n\nLa liste est correctement triée 👍\n ");
		print_stack(stack_a);
		printf(RESET);
	}
}
