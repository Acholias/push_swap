/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:03:51 by lumugot           #+#    #+#             */
/*   Updated: 2025/02/21 16:12:40 by lumugot          ###   ########.fr       */
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
				return (1);
			data++;
		}
		data_ref++;
	}
	return (0);
}

void	add_to_stack(t_list **head, int value)
{
	t_list	*new_node;
	t_list	*current;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		exit_error ();
	new_node->number = value;
	new_node->next = NULL;
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

void	split_args(char *args, t_list **stack)
{
	char	**split;
	int		index;
	int		value;

	if (!stack)
		exit_error();
	split = ft_split(args, ' ');
	if (!split)
		exit_error ();
	index = 0;
	while (split[index])
	{
		value = safe_atol_to_int(split[index]);
		add_to_stack(stack, value);
		index++;
	}
	free_split(split);
}

t_list	*init_list(int argc, char **argv)
{
	t_list	*stack_a;
	int		index;

	stack_a = NULL;
	index = 1;
	if (check_duplicate(argv) == 1)
		exit_error();
	while (index < argc)
	{
		split_args(argv[index], &stack_a);
		index++;
	}
	return (stack_a);
}

int main(int argc, char **argv)
{
    t_list *stack_a;
    t_list *stack_b;

    if (argc >= 2)
    {
        stack_b = NULL;
        stack_a = init_list(argc, argv);
		if (check_sorted(stack_a))
			return (0);
        select_sort(&stack_a, &stack_b);
        free_stack(stack_a);
        free_stack(stack_b);
    }
    else
        exit_error();
    return (0);
}
