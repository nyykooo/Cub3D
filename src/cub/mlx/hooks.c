/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:11:30 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/05 21:50:52 by ncampbel         ###   ########.fr       */
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
