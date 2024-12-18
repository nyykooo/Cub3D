/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:29:57 by brunhenr          #+#    #+#             */
/*   Updated: 2024/12/18 14:00:17 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	ft_rotate_left(t_player *player, t_cub *cub)
{
	double	angle;
	
	angle = cub->frameTime.rot_speed;
	ft_rotate_vect(angle, player->dirVector);
	ft_rotate_vect(angle, player->camVector);
}

void	ft_rotate_right(t_player *player, t_cub *cub)
{
	double angle;
	
	angle = cub->frameTime.rot_speed * -1;
	ft_rotate_vect(angle, player->dirVector);
	ft_rotate_vect(angle, player->camVector);
}
