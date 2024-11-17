# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 17:37:50 by ncampbel          #+#    #+#              #
#    Updated: 2024/11/17 12:44:09 by ncampbel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = main

SRC = $(addsuffix .c, $(addprefix src/, $(SRC_DIR)))

LIBFT = "includes/libs/libft/libft.a"

OBJ_SRC_DIR = obj

OBJ = $(SRC:%.c=$(OBJ_SRC_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_SRC_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C includes/libs/libft -s

clean:
	rm -rfd obj
	make -C includes/libs/libft clean -s

fclean: clean
	rm -f $(NAME)
	make -C includes/libs/libft fclean -s

re: fclean all

.PHONY: all clean fclean re

.SILENT: