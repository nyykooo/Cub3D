/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:04:32 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/06 17:24:37 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

// FIXED POINT MACROS

# define F_BITS 8

// KEY MACROS
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

// SCREEN MACROS
# define SCREEN_WIDTH 700
# define SCREEN_HEIGHT 700
// 640
// 480

// NAME
# define NAME "Cub3D"
# define TITLE "Cub3d brunhenr e ncampbel - 42Lisboa"

// ERROR MACROS
# define ERROR_MSG ft_error_msg_construct
# define ERROR_PRINT ft_put_error_msg
# define ERROR_AC "Error\n Invalid number of arguments\n"
# define ERROR_OPEN "Error\n Unable to open file \""
# define ERROR_EXT "Error\n Invalid file extension for file \""
# define ERROR_READ "Error\n Empty file \""
# define ERROR_MLC "Error\n Memory allocation failed \""
# define ERROR_MAP_EMPTY "Error\n Invalid map: empty line in map content\n"
# define ERROR_MAP_CLOSE "Error\n Invalid map: map not closed\n"
# define ERROR_MAP_CHAR "Error\n Invalid map: invalid character in map\n"
# define ERROR_MAP_ORDER "Error\n Invalid map: map order\n"
# define ERROR_TEXT "Error\n Invalid texture path: \""
# define ERROR_NULL_TEXT "Error\n Missing texture or color\n"
# define ERROR_SPLIT "Error\n Unable to split line\n"
# define ERROR_PLAYER "Error\n Invalid amount of players\n"
# define ERROR_MAP_SIZE "Error\n Invalid map size\n"
# define ERROR_MLX "Error\n Unable to initialize mlx\n"
# define ERROR_WIN "Error\n Unable to create window\n"
# define ERROR_IMG "Error\n Unable to create image\n"
# define ERROR_GDA "Error\n Unable to get data address\n"

// MLX MACROS
# define MLX_NW mlx_new_window
# define MLX_GDA mlx_get_data_addr
# define MLX_PITW mlx_put_image_to_window
# define MLX_XFTI mlx_xpm_file_to_image
# define MLX_NI mlx_new_image

#endif