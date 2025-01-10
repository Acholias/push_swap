/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 04:12:13 by lumugot           #+#    #+#             */
/*   Updated: 2025/01/09 16:44:22 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_all_digits(char *str)
{
	int	index;

	index = 0;
	if (!str)
		return (0);
	while (str[index])
	{
		if (!ft_isdigit(str[index]))
			return (0);
		index++;
	}
	return (1);
}

int	check_duplicate(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_strcmp(args[i], args[j]) == 0)
				exit_error();
			j++;
		}
		i++;
	}
	return (0);
}

// int main(int argc, char **argv)
// {
// 	int	count;

// 	count = 1;
//     if (argc < 2)
// 		exit_error();
// 	while (count < argc)
// 	{
// 		if (!check_all_digits(argv[count]))
// 			exit_error();
// 		count++;
// 	}
//     check_duplicate(argv + 1);
//     return 0;
// }