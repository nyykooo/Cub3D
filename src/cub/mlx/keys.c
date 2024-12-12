/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:29:57 by brunhenr          #+#    #+#             */
/*   Updated: 2024/12/11 15:47:47 by ncampbel         ###   ########.fr       */
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
