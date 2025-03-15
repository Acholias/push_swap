/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 04:11:56 by lumugot           #+#    #+#             */
/*   Updated: 2025/03/13 11:03:50 by lumugot          ###   ########.fr       */
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

	number = 0;
	index = 0;
	sign = 1;
	if (str[index] == '-' && str[index + 1])
	{
		sign = -1;
		index++;
	}
	while ((str[index] >= 9 && str[index] <= 13) || str[index] == 32)
		index++;
	while (str[index] >= '0' && str[index] <= '9')
	{
		number = number * 10 + str[index] - '0';
		index++;
	}
	if (str[index] == '-' || str[index] == '+' || ft_isalpha(str[index]))
		exit_error();
	return (number * sign);
}

int	safe_atol_to_int(char *str)
{
	long	result;
	char	*str_bis;

	str_bis = ft_strtrim(str, " ");
	if (ft_strlen(str_bis) == 0)
	{
		free (str_bis);
		exit_error();
	}
	result = ft_atol(str_bis);
	if (result > INT_MAX || result < INT_MIN)
		exit_error();
	free (str_bis);
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

void	free_stack(t_list *stack)
{
	t_list	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
