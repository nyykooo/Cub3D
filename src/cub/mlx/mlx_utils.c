/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:55:45 by brunhenr          #+#    #+#             */
/*   Updated: 2024/12/19 15:27:09 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	clear_image(t_cub *cub, int color)
{
	int		x;
	int		y;
	char	*dst;

	for (y = 0; y < SCREEN_HEIGHT; y++)
	{
		for (x = 0; x < SCREEN_WIDTH; x++)
		{
			dst = cub->addr + (y * cub->line_length + x * (cub->bpp / 8));
			*(unsigned int *)dst = color;
		}
	}
}

void	ft_draw_vertical_line(int x, int drawStart, int drawEnd, t_cub *cub, int *buffer)
{
	int	color;
	int	i;

	i = 0;
	while (i < drawStart)
		ft_my_mlx_pixel_put(cub, x, i++, cub->map->texture->ceiling->color);
	i = 0;
	while (drawStart < drawEnd)
	{
		color = buffer[i];
		ft_my_mlx_pixel_put(cub, x, drawStart, color);
		drawStart++;
		i++;
	}
	while (drawEnd < SCREEN_HEIGHT)
		ft_my_mlx_pixel_put(cub, x, drawEnd++, cub->map->texture->floor->color);
}

int	**ft_get_image_pixels(t_img *img, int w, int h)
{
	int	**pixels;
	int	x;
	int	y;

	x = 0;
	pixels = malloc(w * sizeof(int *));
	while (x < w)
	{
		pixels[x] = malloc(h * sizeof(int));
		x++;
	}
	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			pixels[x][y] = *(int *)(img->data + y * img->size_line \
			+ x * (img->bpp / 8));
			x++;
		}
		y++;
	}
	return (pixels);
}
