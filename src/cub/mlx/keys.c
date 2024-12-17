/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:29:57 by brunhenr          #+#    #+#             */
/*   Updated: 2024/12/17 00:28:17 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	ft_rotate_left(t_player *player, t_cub *cub)
{
	double	angle;
	double	oldDirX; 
	double	oldPlaneX;
	
	//angle = ft_deg_to_rad(5);
	angle = cub->frameTime.rot_speed;
	oldDirX = player->dirVector->x;
	player->dirVector->x = player->dirVector->x * cos(angle) - player->dirVector->y * sin(angle);
	player->dirVector->y = oldDirX * sin(angle) + player->dirVector->y * cos(angle);

	oldPlaneX = player->camVector->x;
	player->camVector->x = player->camVector->x * cos(angle) - player->camVector->y * sin(angle);
	player->camVector->y = oldPlaneX * sin(angle) + player->camVector->y * cos(angle);

	normalize_vector(player->dirVector);
	normalize_vector(player->camVector);
}

void	ft_rotate_right(t_player *player, t_cub *cub)
{
	double angle;
	double oldDirX;
	double oldPlaneX;

	//angle = ft_deg_to_rad(-5);
	angle = cub->frameTime.rot_speed * -1;
	oldDirX = player->dirVector->x;
	player->dirVector->x = player->dirVector->x * cos(angle) - player->dirVector->y * sin(angle);
	player->dirVector->y = oldDirX * sin(angle) + player->dirVector->y * cos(angle);

	oldPlaneX = player->camVector->x;
	player->camVector->x = player->camVector->x * cos(angle) - player->camVector->y * sin(angle);
	player->camVector->y = oldPlaneX * sin(angle) + player->camVector->y * cos(angle);

	normalize_vector(player->dirVector);
	normalize_vector(player->camVector);
}
