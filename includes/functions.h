/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:00:05 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/23 00:15:37 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "headers.h"

// FREE FUNCTIONS
void	ft_clear_cub(void);
void	ft_clear_map(t_map *map);

// ERROR FUNCTIONS
char	*ft_error_msg_construct(int nbr, ...);
int		ft_put_error_msg(char *error_msg, int exit_status);

// PARSE FUNCTIONS
void	ft_parse_input(char **av, int ac);

// CUB FUNCTIONS
t_cub	*ft_get_cub(void);
void	ft_init_cub(char *av);

// MAP FUNCTIONS
void	ft_init_map(t_cub *cub);
void	ft_alloc_map(t_cub *cub);
void	ft_print_map(t_map *map);
void	ft_parse_map(char *name);

#endif