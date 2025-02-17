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

void	double_swap(t_list **stack_a, t_list **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	ft_putendl_fd("ss", 1);
}


void	double_rotate(t_list **stack_a, t_list **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	ft_putendl_fd("rr", 1);
}

void	double_reverse_rotate(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
	ft_putendl_fd("rrr", 1);
}
