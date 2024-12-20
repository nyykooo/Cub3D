/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:55:45 by brunhenr          #+#    #+#             */
/*   Updated: 2024/12/19 16:43:39 by brunhenr         ###   ########.fr       */
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

void	ft_draw_vertical_line(int x, t_column *column, t_cub *cub)
{
	int	color;
	int	i;

	i = 0;
	while (i < column->draw_start)
		ft_my_mlx_pixel_put(cub, x, i++, cub->map->texture->ceiling->color);
	i = 0;
	while (column->draw_start < column->draw_end)
	{
		color = column->buffer[i];
		ft_my_mlx_pixel_put(cub, x, column->draw_start, color);
		column->draw_start++;
		i++;
	}
	while (column->draw_end < SCREEN_HEIGHT)
		ft_my_mlx_pixel_put(cub, x, column->draw_end++, cub->map->texture->floor->color);
}

int	**ft_get_image_pixels(t_img *img)
{
	int	**pixels;
	int	x;
	int	y;

	x = 0;
	pixels = malloc(TEX_WIDTH * sizeof(int *));
	while (x < TEX_WIDTH)
	{
		pixels[x] = malloc(TEX_HEIGHT * sizeof(int));
		x++;
	}
	y = 0;
	while (y < TEX_HEIGHT)
	{
		x = 0;
		while (x < TEX_WIDTH)
		{
			pixels[x][y] = *(int *)(img->data + y * img->size_line \
			+ x * (img->bpp / 8));
			x++;
		}
		y++;
	}
	return (pixels);
}
