# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 16:31:03 by lumugot           #+#    #+#              #
#    Updated: 2025/03/27 18:32:42 by lumugot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT_DIR = Libft

LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC = move/double_move.c \
		move/move_bis.c \
		move/move.c \
		parsing/parse_tools.c \
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
	@i=0; while [ $$i -lt 50 ]; do \
		RED=$$(($$i * 255 / 50)); \
		GREEN=$$((255 - $$RED)); \
		printf "\033[48;2;$$GREEN;$$RED;0m \033[0m"; \
		i=$$(($$i + 1)); \
		sleep 0.05; \
	done; \
	echo " "
	sleep 1;
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