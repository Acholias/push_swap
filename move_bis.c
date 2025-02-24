/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:05:57 by lumugot           #+#    #+#             */
/*   Updated: 2025/01/19 12:05:57 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **stack_a)
{
	t_list	*first;
	t_list	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	last = ft_lstlast(*stack_a);
	*stack_a = first->next;
	last->next = first;
	first->next = NULL;
	ft_putendl_fd("ra", 1);
}

void	rotate_b(t_list **stack_b)
{
	t_list	*first;
	t_list	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	last = ft_lstlast(*stack_b);
	*stack_b = first->next;
	last->next = first;
	first->next = NULL;
	ft_putendl_fd("rb", 1);
}

void	reverse_rotate_a(t_list **stack_a)
{
	t_list	*last;
	t_list	*before_last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	last = *stack_a;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	ft_putendl_fd("rra", 1);
}

void	reverse_rotate_b(t_list **stack_b)
{
	t_list	*last;
	t_list	*before_last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	last = *stack_b;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	ft_putendl_fd("rrb", 1);
}
