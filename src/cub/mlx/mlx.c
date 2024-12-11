/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:50:13 by ncampbel          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/12/04 17:31:29 by ncampbel         ###   ########.fr       */
=======
/*   Updated: 2024/12/10 19:51:51 by brunhenr         ###   ########.fr       */
>>>>>>> bruno
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

<<<<<<< HEAD
void	ft_init_mlx(t_cub *cub)
=======
void	ft_my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	// if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
	// {
	// 	write (2, "Error: my_mlx_pixel_put\n", 24);
	// 	return;
	// }
	// if (!cub->addr)
	// {
	// 	perror("Error: cub->addr is not initialized");
	// 	return;
	// }
	
	dst = cub->addr + (y * cub->line_lenght + x * (cub->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_mlx_inicialization(t_cub *cub)
>>>>>>> bruno
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
<<<<<<< HEAD
	mlx_hook(cub->win, 2, 1L << 0, ft_game_keys, cub);
=======
	cub->addr = mlx_get_data_addr(cub->img, &cub->bpp, \
	&cub->line_lenght, &cub->endian);
	if (!cub->addr)
	{
		ft_clear_cub();
		perror("Error: mlx_get_data_addr");
		exit (1);
	}
>>>>>>> bruno
	mlx_hook (cub->win, 17, 0, ft_close_x, cub);
	mlx_hook (cub->win, 2, KeyPressMask, ft_keys, cub);
	mlx_key_hook (cub->win, ft_keys, cub); 
	mlx_expose_hook(cub->win, ft_ray_casting, cub);
	//mlx_loop_hook(); //tiago indicou o uso (estudar) é o loop do game. Para atualizar a tela.
	mlx_loop (cub->mlx_ptr);
}
<<<<<<< HEAD
=======




>>>>>>> bruno
