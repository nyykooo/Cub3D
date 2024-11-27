/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:54:54 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/27 23:42:57 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	ft_look_for_invalid_map(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cub->map->rows)
	{
		j = -1;
		while (++j < (int)ft_strlen(cub->map->map[i]))
			if (cub->map->map[i][j] == '\t')
				ERROR_PRINT(ERROR_MSG(1, ERROR_MAP_CHAR, 0), 1);
	}
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

void	ft_trim_map(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cub->map->rows)
	{
		j = -1;
		while (cub->map->map[i][++j])
			if (cub->map->map[i][j] == '\n')
				cub->map->map[i][j] = 0;
	}
}
