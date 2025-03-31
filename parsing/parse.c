/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:03:51 by lumugot           #+#    #+#             */
/*   Updated: 2025/03/31 21:29:16 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

static int	check_duplicate(char **str)
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
				return (1);
			data++;
		}
		data_ref++;
	}
	return (0);
}

static void	add_to_stack(t_list **head, int value)
{
	t_list	*new_node;
	t_list	*current;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		exit_error ();
	new_node->number = value;
	new_node->next = NULL;
	new_node->rank = -1;
	if (!*head)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
}

int	check_arg_lenght(char *arg)
{
	return (ft_strlen(arg) > 11);
}

static void	split_args(char *args, t_list **stack)
{
	char	**split;
	int		index;
	long	value;

	if (!stack && !(*stack))
		exit_error();
	split = ft_split(args, ' ');
	if (!split)
		exit_error();
	if (check_duplicate(split) == 1)
	{
		free_split(split);
		exit_error();
	}
	index = 0;
	value = 0;
	while (split[index])
	{
		value = safe_atol_to_int(split[index]);
		if (check_arg_lenght(split[index]) || value > INT_MAX || value < INT_MIN)
			free_all(split, *stack);
		add_to_stack(stack, value);
		index++;
	}
	free_split(split);
}

static t_list	*init_list(int argc, char **argv)
{
	t_list	*stack_a;
	int		index;

	stack_a = NULL;
	index = 1;
	if (check_duplicate(argv + 1) == 1)
	{
		free(stack_a);
		exit_error();
	}
	while (index < argc)
	{
		split_args(argv[index], &stack_a);
		index++;
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1)
		return (0);
	if (argc >= 2)
	{
		stack_b = NULL;
		stack_a = init_list(argc, argv);
		check_stack(stack_a);
		if (check_sorted(stack_a))
		{
			free_stack(stack_a);
			free_stack(stack_b);
			return (0);
		}
		select_sort(&stack_a, &stack_b);
		free_stack(stack_a);
		free_stack(stack_b);
	}
	else
		exit_error();
	return (0);
}
