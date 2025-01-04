/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:14:36 by brunhenr          #+#    #+#             */
/*   Updated: 2025/01/04 21:17:50 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

int	ft_ray_casting(t_cub *cub)
{
	int			x;
	t_player	*player;

	x = 0;
	player = cub->map->player;
	ft_image_hub(cub);
	ft_start_frame(&cub->frame_time);
	while (x < SCREEN_WIDTH)
	{
		ft_draw_column(cub, x, player);
		x++;
	}
	if (!player->is_attacking)
		ft_draw_sword(player->sword, SWORD_WIDTH,
			SWORD_HEIGHT, (SCREEN_HEIGHT / SWORD_HEIGHT));
	else
		draw_sword_attack(cub, player);
	ft_draw_minimap(cub, player);
	ft_end_frame(&cub->frame_time);
	mlx_put_image_to_window(cub->mlx_ptr, cub->win, cub->img, 0, 0);
	return (0);
}
