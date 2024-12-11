/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:55:45 by brunhenr          #+#    #+#             */
/*   Updated: 2024/12/10 19:51:16 by brunhenr         ###   ########.fr       */
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