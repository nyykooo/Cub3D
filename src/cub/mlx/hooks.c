/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:11:30 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/19 15:27:01 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	ft_rotate_hub(t_cub *cub)
{
	t_player	*player;

	player = cub->map->player;
	if (cub->keys.left)
	{
		ft_rotate_left(cub->map->player, cub);
		if (!ft_perpendicular_vect(player->dirVector, player->camVector))
			ERROR_PRINT(ERROR_MSG(1, ERROR_VECTORS), 1);
		ft_ray_casting(cub);
	}
	if (cub->keys.right)
	{
		ft_rotate_right(cub->map->player, cub);
		if (!ft_perpendicular_vect(player->dirVector, player->camVector))
			ERROR_PRINT(ERROR_MSG(1, ERROR_VECTORS), 1);
		ft_ray_casting(cub);
	}
}

void	ft_move_hub(t_cub *cub)
{
	if (cub->keys.w)
		ft_move_forward(cub);
	else if (cub->keys.s)
		ft_move_backward(cub);
	else if (cub->keys.a)
		ft_move_left(cub);
	else if (cub->keys.d)
		ft_move_right(cub);
}

int	ft_close_x(t_cub *cub)
{
	if (cub)
		ft_clear_cub();
	exit (0);
}

int	ft_keys(t_cub *cub)
{
	if (cub->keys.esc)
		ft_close_x(cub);
	if (cub->keys.left || cub->keys.right)
		ft_rotate_hub(cub);
	if (cub->keys.w || cub->keys.s
		|| cub->keys.a || cub->keys.d)
		ft_move_hub(cub);
	return (0);
}
