/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:34:59 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/23 11:47:05 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

void	ft_draw_square(t_cub *cub, int x, int y, float scale, int color)
{
	int	i;
	int	j;

	i = 0;
	if (color == -1)
		return ;
	while (i < scale)
	{
		j = 0;
		while (j < scale)
		{
			ft_my_mlx_pixel_put(cub, x + i, y + j, color);
			j++;
		}
		i++;
	}
}


void	ft_draw_minimap(t_cub *cub, t_player *player)
{
	int		i;
	int		j;
	int		x;
	int		y;
	float	scale;

	(void)player;
	scale = (SCREEN_WIDTH / 2) / (cub->map->cols + cub->map->rows);
	ft_map_move(cub);
	i = 0;
	while (i < (int)cub->map->rows)
	{
		j = 0;
		while (j < (int)cub->map->cols)
		{
			x = j * scale;
			y = i * scale;
			if (cub->map->map[i][j] == '1')
				ft_draw_square(cub, x, y, scale, 0x000000);
			else if (cub->map->map[i][j] == '0')
				ft_draw_square(cub, x, y, scale, 0xFFFFFF);
			else if (cub->map->map[i][j] == '2')
				ft_draw_square(cub, x, y, scale, 0xFF0000);
			else if (cub->map->map[i][j] == 'N' || cub->map->map[i][j] == 'S'
				|| cub->map->map[i][j] == 'E' || cub->map->map[i][j] == 'W')
				ft_draw_square(cub, x, y, scale, 0xFF0000);
			else
				ft_draw_square(cub, x, y, scale, -1);
			j++;
		}
		i++;
	}
}
