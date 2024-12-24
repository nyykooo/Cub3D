/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:20:48 by brunhenr          #+#    #+#             */
/*   Updated: 2024/12/24 14:55:44 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	calculate_ray_direction(int x, t_ray *ray, t_player *player)
{
	double	param;

	param = (2 * x / (double)SCREEN_WIDTH) - 1;
	ray->dirX = player->dirVector->x + (param * player->camVector->x);
	ray->dirY = player->dirVector->y + (param * player->camVector->y);
}

void	calculate_delta_distances(t_ray *ray)
{
	if (ray->dirX == 0)
		ray->deltaDistX = 1e30;
	else
		ray->deltaDistX = fabs(1 / ray->dirX);
	if (ray->dirY == 0)
		ray->deltaDistY = 1e30;
	else
		ray->deltaDistY = fabs(1 / ray->dirY);
}

void	calculate_initial_distances(t_player *player, t_ray *ray)
{
	ray->mapX = (int)player->p_x;
	ray->mapY = (int)player->p_y;
	calculate_delta_distances(ray);
	if (ray->dirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (player->p_x - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - player->p_x) * ray->deltaDistX;
	}
	if (ray->dirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (player->p_y - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0 - player->p_y) * ray->deltaDistY;
	}
}
