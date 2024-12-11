/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:00:05 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/11 15:17:57 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "headers.h"

// UTILS FUNCTIONS
double		ft_deg_to_rad(double deg);
bool		ft_is_walkable(char c);
bool		are_vectors_perpendicular(t_dirVector *dirVector, t_dirVector *camVector);
void	normalize_vector(t_dirVector *vector);


// FREE FUNCTIONS
void		ft_clear_cub(void);

// ERROR FUNCTIONS
char		*ft_error_msg_construct(int nbr, ...);
int			ft_put_error_msg(char *error_msg, int exit_status);

// PARSE FUNCTIONS
void		ft_input_parse(char **av, int ac);	
void		ft_input_validation(char **av, int ac);
void		ft_parse_texture(t_cub *cub);
void		ft_parse_color(t_cub *cub, char *line);
void		ft_normalize_map(t_cub *cub);

// CUB FUNCTIONS
t_cub		*ft_get_cub(void);
t_cub		*ft_init_cub(void);

// TEXTURE FUNCTIONS
t_texture	*ft_init_texture(void);
bool		ft_get_text_color(t_map *map, char **split);
bool		ft_is_text_or_color(char *line, t_cub *cub);

// MAP FUNCTIONS
void		ft_init_map(t_cub *cub);
void		ft_alloc_map(t_cub *cub);
void		ft_print_map(t_map *map);
void		ft_get_map_textures(t_map *map, char *line);
void		ft_trim_map(t_cub *cub);
void		ft_look_for_invalid_map(t_cub *cub);

// FLOODFILL FUNCTIONS
void		ft_call_flood(t_map *map);

// COLOR FUNCTIONS
t_color		*ft_init_color(void);
int			ft_create_rgb(int r, int g, int b);

// PLAYER FUNCTIONS
t_player	*ft_init_player(void);
void		ft_check_player(t_map *map);

// MLX FUNCTIONS
void		ft_init_mlx(t_cub *cub);
void		ft_mlx_hook_and_loop(t_cub *cub);

// MLX HOOKS
int			ft_close_x(t_cub *cub);
int			ft_game_keys(int keycode, t_cub *cub);
void		ft_mlx_inicialization(t_cub *cub);
void		ft_mlx_getdata_and_loop(t_cub *cub);
void		ft_my_mlx_pixel_put(t_cub *cub, int x, int y, int color);
int			ft_ray_casting(t_cub *cub);

// MLX UTILS
void		clear_image(t_cub *cub, int color);
void		ft_draw_vertical_line(int x, int drawStart, int drawEnd, t_cub *cub);

// MLX HOOKS
int			ft_close_x(t_cub *cub);
int			ft_keys(int keycode, t_cub *cub);

// KEYS
void		ft_rotate_left(t_player *player);
void		ft_rotate_right(t_player *player);
void		ft_move_forward(t_cub *cub);

// MLX IMAGE FUNCTIONS
void		ft_image_hub(t_cub *cub);

// MOVE FUNCTIONS
void		ft_move_player(int keycode, t_cub *cub);

#endif