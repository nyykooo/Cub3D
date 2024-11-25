/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:39:51 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/25 18:28:37 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "headers.h"

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	char	*ceiling;
	char	*floor;
}	t_texture;

typedef struct s_map
{
	t_texture	*texture;
	char		**map;
	char		*path;
	int			rows;
	int			cols;
}	t_map;

typedef struct s_cub
{
	t_map	*map;
	char	*file;
	char 	*line;
	int		fd;
}	t_cub;

#endif