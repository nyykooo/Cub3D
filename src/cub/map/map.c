/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:43:58 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/24 16:56:46 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	ft_init_map(t_cub *cub)
{
	cub->map = (t_map *)malloc(sizeof(t_map));
	if (!cub->map)
		ERROR_PRINT(ERROR_MSG(3, ERROR_READ, ": t_map map", "\"\n"), 1);
	cub->map->rows = 0;
	cub->map->cols = 0;
	cub->map->path = ft_strdup(cub->file);
	cub->map->texture = ft_init_texture();
}

void	ft_alloc_map(t_cub *cub)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(cub->map->path, O_RDONLY);
	cub->map->map = (char **)malloc(sizeof(char *) * cub->map->rows);
	if (!cub->map->map)
		ERROR_PRINT(ERROR_MSG(3, ERROR_READ, ": char **map", "\"\n"), 1);
	line = get_next_line(fd);
	while (i < cub->map->rows)
	{
		cub->map->map[i] = ft_strdup(line);
		if (!cub->map->map[i])
			ERROR_PRINT(ERROR_MSG(3, ERROR_READ, ": char *map[i]", "\"\n"), 1);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
}

void	ft_clean_map_spaces(char **line)
{
	int	j;

	j = -1;
	while ((*line)[++j])
	{
		if (ft_isspace((*line)[j]) && (*line)[j] != ' ')
			(*line)[j] = ' ';
	}
}

void	ft_print_map(t_map *map)
{
	int	i;

	printf("TEXTURES\n");
	printf("NO: %s\n", map->texture->north);
	printf("SO: %s\n", map->texture->south);
	printf("WE: %s\n", map->texture->west);
	printf("EA: %s\n", map->texture->east);
	printf("\nMAP\n");
	i = 0;
	while (i < map->rows)
	{
		printf("%s\n", map->map[i]);
		i++;
	}
}

void	ft_get_map_info(t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < cub->map->rows)
	{
		if (ft_is_text_or_color(cub->map,&cub->map->map[i]))
		{
			ft_clean_map_spaces(&cub->map->map[i]);
			ft_get_map_textures(cub->map, cub->map->map[i]);
		}
	}
}
