/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:31:26 by brunhenr          #+#    #+#             */
/*   Updated: 2024/12/12 23:29:38 by ncampbel         ###   ########.fr       */
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
		if (cub->map->rows <= (unsigned int)ray->mapX || cub->map->cols <= (unsigned int)ray->mapY)
			break ;
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
	int		color;
	int		i = 0;
	int		tex_y;
	int		y;

	calculate_ray_direction(x, &ray, player);
	calculate_initial_distances(player, &ray);
	perform_dda(cub, &ray);
	if (ray.side == 0 || ray.side == 2)
		orto_wall_dist = (ray.sideDistX - ray.deltaDistX);
	else
		orto_wall_dist = (ray.sideDistY - ray.deltaDistY);
	line_height = (int)(SCREEN_HEIGHT / orto_wall_dist);
	draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
	draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
	
	double	wall_cord;
	int		tex_x;
	
	if(ray.side == 0 || ray.side == 2)
		wall_cord = player->p_y + orto_wall_dist * ray.dirY;
	else
		wall_cord = player->p_x + orto_wall_dist * ray.dirX;
    wall_cord -= floor((wall_cord));

	tex_x = (int)(wall_cord * (double)TEX_WIDTH);

	if((ray.side == 0 || ray.side == 2) && ray.dirX > 0)
		tex_x = TEX_WIDTH - tex_x - 1;
	if((ray.side == 1 || ray.side == 3) && ray.dirY < 0)
		tex_x = TEX_WIDTH - tex_x - 1;
	
	double step = 1.0 * TEX_HEIGHT / line_height; // 1.00 para ser double

    double texPos = (draw_start - SCREEN_HEIGHT / 2 + line_height / 2) * step;

	int		len = draw_end - draw_start;
	int		buffer[len];

	y = draw_start;
	while (y < draw_end)
	{
		tex_y = (int)texPos & (TEX_HEIGHT - 1);
		texPos += step;
		if (ray.side == 1)
			color = cub->map->texture->east->tex[tex_x][tex_y];
		else if (ray.side == 0)
			color = cub->map->texture->south->tex[tex_x][tex_y];
		else if (ray.side == 2)
			color = cub->map->texture->north->tex[tex_x][tex_y];
		else if (ray.side == 3)
			color = cub->map->texture->west->tex[tex_x][tex_y];
		buffer[i] = color;
		i++;
		y++;
	}
	ft_draw_vertical_line(x, draw_start, draw_end, cub, buffer);
}

int	ft_ray_casting(t_cub *cub)
{
	int			x;
	t_player	*player;

	x = 0;
	player = cub->map->player;
	ft_image_hub(cub);
	while (x < SCREEN_WIDTH)
	{
		draw_column(cub, x, player);
		x++;
	}
	mlx_put_image_to_window(cub->mlx_ptr, cub->win, cub->img, 0, 0);
	return (0);
}
