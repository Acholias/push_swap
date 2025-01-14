/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:13:49 by lumugot           #+#    #+#             */
/*   Updated: 2024/12/27 17:13:49 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	swap_a(t_list **list_a)
{
	t_list	*first;
	t_list	*second;

	if (!list_a || !(*list_a) || !(*list_a)->next)
		return ;
	first = *list_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*list_a = second;
	ft_putstr_fd("sa", 1);
}

void	swap_b(t_list **list_b)
{
	t_list	*first;
	t_list	*second;

	if (!list_b || !(*list_b) || !(*list_b)->next)
		return ;
	first = *list_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*list_b = second;
	ft_putstr_fd("sb", 1);
}

void	push_a(t_list **list_a, t_list **list_b)
{
	t_list	*temp;

	if (!list_b || !(*list_b))
		return ;
	temp = *list_b;
	*list_b = (*list_b)->next;
	temp->next = *list_a;
	*list_a = temp;
	ft_putstr_fd("pa", 1);
}

void	push_b(t_list **list_b, t_list **list_a)
{
	t_list	*temp;

	if (!list_a || !(*list_a))
		return ;
	temp = *list_a;
	*list_a = (*list_a)->next;
	temp->next = *list_b;
	*list_b = temp;
	ft_putstr_fd("pb", 1);
}