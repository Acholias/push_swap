/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 01:06:24 by lumugot           #+#    #+#             */
/*   Updated: 2025/03/31 21:14:29 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

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
	if (size > 500)
		chunk->count = 10;
	return (chunk->count);
}

void	full_sort_stack(t_list **stack_a, t_list **stack_b)
{
	separate_stack_by_chunk(stack_a, stack_b);
	push_to_stack_a(stack_a, stack_b);
}
