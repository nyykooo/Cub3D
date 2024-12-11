/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:11:30 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/11 15:36:46 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

int	ft_close_x(t_cub *cub)
{
	if (cub)
		ft_clear_cub();
	exit (0);
}

int	ft_keys(int keycode, t_cub *cub)
{
	if (keycode == KEY_LEFT)
	{
		ft_rotate_left(cub->map->player);
		if (!are_vectors_perpendicular(cub->map->player->dirVector, cub->map->player->camVector))
			ERROR_PRINT(ERROR_MSG(1, ERROR_VECTORS), 1);
		ft_ray_casting(cub);
	}
	if (keycode == KEY_RIGHT)
	{
		ft_rotate_right(cub->map->player);
		if (!are_vectors_perpendicular(cub->map->player->dirVector, cub->map->player->camVector))
			ERROR_PRINT(ERROR_MSG(1, ERROR_VECTORS), 1);
		ft_ray_casting(cub);
	}
	if (keycode == KEY_W)
		ft_move_forward(cub);
	return (0);
}
