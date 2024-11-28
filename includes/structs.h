/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:39:51 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/28 19:30:08 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "headers.h"

typedef struct s_color
{
	char	*input;
	int		color;
	int		red;
	int		green;
	int		blue;
}	t_color;

typedef struct s_texture
{
	t_color	*ceiling;
	t_color	*floor;
	char	*north;
	char	*south;
	char	*east;
	char	*west;
}	t_texture;

typedef struct s_map
{
	t_texture	*texture;
	char		**map;
	char		**ff_map;
	char		*path;
	int			rows;
	int			cols;
}	t_map;

typedef struct s_cub
{
	t_map	*map;
	char	*file;
	char	*line;
	int		fd;
}	t_cub;

#endif