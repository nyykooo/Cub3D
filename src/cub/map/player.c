/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:10:52 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/19 16:13:29 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

static bool	ft_player_dir(t_map *map, int x, int y)
{
	if (map->map[x][y] == 'N' || map->map[x][y] == 'S' ||
		map->map[x][y] == 'E' || map->map[x][y] == 'W')
		return (true);
	return (false);
}

static void initial_player_dir(t_map *map)
{
	if (map->player->p_dir == 78) // N
	{
		map->player->dirVector->x = -0.66;
		map->player->dirVector->y = 0;
	}
	else if (map->player->p_dir == 83) // S
	{
		map->player->dirVector->x = 0.66;
		map->player->dirVector->y = 0;
	}
	else if (map->player->p_dir == 69) // E
	{
		map->player->dirVector->x = 0;
		map->player->dirVector->y = 0.66;
	}
	else if (map->player->p_dir == 87) // W
	{
		map->player->dirVector->x = 0;
		map->player->dirVector->y = -0.66;
	}
}
static void initial_cam_dir(t_map *map)
{
	if (map->player->p_dir == 78) // N
	{
		map->player->camVector->x = 0;
		map->player->camVector->y = 0.66;
	}
	else if (map->player->p_dir == 83) // S
	{
		map->player->camVector->x = 0;
		map->player->camVector->y = -0.66;
	}
	else if (map->player->p_dir == 69) // E
	{
		map->player->camVector->x = 0.66;
		map->player->camVector->y = 0;
	}
	else if (map->player->p_dir == 87) // W
	{
		map->player->camVector->x = -0.66;
		map->player->camVector->y = 0;
	}
}

static void	ft_fill_player(t_map *map, int x, int y)
{
	if (map->player->p_dir != -1)
		ERROR_PRINT(ERROR_MSG(1, ERROR_PLAYER), 1);
	map->player->p_x = x + 0.5;
	map->player->p_y = y + 0.5;
	map->player->p_dir = map->map[x][y];
	map->player->dirVector = (t_dirVector *)malloc(sizeof(t_dirVector));
	map->player->camVector = (t_dirVector *)malloc(sizeof(t_dirVector));
	if (!map->player->dirVector || !map->player->camVector)
		ERROR_PRINT(ERROR_MSG(3, ERROR_MLC, ": t_dirVector dirVector or camVector", "\"\n"), 1);
	map->player->ray = (t_ray *)malloc(sizeof(t_ray));
	if (!map->player->ray)
		ERROR_PRINT(ERROR_MSG(3, ERROR_MLC, ": t_ray ray", "\"\n"), 1);
	map->player->is_attacking = false;
	initial_player_dir(map);
	initial_cam_dir(map);
}

void	ft_check_player(t_map *map)
{
	int		x;
	int		y;

	x = -1;
	while (map->map[++x])
	{
		y = -1;
		while (map->map[x][++y])
			if (ft_player_dir(map, x, y))
				ft_fill_player(map, x, y);
	}
	if (map->player->p_dir == -1)
		ERROR_PRINT(ERROR_MSG(1, ERROR_PLAYER), 1);
}

t_player	*ft_init_player(void)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		ERROR_PRINT(ERROR_MSG(3, ERROR_READ, ": t_player player", "\"\n"), 1);
	player->p_dir = -1;
	player->p_x = -1;
	player->p_y = -1;
	return (player);
}
