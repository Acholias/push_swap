/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:13:38 by lumugot           #+#    #+#             */
/*   Updated: 2024/12/27 17:13:38 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **list_a)
{
	t_list	*first;
	t_list	*last;

	if (!list_a || !(*list_a) || !(*list_a)->next)
		return ;
	first = *list_a;
	*list_a = (*list_a)->next;
	last = *list_a;
	while (last->next)
		last= last->next;
	last->next = first;
	first->next = NULL;
}

void	rotate_b(t_list **list_b)
{
	t_list	*first;
	t_list	*last;

	if (!list_b || !(*list_b) || !(*list_b)->next)
		return ;
	first = *list_b;
	*list_b = (*list_b)->next;
	last = *list_b;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	reverse_rotate_a(t_list **list_a)
{
	t_list	*before_last;
	t_list	*last;

	if (!list_a || !(*list_a) || !(*list_a)->next)
		return ;
	before_last = *list_a;
	while (before_last->next && before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = *list_a;
	*list_a = last;
}

void	reverse_rotate_b(t_list **list_b)
{
	t_list *before_last;
	t_list *last;

	if (!list_b || !(*list_b) || !(*list_b)->next)
		return ;
	before_last = *list_b;
	while (before_last->next && before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = *list_b;
	*list_b = last;
}