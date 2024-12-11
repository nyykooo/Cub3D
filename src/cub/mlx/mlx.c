/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:50:13 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/11 18:21:47 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

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
{
	cub->mlx_ptr = mlx_init();
	if (!cub->mlx_ptr)
	{
		ft_clear_cub();
		perror("Error: mlx_init"); //colocar a perror dentro do contexto das nossas msg de erro
		exit (1);
	}
	ft_get_tex_imgs(cub, cub->map->texture);
	cub->win = mlx_new_window(cub->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
	if (!cub->win)
	{
		ft_clear_cub();
		perror("Error: mlx_new_window");
		exit (1);
	}
	cub->img = mlx_new_image(cub->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!cub->img)
	{
		ft_clear_cub();
		perror("Error: mlx_new_image");
		exit (1);
	}
}

void	ft_mlx_getdata_and_loop(t_cub *cub)
{
	cub->addr = mlx_get_data_addr(cub->img, &cub->bpp, \
	&cub->line_lenght, &cub->endian);
	if (!cub->addr)
	{
		ft_clear_cub();
		perror("Error: mlx_get_data_addr");
		exit (1);
	}
	mlx_hook (cub->win, 17, 0, ft_close_x, cub);
	mlx_hook (cub->win, 2, KeyPressMask, ft_keys, cub);
	mlx_key_hook (cub->win, ft_keys, cub); 
	mlx_expose_hook(cub->win, ft_ray_casting, cub);
	//mlx_loop_hook(); //tiago indicou o uso (estudar) é o loop do game. Para atualizar a tela.
	mlx_loop (cub->mlx_ptr);
}




