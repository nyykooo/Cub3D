/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:11:30 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/14 11:59:59 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	ft_rotate_hub(int keycode, t_cub *cub)
{
	t_player	*player;

	player = cub->map->player;
	if (keycode == KEY_LEFT)
	{
		ft_rotate_left(cub->map->player);
		if (!ft_perpendicular_vect(player->dirVector, player->camVector))
			ERROR_PRINT(ERROR_MSG(1, ERROR_VECTORS), 1);
		ft_ray_casting(cub);
	}
	if (keycode == KEY_RIGHT)
	{
		ft_rotate_right(cub->map->player);
		if (!ft_perpendicular_vect(player->dirVector, player->camVector))
			ERROR_PRINT(ERROR_MSG(1, ERROR_VECTORS), 1);
		ft_ray_casting(cub);
	}
}

void	ft_move_hub(int keycode, t_cub *cub)
{
	if (keycode == KEY_W)
		ft_move_forward(cub);
	else if (keycode == KEY_S)
		ft_move_backward(cub);
	else if (keycode == KEY_A)
		ft_move_left(cub);
	else if (keycode == KEY_D)
		ft_move_right(cub);
}

int	ft_close_x(t_cub *cub)
{
	if (cub)
		ft_clear_cub();
	exit (0);
}

void	ft_open_door(t_cub *cub)
{
	(void)cub;
	printf("Open door\n");
}

int	ft_keys(int keycode, t_cub *cub)
{
	if (keycode == KEY_ESC)
		ft_close_x(cub);
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		ft_rotate_hub(keycode, cub);
	if (keycode == KEY_W || keycode == KEY_S
		|| keycode == KEY_A || keycode == KEY_D)
		ft_move_hub(keycode, cub);
	if (keycode == KEY_SPC)
		ft_open_door(cub);
	return (0);
}
