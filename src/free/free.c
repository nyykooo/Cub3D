/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:43:29 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/24 18:57:16 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

static void	ft_clear_player(t_player *player)
{
	if (player)
	{
		if (player->dirVector)
			free(player->dirVector);
		if (player->camVector)
			free(player->camVector);
		if (player->ray)
			free(player->ray);
		free (player);
	}
}

static void	ft_clear_color(t_color *color)
{
	if (color->input)
		free(color->input);
	if (color)
		free(color);
}

static void	ft_clear_single_texture(t_wall *texture_part)
{
	if (texture_part->path)
	{
		free(texture_part->path);
		if (texture_part->tex)
			ft_free_int_array(texture_part->tex);
		free(texture_part);
	}
}

static void	ft_clear_texture(t_texture *texture)
{
	ft_clear_single_texture(texture->north);
	ft_clear_single_texture(texture->south);
	ft_clear_single_texture(texture->east);
	ft_clear_single_texture(texture->west);
	ft_clear_single_texture(texture->door);
	if (texture->ceiling)
		ft_clear_color(texture->ceiling);
	if (texture->floor)
		ft_clear_color(texture->floor);
	if (texture)
		free(texture);
}

void	ft_clear_map(t_map *map)
{
	if (map && map->map)
		ft_free_array(map->map);
	if (map && map->ff_map)
		ft_free_array(map->ff_map);
	if (map->texture)
		ft_clear_texture(map->texture);
	if (map->path)
		free(map->path);
	if (map->player)
		ft_clear_player(map->player);
	if (map)
		free(map);
}
