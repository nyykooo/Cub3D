/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:31:26 by brunhenr          #+#    #+#             */
/*   Updated: 2024/12/11 13:04:46 by brunhenr         ###   ########.fr       */
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
		ray->deltaDistX = 1e30; //1e30 = 1 * 10^30. Tende ao infinito.
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

int	perform_dda(t_cub *cub, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		if (cub->map->map[ray->mapX][ray->mapY] == '1') //corrigir! Antes de checar a parede, checar se está dentro do mapa
			hit = 1;
	}
	return (hit);
}

void	draw_column(t_cub *cub, int x, t_player *player)
{
	t_ray	ray;
	int		line_height;
	int		draw_start;
	double	orto_wall_dist;
	int		draw_end;

	calculate_ray_direction(x, &ray, player);
	calculate_initial_distances(player, &ray);
	perform_dda(cub, &ray);
	if (ray.side == 0)
		orto_wall_dist = (ray.sideDistX - ray.deltaDistX);
	else
		orto_wall_dist = (ray.sideDistY - ray.deltaDistY);
	line_height = (int)(SCREEN_HEIGHT / orto_wall_dist);
	draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
	draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
	if (ray.side == 1)
		cub->map->texture->untex = 33000;
	else
		cub->map->texture->untex = 65535;
	ft_draw_vertical_line(x, draw_start, draw_end, cub);
}

int	ft_ray_casting(t_cub *cub)
{
	int			x;
	t_player	*player;

	x = 0;
	player = cub->map->player;
	clear_image(cub, 0x000000); // pensar em destruir e criar nova imagem. Testar!
	while (x < SCREEN_WIDTH)
	{
		draw_column(cub, x, player);
		x++;
	}
	mlx_put_image_to_window(cub->mlx_ptr, cub->win, cub->img, 0, 0);
	return (0);
}
