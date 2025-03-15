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

typedef struct s_chunk
{
	int	min;
	int	max;
	int	max_n;
	int	max_i;
	int	size;
	int	flag;
	int	median;
	int	count;
}	t_chunk;

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
int		find_min_value(t_list *stack_a);
int		select_sort(t_list **stack_a, t_list **list_b);

//mapping.c
void	mapping_stack(t_list *stack);

//minim_sort.c
int		find_position(t_list *stack, int value);
void	sort_2_values(t_list **stack_a);
void	sort_3_values(t_list **stack_a);
void	sort_4_values(t_list **stack_a, t_list **stack_b);
void	sort_5_values(t_list **stack_a, t_list **stack_b);

//quicksort.c
void	swap_value(int *a, int *b);
int		partitions(int *tab, int start, int end);
void	quicksort(int *tab, int start, int end);
int		calculate_median(int *stack, int size);
int		*list_to_array(t_list *stack, int size);

//sort_chunk.c
void	init_chunk_limits(t_chunk *chunk, int *array, int index, int size);
int		check_range_number_for_chunk(t_list *stack, int min, int max);
void	push_to_stack_b(t_list **stack_a, t_list **stack_b, t_chunk *chunk);
void	process_chunks(t_list **stack_a, t_list **stack_b, int *array, int len);
void	separate_stack_by_chunk(t_list **stack_a, t_list **stack_b);

//sort_tools.c
void	search_max_and_index(t_list **stack_b, int *max_i, int *max_n);
void	handle_first_half(t_list **stack_a, t_list **stack_b, t_chunk *data);
void	handle_second_half(t_list **stack_a, t_list **stack_b, t_chunk *data);

//sort.c
int		define_number_of_chunk(t_chunk *chunk, int size);
void	search_max_and_index(t_list **stack_b, int *max_i, int *max_n);
void	push_to_stack_a(t_list **stack_a, t_list **stack_b);
void	full_sort_stack(t_list **stack_a, t_list **stack_b);

#endif