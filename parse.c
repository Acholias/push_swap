/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:03:51 by lumugot           #+#    #+#             */
/*   Updated: 2025/01/15 00:51:50 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(char **str)
{
	int	data_ref;
	int	data;
	int	value;
	int	value_ref;

	if (!str)
		exit_error();
	data_ref = 0;
	while (str[data_ref])
	{
		value_ref = safe_atol_to_int(str[data_ref]);
		data = data_ref + 1;
		while (str[data])
		{
			value = safe_atol_to_int(str[data]);
			if (value_ref == value)
				exit_error();
			data++;
		}
		data_ref++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		exit_error();
	check_duplicate(argv);
	return (0);
}
