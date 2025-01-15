/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:03:51 by lumugot           #+#    #+#             */
/*   Updated: 2025/01/15 14:39:53 by lumugot          ###   ########.fr       */
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

void	add_to_stack(t_stack **head, int value)
{
	t_stack	*new_node;
	t_stack	*current;

	new_node = malloc(sizeof(t_stack));
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

void	split_args(char *args, t_stack **stack)
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

t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*stack_a;
	int		index;

	index = 1;
	while (index < argc)
	{
		split_args(argv[index], &stack_a);
		index++;
	}
	return (stack_a);
}

void print_list(t_stack *head)
{
    t_stack *current = head;

    while (current)
	{
    
        int n = current->number;
        char num[12];
        int i = 0;

        if (n == 0)
            num[i++] = '0';
		else
		{
            if (n < 0)
			{
                num[i++] = '-';
                n = -n;
            }
            int temp = n, len = 0;
            while (temp > 0)
			{
                temp /= 10;
                len++;
            }
            for (int j = i + len - 1; n > 0; j--)
			{
                num[j] = (n % 10) + '0';
                n /= 10;
            }
            i += len;
        }
        num[i++] = '\n';
        num[i] = '\0';
        ft_putstr_fd(num, 1);
        current = current->next;
    }
}

int main(int argc, char **argv)
{
	t_stack *stack;

    if (argc > 2)
	{
		stack = init_stack(argc, argv);
		if (check_duplicate(argv))
			free_stack(stack);
		print_list(stack);
    	free_stack(stack);
	}
	else
    	exit_error();
	return (0);
}
