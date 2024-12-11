/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:39:51 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/11 15:19:01 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "headers.h"

typedef struct s_fixed
{
	const int	bits;
	int			fixed_point;
	int			(*to_int)(void);
	float		(*to_float)(void);
	int			(*get_raw_bits)(void);
	void		(*set_raw_bits)(int const raw);
}	t_fixed;
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

typedef struct s_texture
{
	t_color	*ceiling;
	t_color	*floor;
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		untex;
}	t_texture;

typedef struct s_map
{
	t_player		*player;
	t_texture		*texture;
	void			*black_img;
	void			*white_img;
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
}	t_cub;

#endif