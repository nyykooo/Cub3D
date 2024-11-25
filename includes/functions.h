/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:00:05 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/25 19:25:08 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "headers.h"

// FREE FUNCTIONS
void		ft_clear_cub(void);
void		ft_clear_map(t_map *map);
void		ft_clear_texture(t_texture *texture);
void		ft_clear(t_cub *cub);

// ERROR FUNCTIONS
char		*ft_error_msg_construct(int nbr, ...);
int			ft_put_error_msg(char *error_msg, int exit_status);

// PARSE FUNCTIONS
void		ft_parse_input(char **av, int ac);

// CUB FUNCTIONS
t_cub		*ft_get_cub(void);
void		ft_init_cub(char *av);

// TEXTURE FUNCTIONS
t_texture	*ft_init_texture(void);
void		ft_get_texture(t_texture *texture, char *line);
bool		ft_get_text_color(t_map *map, char **split);
bool		ft_is_text_or_color(char *line);

// MAP FUNCTIONS
void		ft_init_map(t_cub *cub);
void		ft_alloc_map(t_cub *cub);
void		ft_print_map(t_map *map);
void		ft_parse_map(char *name);
void		ft_get_map_textures(t_map *map, char *line);
void		ft_clean_map_spaces(char **line);
void		ft_get_map_info(t_cub *cub, char *line);

#endif