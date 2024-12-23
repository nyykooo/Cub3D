/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:39:51 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/23 17:38:03 by brunhenr         ###   ########.fr       */
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

// ------ sprite study --------


typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;	
	int		height;	
}		t_win;

typedef struct s_image
{
	t_win	win;
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}		t_image;


enum entity {
	PLAYER,
	ENEMY,
	EVENT,
	OBJ,
};

typedef struct s_animation {
	t_list *	frames;
	int		width;
	int		height;
	int		delay;			// How many fps it takes to change animation
	int		_tmp_delay;		// Delay Iterator
	int		current_frame_num;	// Which frame is selected
	long int	last_updated;		// When was the last update
	long int	frame_count;		// The frame count
	enum entity	entity;
}		t_animation;


typedef struct s_sprite {
	t_list	* animations;
	char	* name;
	char	* file_path;
	t_image	sprite_img;
	int	width;
	int	height;
	int	z_index;
}		t_sprite;

typedef	struct sprite_slice {
	int x;
	int y;
	int width;
	int height;
}	sprite_slice;

// ----------------------
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
	int		hit;
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
	t_ray		*ray; // Agora o player tem um ray para emitir um raio para verificar a distância até a parede
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
	t_wall	*door;
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
	double			frame_time;
	double			move_speed;
	double			rot_speed;
}	t_frametime;

typedef struct s_keys
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	e;
	bool	c;
	bool	left;
	bool	right;
	bool	esc;
}	t_keys;

typedef struct s_cub
{
	t_map		*map;
	void		*mlx_ptr;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	int			mouse_x;
	int			mouse_y;
	char		*file;
	char		*line;
	int			fd;
	t_frametime	frameTime;
	t_keys		keys;
}	t_cub;

typedef struct	s_column
{
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			tex_x;
	int			*buffer;
}	t_column;

#endif