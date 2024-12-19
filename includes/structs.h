/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:39:51 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/18 19:20:59 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "headers.h"
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_image
{
	void	*img;
	int		**tex;
	char	*path;
	int		width;
	int		height;
}	t_image;

typedef struct s_sprite
{
	t_image	*sprite_sheet;
	int		frame_w;
	int		frame_h;
	int		num_frames;
	int		cur_frame;
	long	frame_time;
	long	last_frame_time;
} t_sprite;

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
	t_dirVector	*dirVector;
	t_dirVector	*camVector;
	t_image		*sword;
	t_sprite	*attack;
	double		p_y;
	double		p_x;
	char		p_dir;
	bool		is_attacking;
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
	t_image	*north;
	t_image	*south;
	t_image	*east;
	t_image	*west;
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

typedef struct s_frametime
{
	struct timeval	start;
	struct timeval	end;
	double	frame_time;
	double	move_speed;
	double	rot_speed;
}	t_frametime;

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
	int		mouse_x;
	int		mouse_y;
	char	*file;
	char	*line;
	int		fd;
	t_frametime	frameTime;
}	t_cub;


#endif