/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:39:51 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/11 15:10:55 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "headers.h"


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

typedef struct s_player
{
	char	p_dir;
	int		p_x;
	int		p_y;
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