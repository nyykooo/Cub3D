/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:00:05 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/23 11:25:21 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "headers.h"

// RAY CASTING
int			ft_ray_casting(t_cub *cub);
void		ft_draw_column(t_cub *cub, int x, t_player *player);
void		ft_fill_buffer(t_column *column, t_ray *ray, t_cub *cub);

// COLLISION 
int			ft_collision(t_map *map, t_cub *cub);
int			ft_collision_dda(t_player *player, t_cub *cub);
void		ft_collision_dists(t_player *player);
void		ft_prepare_vec(double angle, t_dirVector *dir_vector, t_cub *cub);

// DRAW UTILS
void		calculate_delta_distances(t_ray *ray);
void		calculate_ray_direction(int x, t_ray *ray, t_player *player);
void		calculate_initial_distances(t_player *player, t_ray *ray);
void		perform_dda(t_cub *cub, t_ray *ray);

// UTILS FUNCTIONS
void		ft_rotate_vect(double angle, t_dirVector *vector);
double		ft_deg_to_rad(double deg);
bool		ft_is_walkable(char c);
bool		ft_perpendicular_vect(t_dirVector *dirVector, \
t_dirVector *camVector);

// FREE FUNCTIONS
void		ft_clear_cub(void);

// ERROR FUNCTIONS
char		*ft_error_msg_construct(int nbr, ...);
int			ft_put_error_msg(char *error_msg, int exit_status);

// PARSE FUNCTIONS
void		ft_input_parse(char **av, int ac);	
void		ft_input_validation(char **av, int ac);
void		ft_parse_texture(void);
void		ft_parse_color(t_cub *cub, char *line);
void		ft_normalize_map(t_cub *cub);

// CUB FUNCTIONS
t_cub		*ft_get_cub(void);
t_cub		*ft_init_cub(void);

// TEXTURE FUNCTIONS
t_texture	*ft_init_texture(void);
bool		ft_get_text_color(t_map *map, char **split);
bool		ft_is_text_or_color(char *line, t_cub *cub);
void		ft_get_tex_imgs(t_cub *cub, t_texture *texture);

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
int			ft_keys(t_cub *cub);
int			ft_game_keys(int keycode, t_cub *cub);
void		ft_mlx_inicialization(t_cub *cub);
void		ft_mlx_getdata_and_loop(t_cub *cub);
void		ft_my_mlx_pixel_put(t_cub *cub, int x, int y, int color);
int			ft_ray_casting(t_cub *cub);
int			ft_mouse(int x, int y, t_cub *cub);
int			ft_key_press(int keycode, t_cub *cub);
int			ft_key_release(int keycode, t_cub *cub);

// MLX UTILS
void		clear_image(t_cub *cub, int color);
void		ft_draw_vertical_line(int x, t_column *column, t_cub *cub);
int			**ft_get_image_pixels(t_img *img);

// KEYS
void		ft_rotate_left(t_player *player, t_cub *cub);
void		ft_rotate_right(t_player *player, t_cub *cub);

// MLX IMAGE FUNCTIONS
void		ft_image_hub(t_cub *cub);

// MOVE FUNCTIONS
void		ft_move_player(int keycode, t_cub *cub);
void		ft_move_forward(t_cub *cub);
void		ft_move_backward(t_cub *cub);
void		ft_move_right(t_cub *cub);
void		ft_move_left(t_cub *cub);

// TIME FUNCTIONS
void		ft_start_frame(t_frametime *frameTime);
void		ft_end_frame(t_frametime *frameTime);

#endif