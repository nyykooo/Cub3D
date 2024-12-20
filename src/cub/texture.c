/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:54:06 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/18 13:53:44 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

static bool	ft_check_order(t_cub *cub)
{
	if (cub->map->texture->north && cub->map->texture->south
		&& cub->map->texture->west && cub->map->texture->east
		&& cub->map->texture->ceiling->input
		&& cub->map->texture->floor->input)
		return (true);
	return (false);
}

t_texture	*ft_init_texture(void)
{
	t_texture	*texture;

	texture = (t_texture *)malloc(sizeof(t_texture));
	texture->north = malloc(sizeof(t_image));
	texture->south = malloc(sizeof(t_image));
	texture->east = malloc(sizeof(t_image));
	texture->west = malloc(sizeof(t_image));
	texture->north->path = NULL;
    texture->north->tex = NULL;
    texture->north->img = NULL;

    texture->south->path = NULL;
    texture->south->tex = NULL;
    texture->south->img = NULL;

    texture->east->path = NULL;
    texture->east->tex = NULL;
    texture->east->img = NULL;

    texture->west->path = NULL;
    texture->west->tex = NULL;
    texture->west->img = NULL;
	texture->ceiling = ft_init_color();
	texture->floor = ft_init_color();
	return (texture);
}

bool	ft_get_text_color(t_map *map, char **split)
{
	if (split[0] == NULL || split[0][0] == '\0' || split[1] == NULL)
		return (true);
	if (ft_strncmp(split[0], "NO", 2) == 0)
		map->texture->north->path = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "SO", 2) == 0)
		map->texture->south->path = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "WE", 2) == 0)
		map->texture->west->path = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "EA", 2) == 0)
		map->texture->east->path = ft_strdup(split[1]);
	else if (map->texture->north && map->texture->south
		&& map->texture->west && map->texture->east
		&& map->texture->ceiling->input
		&& map->texture->floor->input)
		return (false);
	return (true);
}

bool	ft_is_text_or_color(char *line, t_cub *cub)
{
	if (line[0] == '\0' || line[0] == '\n')
		return (true);
	if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
		|| ft_strncmp(line, "WE", 2) == 0
		|| ft_strncmp(line, "EA", 2) == 0)
		return (true);
	else if (ft_strncmp(line, "C", 1) == 0 || ft_strncmp(line, "F", 1) == 0)
	{
		ft_parse_color(ft_get_cub(), line);
		return (true);
	}
	if (!ft_check_order(cub))
		ERROR_PRINT(ERROR_MSG(1, ERROR_MAP_ORDER), 1);
	return (false);
}
