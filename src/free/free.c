/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:43:29 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/30 12:58:43 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

static void	ft_clear_color(t_color *color)
{
	if (color->input)
		free(color->input);
	if (color)
		free(color);
}

static void	ft_clear_texture(t_texture *texture)
{
	if (texture->north)
		free(texture->north);
	if (texture->south)
		free(texture->south);
	if (texture->east)
		free(texture->east);
	if (texture->west)
		free(texture->west);
	if (texture->ceiling)
		ft_clear_color(texture->ceiling);
	if (texture->floor)
		ft_clear_color(texture->floor);
	if (texture)
		free(texture);
}

static void	ft_clear_map(t_map *map)
{
	if (map && map->map)
		ft_free_array(map->map);
	if (map && map->ff_map)
		ft_free_array(map->ff_map);
	if (map->texture)
		ft_clear_texture(map->texture);
	if (map->path)
		free(map->path);
	if (map)
		free(map);
}

void	ft_clear_cub(void)
{
	t_cub	*cub;

	cub = ft_get_cub();
	if (cub->fd != -1)
		close(cub->fd);
	if (cub->line)
		free(cub->line);
	if (cub->file)
		free(cub->file);
	if (cub->map)
		ft_clear_map(cub->map);
}
