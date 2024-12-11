/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:11:30 by ncampbel          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/12/05 21:50:52 by ncampbel         ###   ########.fr       */
=======
/*   Updated: 2024/12/10 19:51:14 by brunhenr         ###   ########.fr       */
>>>>>>> bruno
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

int	ft_game_keys(int keycode, t_cub *cub)
{
	if (keycode == KEY_ESC && cub)
		ft_close_x(cub);
	else if (keycode == KEY_W || keycode == KEY_S
		|| keycode == KEY_A || keycode == KEY_D)
		ft_move_player(keycode, cub);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		printf("Player turned %d\n", keycode);
	return (0);
}

int	ft_close_x(t_cub *cub)
{
	if (cub)
		ft_clear_cub();
	exit (0);
}

int	ft_keys(int keycode, t_cub *cub)
{
	if (keycode == 65361) //seta esquerda
	{
		ft_rotate_left(cub->map->player);
		if (!are_vectors_perpendicular(cub->map->player->dirVector, cub->map->player->camVector))
		{
			printf("The vectors are not perpendicular.\n");
			ft_clear_cub();
			exit(1);
		}
		ft_ray_casting(cub);
	}
	if (keycode == 65363) //seta direita
	{
		ft_rotate_right(cub->map->player);
		if (!are_vectors_perpendicular(cub->map->player->dirVector, cub->map->player->camVector))
		{
			printf("The vectors are not perpendicular.\n");
			ft_clear_cub();
			exit(1);
		}
		ft_ray_casting(cub);
	}
	if (keycode == 119) //W
		ft_move_forward(cub);
	return (0);
}
