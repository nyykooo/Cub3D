/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:55:45 by brunhenr          #+#    #+#             */
/*   Updated: 2024/12/11 16:03:25 by brunhenr         ###   ########.fr       */
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
			dst = cub->addr + (y * cub->line_lenght + x * (cub->bpp / 8));
			*(unsigned int *)dst = color;
		}
	}
}

void	ft_draw_vertical_line(int x, int drawStart, int drawEnd, t_cub *cub)
{
	int	color;

	color = cub->map->texture->untex;
	if (drawStart < 0)
		drawStart = 0;
	if (drawEnd >= SCREEN_HEIGHT)
		drawEnd = SCREEN_HEIGHT - 1;
	while (drawStart <= drawEnd)
	{
		ft_my_mlx_pixel_put(cub, x, drawStart, color);
		drawStart++;
	}
}

int	*ft_get_image_pixels(t_img *img)
{
	int *pixels;
	int x;
	int	y;
	int pixel_index;

	pixels = malloc(sizeof(int) * TEX_HEIGHT * TEX_WIDTH);
    for (y = 0; y < TEX_HEIGHT; y++)
    {
        for (x = 0; x < TEX_WIDTH; x++)
        {
            pixel_index = y * TEX_WIDTH + x;
            pixels[pixel_index] = *(int *)(img->data + y * img->size_line + x * (img->bpp / 8));
        }
    }

    return (pixels);
}

