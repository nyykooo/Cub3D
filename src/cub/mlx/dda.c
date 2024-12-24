/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:55:19 by brunhenr          #+#    #+#             */
/*   Updated: 2024/12/24 15:09:07 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

static void	update_side_dist(t_ray *ray)
{
	if (ray->sideDistX < ray->sideDistY)
	{
		ray->sideDistX += ray->deltaDistX;
		ray->mapX += ray->stepX;
		if (ray->stepX == 1)
			ray->side = 0;
		else if (ray->stepX == -1)
			ray->side = 2;
	}
	else
	{
		ray->sideDistY += ray->deltaDistY;
		ray->mapY += ray->stepY;
		if (ray->stepY == -1)
			ray->side = 3;
		else
			ray->side = 1;
	}
}

static void	check_hit(t_cub *cub, t_ray *ray)
{
	if (cub->map->rows <= (unsigned int)ray->mapX || \
	cub->map->cols <= (unsigned int)ray->mapY)
	{
		ray->hit = 1;
		return ;
	}
	if (cub->map->map[ray->mapX][ray->mapY] == '1')
		ray->hit = 1;
	else if (cub->map->map[ray->mapX][ray->mapY] == '2')
		ray->hit = 2;
}

void	ft_perform_dda(t_cub *cub, t_ray *ray)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		update_side_dist(ray);
		check_hit(cub, ray);
	}
}
