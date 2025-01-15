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

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
}	t_stack;

void	swap_a(t_list **list_a);
void	swap_b(t_list **list_b);
void	double_swap(t_list **list_a, t_list **list_b);
void	push_a(t_list **list_a, t_list **list_b);
void	push_b(t_list **list_b, t_list **list_a);
void	double_push(t_list **list_a, t_list **list_b);
void	rotate_a(t_list **list_a);
void	rotate_b(t_list **list_b);
void	double_rotate(t_list **list_a, t_list **list_b);
void	reverse_rotate_a(t_list **list_a);
void	reverse_rotate_b(t_list **list_b);

int		exit_error(void);
long	ft_atol(char *str);
int		safe_atol_to_int(char *str);
void	free_split(char **split);
void	free_stack(t_stack *stack);


//Voir pour mon histoire de moyenne sur chaque moitie de la pile pour 
//l'initialiser a l'endroit ou a l'enver dans la pile (gain de mouve ?)
//La fonction qui va initialiser la pile dans ma liste chainee soit ma stack_a
//Sera donc sois a l'endrois soit a l'envers je pense que je peu gagner quelque mouvements
#endif