/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:50:13 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/17 10:41:10 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

int	ft_mouse(int x, int y, t_cub *cub)
{
	t_player	*player;

	player = cub->map->player;
	(void)y;
	if (cub->mouse_x < x)
	{
		ft_rotate_right(player, cub);
		if (!ft_perpendicular_vect(player->dirVector, player->camVector))
			ERROR_PRINT(ERROR_MSG(1, ERROR_VECTORS), 1);
		ft_ray_casting(cub);
	}
	else if (cub->mouse_x > x)
	{
		ft_rotate_left(player, cub);
		if (!ft_perpendicular_vect(player->dirVector, player->camVector))
			ERROR_PRINT(ERROR_MSG(1, ERROR_VECTORS), 1);
		ft_ray_casting(cub);
	}
	cub->mouse_x = x;
	return (0);
}

void	ft_my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return;
	dst = cub->addr + (y * cub->line_lenght + x * (cub->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_init_mlx(t_cub *cub)
{
	cub->mlx_ptr = mlx_init();
	if (!cub->mlx_ptr)
		ERROR_PRINT(ERROR_MSG(1, ERROR_MLX), 1);
	cub->win = mlx_new_window(cub->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
	if (!cub->win)
		ERROR_PRINT(ERROR_MSG(1, ERROR_WIN), 1);
	ft_get_tex_imgs(cub, cub->map->texture);
	ft_image_hub(cub);
}

void	ft_mlx_hook_and_loop(t_cub *cub)
{
	cub->mouse_x = SCREEN_WIDTH / 2;
	mlx_hook(cub->win, 6, PointerMotionMask, ft_mouse, cub);
	mlx_hook (cub->win, 17, 0, ft_close_x, cub);
	mlx_hook (cub->win, 2, KeyPressMask, ft_keys, cub);
	mlx_key_hook (cub->win, ft_keys, cub); 
	mlx_expose_hook(cub->win, ft_ray_casting, cub);
	//mlx_loop_hook(); //tiago indicou o uso (estudar) é o loop do game. Para atualizar a tela.
	mlx_loop (cub->mlx_ptr);
}
