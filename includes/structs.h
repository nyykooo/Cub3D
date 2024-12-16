/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:39:51 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/16 22:33:04 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "headers.h"
# include "macros.h"

typedef struct s_ray
{
	double	dirX;
	double	dirY;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	int		stepX;
	int		stepY;
	int		side;
}	t_ray;

typedef struct s_dirVector
{
	double	x;
	double	y;
}	t_dirVector;

typedef struct s_player
{
	char		p_dir;
	double		p_x;
	double		p_y;
	t_dirVector	*dirVector;
	t_dirVector	*camVector;
}	t_player;

typedef struct s_color
{
	char	*input;
	int		color;
	int		red;
	int		green;
	int		blue;
}	t_color;

typedef struct s_wall
{
	char	*path;
	int		**tex;
	void	*img;
}	t_wall;

typedef struct s_texture
{
	t_color	*ceiling;
	t_color	*floor;
	t_wall	*north;
	t_wall	*south;
	t_wall	*east;
	t_wall	*west;
}	t_texture;

typedef struct s_map
{
	t_player		*player;
	t_texture		*texture;
	char			**map;
	char			**ff_map;
	char			*path;
	unsigned int	rows;
	unsigned int	cols;
}	t_map;

typedef struct s_cub
{
	t_map	*map;
	void	*mlx_ptr;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_lenght;
	int		endian;
	char	*file;
	char	*line;
	int		fd;
	double	time;
	double	old_time;
	double	frame_time;
	double	move_speed;
	double	rot_speed;
}	t_cub;

#endif