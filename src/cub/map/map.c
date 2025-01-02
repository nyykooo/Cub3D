/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:43:58 by ncampbel          #+#    #+#             */
/*   Updated: 2025/01/02 16:51:53 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

static void	ft_init_map_content(t_cub *cub)
{
	unsigned int	i;

	i = 0;
	while (i <= cub->map->rows)
		cub->map->map[i++] = NULL;
}

static t_player	*ft_init_player(void)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		ERROR_PRINT(ERROR_MSG(3, ERROR_MLC, ": t_player player", "\"\n"), 1);
	player->p_dir = -1;
	player->p_x = -1;
	player->p_y = -1;
	player->dirVector = (t_dirVector *)malloc(sizeof(t_dirVector));
	if (!player->dirVector)
		ERROR_PRINT(ERROR_MSG(3, ERROR_MLC, \
		": t_dirVector dirVector", "\"\n"), 1);
	player->camVector = (t_dirVector *)malloc(sizeof(t_dirVector));
	if (!player->dirVector || !player->camVector)
		ERROR_PRINT(ERROR_MSG(3, ERROR_MLC, \
		": t_dirVector dirVector or camVector", "\"\n"), 1);
	player->ray = (t_ray *)malloc(sizeof(t_ray));
	if (!player->ray)
		ERROR_PRINT(ERROR_MSG(3, ERROR_MLC, ": t_ray ray", "\"\n"), 1);
	return (player);
}

void	ft_init_map(t_cub *cub)
{
	cub->map = (t_map *)malloc(sizeof(t_map));
	if (!cub->map)
		ERROR_PRINT(ERROR_MSG(3, ERROR_READ, ": t_map map", "\"\n"), 1);
	cub->map->rows = 0;
	cub->map->cols = 0;
	cub->map->path = ft_strdup(cub->file);
	cub->map->map = NULL;
	cub->map->ff_map = NULL;
	cub->map->texture = ft_init_texture();
	cub->map->player = ft_init_player();
}

void	ft_alloc_map(t_cub *cub)
{
	unsigned int	i;

	i = 0;
	cub->fd = open(cub->map->path, O_RDONLY);
	cub->map->map = (char **)malloc(sizeof(char *) * (cub->map->rows + 1));
	if (!cub->map->map)
		ERROR_PRINT(ERROR_MSG(3, ERROR_READ, ": char **map", "\"\n"), 1);
	ft_init_map_content(cub);
	cub->line = get_next_line(cub->fd);
	while (i < cub->map->rows)
	{
		if (cub->line[0] == '\n' && i != 0)
			ERROR_PRINT(ERROR_MSG(1, ERROR_MAP_EMPTY), 1);
		if (!ft_is_text_or_color(cub->line, cub))
		{
			cub->map->map[i] = ft_strdup(cub->line);
			if (!cub->map->map[i++])
				ERROR_PRINT(ERROR_MSG(3, ERROR_READ,
						": char *map[i]", "\"\n"), 1);
		}
		free(cub->line);
		cub->line = get_next_line(cub->fd);
	}
	cub->map->map[i] = NULL;
	close(cub->fd);
}

// void	ft_clean_map_spaces(char **line)
// {
// 	int	j;

// 	j = -1;
// 	while ((*line)[++j])
// 	{
// 		if (ft_isspace((*line)[j]) && (*line)[j] != ' ')
// 			(*line)[j] = ' ';
// 	}
// }

// void	ft_get_map_info(t_cub *cub, char *line)
// {
// 	ft_clean_map_spaces(&line);
// 	ft_get_map_textures(cub->map, line);
// }
