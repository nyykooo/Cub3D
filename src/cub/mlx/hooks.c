/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:11:30 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/10 19:51:14 by brunhenr         ###   ########.fr       */
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
