# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 16:31:03 by lumugot           #+#    #+#              #
#    Updated: 2025/03/15 17:51:22 by lumugot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT_DIR = Libft

LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC = parse.c \
		tools.c \
		tools_bis.c \
		move.c \
		move_bis.c \
		double_move.c \
		minim_sort.c \
		quicksort.c \
		sort_chunk.c \
		sort_tools.c \
		sort.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
