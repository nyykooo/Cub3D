/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:54:18 by brunhenr          #+#    #+#             */
/*   Updated: 2025/01/04 14:10:02 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	ft_prepare_vec(double angle, t_dirVector *dir_vector, t_cub *cub)
{
	angle = ft_deg_to_rad(angle);
	dir_vector->x = cub->map->player->dirVector->x;
	dir_vector->y = cub->map->player->dirVector->y;
	ft_rotate_vect(angle, dir_vector);
	cub->map->player->ray->dirX = dir_vector->x;
	cub->map->player->ray->dirY = dir_vector->y;
}

static void	ft_collision_init(t_player *player)
{
	player->ray->mapX = (int)player->p_x;
	player->ray->mapY = (int)player->p_y;
	calculate_delta_distances(player->ray);
}

void	ft_collision_dists(t_player *player)
{
	ft_collision_init(player);
	if (player->ray->dirX < 0)
	{
		player->ray->stepX = -1;
		player->ray->sideDistX = (player->p_x - player->ray->mapX) \
		* player->ray->deltaDistX;
	}
	else
	{
		player->ray->stepX = 1;
		player->ray->sideDistX = (player->ray->mapX + 1.0 - player->p_x) \
		* player->ray->deltaDistX;
	}
	if (player->ray->dirY < 0)
	{
		player->ray->stepY = -1;
		player->ray->sideDistY = (player->p_y - player->ray->mapY) \
		* player->ray->deltaDistY;
	}
	else
	{
		player->ray->stepY = 1;
		player->ray->sideDistY = (player->ray->mapY + 1.0 - player->p_y) \
		* player->ray->deltaDistY;
	}
}

int	ft_collision_dda(t_player *player, t_cub *cub)
{
	while (true)
	{
		if (player->ray->sideDistX < player->ray->sideDistY)
		{
			player->ray->sideDistX += player->ray->deltaDistX;
			player->ray->mapX += player->ray->stepX;
		}
		else
		{
			player->ray->sideDistY += player->ray->deltaDistY;
			player->ray->mapY += player->ray->stepY;
		}
		if (cub->map->rows <= (unsigned int)player->ray->mapX || \
		cub->map->cols <= (unsigned int)player->ray->mapY)
			break ;
		if (cub->map->map[player->ray->mapX][player->ray->mapY] == '1' || \
		cub->map->map[player->ray->mapX][player->ray->mapY] == '2')
			break ;
	}
	return (0);
}

int	ft_collision(t_map *map, t_cub *cub)
{
	ft_collision_dists(map->player);
	ft_collision_dda(map->player, cub);
	if (map->player->ray->sideDistX < 2.0 || map->player->ray->sideDistY < 2.0)
		return (1);
	return (0);
}
