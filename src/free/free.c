/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:43:29 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/27 23:30:59 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

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

void	ft_clear_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->map)
	{
		while (i < map->rows)
		{
			if (map->map[i])
				free(map->map[i]);
			i++;
		}
		free(map->map);
	}
	if (map->texture)
		ft_clear_texture(map->texture);
	if (map->path)
		free(map->path);
	if (map)
		free(map);
}

void	ft_clear_texture(t_texture *texture)
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
		free(texture->ceiling);
	if (texture->floor)
		free(texture->floor);
	if (texture)
		free(texture);
}
