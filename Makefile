# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 16:31:03 by lumugot           #+#    #+#              #
#    Updated: 2025/01/09 16:42:55 by lumugot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT_DIR = Libft

LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = parse.c \
		tools.c \
		
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