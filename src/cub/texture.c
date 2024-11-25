/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:54:06 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/25 19:00:47 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

t_texture	*ft_init_texture(void)
{
	t_texture	*texture;

	texture = (t_texture *)malloc(sizeof(t_texture));
	texture->north = NULL;
	texture->south = NULL;
	texture->east = NULL;
	texture->west = NULL;
	texture->ceiling = NULL;
	texture->floor = NULL;
	return (texture);
}

bool	ft_get_text_color(t_map *map, char **split)
{
	if (split[0] == NULL || split[0][0] == '\0' || split[1] == NULL)
		return (true);
	if (ft_strncmp(split[0], "NO", 2) == 0)
		map->texture->north = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "SO", 2) == 0)
		map->texture->south = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "WE", 2) == 0)
		map->texture->west = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "EA", 2) == 0)
		map->texture->east = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "C", 1) == 0)
		map->texture->ceiling = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "F", 1) == 0)
		map->texture->floor = ft_strdup(split[1]);
	else if (map->texture->north && map->texture->south
		&& map->texture->west && map->texture->east && map->texture->ceiling
		&& map->texture->floor)
		return (false);
	return (true);
}

bool	ft_is_text_or_color(char *line)
{
	if (line[0] == '\0' || line[0] == '\n')
		return (true);
	if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
		|| ft_strncmp(line, "WE", 2) == 0
		|| ft_strncmp(line, "EA", 2) == 0 || ft_strncmp(line, "C", 1) == 0
		|| ft_strncmp(line, "F", 1) == 0)
		return (true);
	return (false);
}
