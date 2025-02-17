/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:14:27 by lumugot           #+#    #+#             */
/*   Updated: 2024/12/27 17:14:27 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "Libft/libft.h"

#define CHUNK 2

//move.c
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	double_swap(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_b, t_list **stack_a);

// move_bis.c
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	reverse_rotate_a(t_list **stack_a);
void	reverse_rotate_b(t_list **stack_b);

//double_move.c
void	double_rotate(t_list **stack_a, t_list **stack_b);
void	double_reverse_rotate(t_list **stack_a, t_list **stack_b);

// tools.c
int		exit_error(void);
long	ft_atol(char *str);
int		safe_atol_to_int(char *str);
void	free_split(char **split);
void	free_stack(t_list *stack);

// tools_bis.c 
int		stack_size(t_list *stack);
int		check_sorted(t_list *stack);
int 	find_min_value(t_list *stack_a);
int		select_sort(t_list **stack_a, t_list **list_b);

//minim_sort.c
int		find_position(t_list *stack, int value);
void	sort_2_values(t_list **stack_a);
void	sort_3_values(t_list **stack_a);
void	sort_4_values(t_list **stack_a, t_list **stack_b);
void	sort_5_values(t_list **stack_a, t_list **stack_b);

//quicksort.c
void swap_value(int *a, int *b);
int partitions(int *tab, int start, int end);
void quicksort(int *tab, int start, int end);
int	calculate_median(int *stack, int size);
int	*list_to_array(t_list *stack, int size);

//sort.c
int		calculate_median_to_stack(t_list *stack, int size);
void	full_sort_stack(t_list **stack_a , t_list **stack_b);

#endif