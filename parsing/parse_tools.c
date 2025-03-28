/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 04:11:56 by lumugot           #+#    #+#             */
/*   Updated: 2025/03/28 13:40:48 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int	exit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

long	ft_atol(char *str, int sign)
{
	long	number;
	int		index;

	number = 0;
	index = 0;
	if ((str[index] == '+' || str[index] == '-') && str[index + 1] == '\0')
		return (LONG_MAX);
	while ((str[index] >= 9 && str[index] <= 13) || str[index] == 32)
		index++;
	if ((str[index] == '+' || str[index] == '-') && ft_isdigit(str[index + 1]))
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
	if (number < 0 || str[index] == '-' || str[index] == '+' || \
			ft_isalpha(str[index]))
		return (LONG_MAX);
	return (number * sign);
}

int	safe_atol_to_int(char *str)
{
	long	result;
	char	*str_bis;
	int		index;

	str_bis = ft_strtrim(str, " ");
	if (ft_strlen(str_bis) == 0)
	{
		free (str_bis);
		exit_error();
	}
	result = ft_atol(str_bis, 1);
	index = -1;
	while (str[++index])
	{
		if (str[index] == '-' || str[index] == '+')
		{
			index++;
			if (!ft_isdigit(str[index]))
			{
				free(str_bis);
				exit_error();
			}
		}
	}
	if (result > INT_MAX || result < INT_MIN)
	{
		free(str_bis);
		exit_error();
	}
	free (str_bis);
	return ((int)result);
}
