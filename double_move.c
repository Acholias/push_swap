/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:13:44 by lumugot           #+#    #+#             */
/*   Updated: 2024/12/27 17:13:44 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_swap(t_list **list_a, t_list **list_b)
{
	swap_a(list_a);
	swap_b(list_b);
	ft_putstr_fd("ss", 1);
}


void	double_rotate(t_list **list_a, t_list **list_b)
{
	rotate_a(list_a);
	rotate_b(list_b);
	ft_putstr_fd("rr", 1);
}

void	double_reverse_rotate(t_list **list_a, t_list **list_b)
{
	reverse_rotate_a(list_a);
	reverse_rotate_b(list_b);
	ft_putstr_fd("rrr", 1);
}