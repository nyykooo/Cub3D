/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:54:54 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/25 20:13:35 by ncampbel         ###   ########.fr       */
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

void	ft_check_first_last(char *line)
{
	int		i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '1')
			ERROR_PRINT(ERROR_MSG(1, ERROR_MAP_CLOSE), 1);
	}
}

void	ft_check_line(char *line)
{
	int		len;

	len = ft_strlen(line);
	if (line[0] != '1' || line[len - 1] != '1')
		ERROR_PRINT(ERROR_MSG(1, ERROR_MAP_CLOSE), 1);
}

void	ft_closed_map(t_cub *cub)
{
	int		i;

	i = -1;
	while (++i < cub->map->rows)
	{
		if (i == 0)
			ft_check_first_last(cub->map->map[i]);
		else
			ft_check_line(cub->map->map[i]);
	}
}
