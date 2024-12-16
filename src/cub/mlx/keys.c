/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:29:57 by brunhenr          #+#    #+#             */
/*   Updated: 2024/12/16 22:45:14 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	ft_rotate_left(t_player *player)
{
	double	angle;
	double	oldDirX; 
	double	oldPlaneX;
	
	angle = ft_deg_to_rad(5);
	oldDirX = player->dirVector->x;
	player->dirVector->x = player->dirVector->x * cos(angle) - player->dirVector->y * sin(angle);
	player->dirVector->y = oldDirX * sin(angle) + player->dirVector->y * cos(angle);

	oldPlaneX = player->camVector->x;
	player->camVector->x = player->camVector->x * cos(angle) - player->camVector->y * sin(angle);
	player->camVector->y = oldPlaneX * sin(angle) + player->camVector->y * cos(angle);

	normalize_vector(player->dirVector);
	normalize_vector(player->camVector);
}

void	ft_rotate_right(t_player *player)
{
	double angle;
	double oldDirX;
	double oldPlaneX;

	angle = ft_deg_to_rad(-5);
	oldDirX = player->dirVector->x;
	player->dirVector->x = player->dirVector->x * cos(angle) - player->dirVector->y * sin(angle);
	player->dirVector->y = oldDirX * sin(angle) + player->dirVector->y * cos(angle);

	oldPlaneX = player->camVector->x;
	player->camVector->x = player->camVector->x * cos(angle) - player->camVector->y * sin(angle);
	player->camVector->y = oldPlaneX * sin(angle) + player->camVector->y * cos(angle);

	normalize_vector(player->dirVector);
	normalize_vector(player->camVector);
}

void	ft_move_forward(t_cub *cub)
{
	if (ft_is_walkable(cub->map->map[(int)cub->map->player->p_x + (int)(cub->map->player->dirVector->x * cub->move_speed)][(int)cub->map->player->p_y]))
	{
		cub->map->player->p_x += cub->map->player->dirVector->x * cub->move_speed;
		if (ft_is_walkable(cub->map->map[(int)cub->map->player->p_x][(int)cub->map->player->p_y + ((int)(cub->map->player->dirVector->y * cub->move_speed))]))
		{
			cub->map->player->p_y += cub->map->player->dirVector->y * cub->move_speed;
			ft_ray_casting(cub);
		}
		else 
		{
			printf("OUT OF BOUNDS VETOR Y coordenadas: x: %d, y: %d\n", (int)cub->map->player->p_x, (int)cub->map->player->p_y + (int)((cub->map->player->dirVector->y * cub->move_speed)));
			printf("Player out of the walkable zone\n");
			ft_clear_cub();
			exit(1);
		}
	}
	else 
	{
		printf("OUT OF BOUNDS VETOR X coordenadas: x: %d, y: %d\n", (int)cub->map->player->p_x + (int)(cub->map->player->dirVector->x * cub->move_speed), (int)cub->map->player->p_y);
		printf("Player out of the walkable zone\n");
		ft_clear_cub();
		exit(1);
	}
}