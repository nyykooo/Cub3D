/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:54:54 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/24 16:55:53 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

void	ft_parse_map(char *name)
{
	t_cub	*cub;
	char	*line;
	int		fd;

	cub = ft_get_cub();
	fd = open(name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		cub->map->rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
}

void	ft_get_map_textures(t_map *map, char *line)
{
	char	**split;
	int		i;

	split = ft_split(line, ' ');
	ft_is_text_or_color(map, split);
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return ;
}

bool	ft_is_text_or_color(t_map *map, char **split)
{
	if (ft_strncmp(split[0], "NO", 2) == 0)
		map->texture->north = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "SO", 2) == 0)
		map->texture->south = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "WE", 2) == 0)
		map->texture->west = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "EA", 2) == 0)
		map->texture->east = ft_strdup(split[1]);
	else if (map->texture->north && map->texture->south
		&& map->texture->west && map->texture->east)
		return (false);
	return (true);
}
