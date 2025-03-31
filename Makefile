# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 16:31:03 by lumugot           #+#    #+#              #
#    Updated: 2025/03/30 15:26:36 by lumugot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

LIBFT_DIR = Libft

LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC = move/double_move.c \
		move/move_bis.c \
		move/move.c \
		parsing/parse_tools.c \
		parsing/clear_memory.c \
		parsing/parse.c \
		sorting/minim_sort.c \
		sorting/sort.c \
		sorting_tools/quicksort.c \
		sorting_tools/sort_chunk.c \
		sorting_tools/sort_parse.c \
		sorting_tools/sort_tools.c \

MAKEFLAGS += -s --no-print-directory

OBJ = $(SRC:.c=.o)

all: $(NAME)
	sleep 1
	@echo "$$BANNER"

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


define BANNER

 _______           _______                _______           _______  _______ 
(  ____ )|\     /|(  ____ \|\     /|     (  ____ \|\     /|(  ___  )(  ____ )
| (    )|| )   ( || (    \/| )   ( |     | (    \/| )   ( || (   ) || (    )|
| (____)|| |   | || (_____ | (___) |     | (_____ | | _ | || (___) || (____)|
|  _____)| |   | |(_____  )|  ___  |     (_____  )| |( )| ||  ___  ||  _____)
| (      | |   | |      ) || (   ) |           ) || || || || (   ) || (      
| )      | (___) |/\____) || )   ( |     /\____) || () () || )   ( || )      
|/       (_______)\_______)|/     \|_____\_______)(_______)|/     \||/       
                                   (_____)                                   

endef
export BANNER