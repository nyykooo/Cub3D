# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 17:37:50 by ncampbel          #+#    #+#              #
#    Updated: 2024/11/25 22:43:38 by ncampbel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = main

SRC_CUB_DIR = cub texture
SRC_CUB_MAP_DIR = map

SRC_ERROR_DIR = error

SRC_PARSE_DIR = parse map

SRC_FREE_DIR = free

SRC_PRINT_DIR = print

SRC = $(addsuffix .c, $(addprefix src/, $(SRC_DIR))) \
	$(addsuffix .c, $(addprefix src/error/, $(SRC_ERROR_DIR))) \
	$(addsuffix .c, $(addprefix src/parse/, $(SRC_PARSE_DIR))) \
	$(addsuffix .c, $(addprefix src/free/, $(SRC_FREE_DIR))) \
	$(addsuffix .c, $(addprefix src/cub/, $(SRC_CUB_DIR))) \
	$(addsuffix .c, $(addprefix src/cub/map/, $(SRC_CUB_MAP_DIR))) \
	$(addsuffix .c, $(addprefix src/print/, $(SRC_PRINT_DIR)))

LIBFT = "includes/libs/libft/libft.a"
GNL = "includes/libs/get_next_line/get_next_line.a"

OBJ_SRC_DIR = obj

OBJ = $(SRC:%.c=$(OBJ_SRC_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(GNL)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(GNL) -o $(NAME)

$(OBJ_SRC_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C includes/libs/libft -s
	
$(GNL):
	make -C includes/libs/get_next_line -s

clean:
	rm -rfd $(OBJ_SRC_DIR)
	make clean -C includes/libs/libft clean -s
	make clean -C includes/libs/get_next_line -s

fclean: clean
	rm -f $(NAME)
	make fclean -C includes/libs/libft fclean -s
	make fclean -C includes/libs/get_next_line -s

re: fclean all

.PHONY: all clean fclean re
