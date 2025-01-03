/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:54:06 by ncampbel          #+#    #+#             */
/*   Updated: 2025/01/02 16:51:15 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

static bool	ft_check_order(t_cub *cub)
{
	if (cub->map->texture->north->path && cub->map->texture->south->path
		&& cub->map->texture->west->path && cub->map->texture->east->path
		&& cub->map->texture->ceiling->input
		&& cub->map->texture->floor->input)
		return (true);
	return (false);
}

static void	ft_check_duplicated_info(t_image *image, char *path)
{
	if (image->path)
		free (image->path);
	image->path = ft_strdup(path);
}

t_texture	*ft_init_texture(void)
{
	t_texture	*texture;

	texture = (t_texture *)ft_calloc(1, sizeof(t_texture));
	if (!texture)
		ERROR_PRINT(ERROR_MSG(3, ERROR_MLC, ": t_texture texture", "\"\n"), 1);
	texture->north = ft_calloc(1, sizeof(t_image));
	if (!texture->north)
		ERROR_PRINT(ERROR_MSG(3, ERROR_MLC, ": t_image north", "\"\n"), 1);
	texture->south = ft_calloc(1, sizeof(t_image));
	if (!texture->south)
		ERROR_PRINT(ERROR_MSG(3, ERROR_MLC, ": t_image south", "\"\n"), 1);
	texture->east = ft_calloc(1, sizeof(t_image));
	if (!texture->east)
		ERROR_PRINT(ERROR_MSG(3, ERROR_MLC, ": t_image east", "\"\n"), 1);
	texture->west = ft_calloc(1, sizeof(t_image));
	if (!texture->west)
		ERROR_PRINT(ERROR_MSG(3, ERROR_MLC, ": t_image west", "\"\n"), 1);
	texture->door = ft_calloc(1, sizeof(t_image));
	if (!texture->door)
		ERROR_PRINT(ERROR_MSG(3, ERROR_MLC, ": t_image door", "\"\n"), 1);
	texture->ceiling = ft_init_color();
	texture->floor = ft_init_color();
	return (texture);
}

void	ft_get_text_color(t_map *map, char **split)
{
	if (split[0] == NULL || split[0][0] == '\0' || split[1] == NULL)
		return ;
	if (ft_strcmp(split[0], "NO") == 0)
		ft_check_duplicated_info(map->texture->north, split[1]);
	else if (ft_strcmp(split[0], "SO") == 0)
		ft_check_duplicated_info(map->texture->south, split[1]);
	else if (ft_strcmp(split[0], "WE") == 0)
		ft_check_duplicated_info(map->texture->west, split[1]);
	else if (ft_strcmp(split[0], "EA") == 0 )
		ft_check_duplicated_info(map->texture->east, split[1]);
	else if (ft_strcmp(split[0], "DO") == 0 )
		ft_check_duplicated_info(map->texture->door, split[1]);
}

bool	ft_is_text_or_color(char *line, t_cub *cub)
{
	if (line[0] == '\0' || line[0] == '\n')
		return (true);
	if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
		|| ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0 \
		|| ft_strncmp(line, "DO", 2) == 0)
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
