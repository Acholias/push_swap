/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 04:11:56 by lumugot           #+#    #+#             */
/*   Updated: 2025/01/27 17:37:24 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (1);
}


long	ft_atol(char *str)
{
	long	number;
	int		index;
	int		sign;

	if (!str)
		return (0);
	number = 0;
	index = 0;
	sign = 1;
	while ((str[index] >= 9 && str[index] <= 13) || str[index] == 32)
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		number = number * 10 + str[index] - '0';
		index++;
	}
	if (str[index] == '-' || str[index] == '+' || ft_isalpha(str[index]))
		exit_error();
	return (number * sign);
}

int safe_atol_to_int(char *str)
{
    long	result;

	result = ft_atol(str);
    if (result > INT_MAX || result < INT_MIN)
        exit_error();
    return ((int)result);
}

void	free_split(char **split)
{
	int	index;

	index = 0;
	while (split[index])
	{
		free(split[index]);
		index++;
	}
	free(split);
}

void free_stack(t_list *stack)
{
    t_list *tmp;
    while (stack)
	{
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
}
