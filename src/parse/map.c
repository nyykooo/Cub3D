/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:54:54 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/24 20:13:43 by ncampbel         ###   ########.fr       */
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
		if (!ft_is_text_or_color(line))
			cub->map->rows++;
		ft_get_map_info(cub, line);
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
	ft_get_text_color(map, split);
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return ;
}
