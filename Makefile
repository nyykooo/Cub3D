# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 17:37:50 by ncampbel          #+#    #+#              #
#    Updated: 2024/12/02 16:41:46 by ncampbel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -o3

SRC_DIR = main

SRC_CUB_DIR = cub texture color

SRC_CUB_MAP_DIR = map player

SRC_CUB_MLX_DIR = mlx hooks image

SRC_ERROR_DIR = error

SRC_PARSE_DIR = parse

SRC_PARSE_MAP_DIR = map floodfill color

SRC_FREE_DIR = free

SRC_PRINT_DIR = print

SRC = $(addsuffix .c, $(addprefix src/, $(SRC_DIR))) \
	$(addsuffix .c, $(addprefix src/error/, $(SRC_ERROR_DIR))) \
	$(addsuffix .c, $(addprefix src/parse/, $(SRC_PARSE_DIR))) \
	$(addsuffix .c, $(addprefix src/parse/map/, $(SRC_PARSE_MAP_DIR))) \
	$(addsuffix .c, $(addprefix src/free/, $(SRC_FREE_DIR))) \
	$(addsuffix .c, $(addprefix src/cub/, $(SRC_CUB_DIR))) \
	$(addsuffix .c, $(addprefix src/cub/map/, $(SRC_CUB_MAP_DIR))) \
	$(addsuffix .c, $(addprefix src/cub/mlx/, $(SRC_CUB_MLX_DIR))) \
	$(addsuffix .c, $(addprefix src/print/, $(SRC_PRINT_DIR)))

LIBFT = includes/libs/libft/libft.a
GNL = includes/libs/get_next_line/get_next_line.a
MLX = includes/libs/mlx-linux/libmlx.a -lXext -lX11

OBJ_SRC_DIR = obj

OBJ = $(SRC:%.c=$(OBJ_SRC_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ) $(MLX) $(LIBFT) $(GNL)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(GNL) $(MLX) -lm -o $(NAME)

$(OBJ_SRC_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C includes/libs/libft -s
	
$(GNL):
	$(MAKE) -C includes/libs/get_next_line -s	
	
$(MLX):
	$(MAKE) -C includes/libs/mlx-linux -s

clean:
	rm -rfd $(OBJ_SRC_DIR)
	$(MAKE) clean -C includes/libs/libft clean -s
	$(MAKE) clean -C includes/libs/get_next_line -s
	$(MAKE) clean -C includes/libs/mlx-linux -s

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C includes/libs/libft fclean -s
	$(MAKE) fclean -C includes/libs/get_next_line -s
	$(MAKE) clean -C includes/libs/mlx-linux -s

re: fclean all

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) includes/maps/minimalist.cub

.PHONY: all clean fclean re
