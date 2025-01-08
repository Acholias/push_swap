/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 04:12:13 by lumugot           #+#    #+#             */
/*   Updated: 2025/01/08 04:35:14 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digit_and_sign(t_list *list)
{
	char	*str;
	int		index;
	int		sign_count;

	if (!list)
		return (0);
	str = list->number;
	index = 0;
	sign_count = 0;
	if (str[index] == '-' || str[index] == '+')
	{
		sign_count++;
		index++;
	}
	while (str[index])
	{
		if (str[index] == '-' || str[index] == '+')
			exit_error();
		index++;
	}
	if (sign_count > 1)
		exit_error();
	list = list->next;
	return (0);
}
