/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:50:13 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/04 15:38:45 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	ft_init_mlx(t_cub *cub)
{
	cub->mlx_ptr = mlx_init();
	if (!cub->mlx_ptr)
		ERROR_PRINT(ERROR_MSG(1, ERROR_MLX), 1);
	cub->win = MLX_NW(cub->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
	if (!cub->win)
		ERROR_PRINT(ERROR_MSG(1, ERROR_WIN), 1);
	ft_image_hub(cub);
}

void	ft_mlx_hook_and_loop(t_cub *cub)
{
	mlx_hook(cub->win, 2, 1L << 0, ft_game_keys, cub);
	mlx_hook (cub->win, 17, 0, ft_close_x, cub);
	//mlx_key_hook (cub->win, keys, cub); 
	//mlx_expose_hook(cub->win, redraw, cub);
	//mlx_loop_hook(); //tiago indicou o uso (estudar)
	mlx_loop (cub->mlx_ptr);
}
