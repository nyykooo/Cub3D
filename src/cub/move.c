/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:51:17 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/05 21:52:52 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

static void	ft_move_up(t_cub *cub)
{
	int		x;
	int		y;

	x = cub->map->player->p_x;
	y = cub->map->player->p_y;
	if (cub->map->map[x - 1][y] == '0')
	{
		cub->map->map[x][y] = '0';
		cub->map->map[x - 1][y] = cub->map->player->p_dir;
		cub->map->player->p_x = x - 1;
	}
}

static void	ft_move_down(t_cub *cub)
{
	int		x;
	int		y;

	x = cub->map->player->p_x;
	y = cub->map->player->p_y;
	if (cub->map->map[x + 1][y] == '0')
	{
		cub->map->map[x][y] = '0';
		cub->map->map[x + 1][y] = cub->map->player->p_dir;
		cub->map->player->p_x = x + 1;
	}
}

static void	ft_move_left(t_cub *cub)
{
	int		x;
	int		y;

	x = cub->map->player->p_x;
	y = cub->map->player->p_y;
	if (cub->map->map[x][y - 1] == '0')
	{
		cub->map->map[x][y] = '0';
		cub->map->map[x][y - 1] = cub->map->player->p_dir;
		cub->map->player->p_y = y - 1;
	}
}

static void	ft_move_right(t_cub *cub)
{
	int		x;
	int		y;

	x = cub->map->player->p_x;
	y = cub->map->player->p_y;
	if (cub->map->map[x][y + 1] == '0')
	{
		cub->map->map[x][y] = '0';
		cub->map->map[x][y + 1] = cub->map->player->p_dir;
		cub->map->player->p_y = y + 1;
	}
}

void	ft_move_player(int keycode, t_cub *cub)
{
	if (keycode == KEY_W)
		ft_move_up(cub);
	else if (keycode == KEY_S)
		ft_move_down(cub);
	else if (keycode == KEY_A)
		ft_move_left(cub);
	else if (keycode == KEY_D)
		ft_move_right(cub);
	ft_image_hub(cub);
}
