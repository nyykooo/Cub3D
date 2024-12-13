/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:04:32 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/13 17:12:24 by ncampbel         ###   ########.fr       */
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

// NUMBER MACROS
//# define ROTATION_ANGLE 0.2
# define PI 3.14159265358979323846

// EVENT MASKS
# define KeyPressMask        (1L<<0) // 1L (o L é para long)
# define KeyReleaseMask      (1L<<1) // 2L
# define ButtonPressMask     (1L<<2) // 4L
# define ButtonReleaseMask   (1L<<3) // 8L
# define PointerMotionMask   (1L<<6) // 64L
# define PointerMotionHintMask (1L<<7) // 128L
# define ExposureMask        (1L<<15) // 32768L
# define StructureNotifyMask (1L<<17) // 131072L

// SCREEN MACROS
# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480

// TEXTURE MACROS
# define TEX_WIDTH 32
# define TEX_HEIGHT 32

// COLORS
# define Red 0xFF0000
# define Green 0x00FF00
# define Blue 0x0000FF
# define White 0xFFFFFF
# define Cyan 0x00FFFF

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
# define ERROR_VECTORS "Error\n The vectors are not perpendicular.\n"

// MLX MACROS
# define MLX_NW mlx_new_window
# define MLX_GDA mlx_get_data_addr
# define MLX_PITW mlx_put_image_to_window
# define MLX_XFTI mlx_xpm_file_to_image
# define MLX_NI mlx_new_image

#endif