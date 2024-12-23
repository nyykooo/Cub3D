/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helmet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:47:16 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/23 11:47:23 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

void	ft_print_h_pixel( t_image *img, int x, int y, float scale)
{
	t_cub	*cub;
	int		tex_x;
	int		tex_y;

	cub = ft_get_cub();
	tex_x = x * scale;
	tex_y = y * scale;
	if (img->tex[tex_x][tex_y] != NONE)
		if (img->print_y + y >= 0 && img->print_y + y < SCREEN_HEIGHT)
			ft_my_mlx_pixel_put(cub, img->print_x + x, img->print_y + y, img->tex[tex_x][tex_y]);
}

void	ft_draw_h_image(t_image *img, int n_w, int n_h, float scale)
{
	int			y;
	int			x;

	y = -1;
	while (++y < n_h)
	{
		x = -1;
		while (++x < n_w)
			ft_print_h_pixel(img, x, y, scale);
	}
}

// 		ft_draw_helmet(cub->map->player->helmet, HELMET_WIDTH, HELMET_HEIGHT, scale * 0.015);
void	ft_draw_helmet(t_image *helmet, int x, int y, float scale)
{
	helmet->print_x = x;
	helmet->print_y = y;
	ft_draw_h_image(helmet, HELMET_WIDTH / scale, HELMET_HEIGHT / scale, scale);
}
