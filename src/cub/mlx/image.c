/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:14:37 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/05 21:13:13 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

static void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
    char	*dst;

    if ((x >= 0 && x < SCREEN_WIDTH) && (y >= 0 && y < SCREEN_HEIGHT))
    {
        dst = cub->addr + (y * cub->line_lenght + x * (cub->bpp / 8));
        *(unsigned int *)dst = color;
    }
}

static void	ft_draw_map(t_cub *cub)
{
    unsigned int		i;
    unsigned int		j;
    unsigned int		x;
    unsigned int		y;

    i = -1;
    while (++i < cub->map->rows)
    {
        j = -1;
        while (++j < cub->map->cols)
        {
            y = -1;
            while (++y < 32)
            {
                x = -1;
                while (++x < 32)
                {
                    if (cub->map->map[i][j] == '1')
                        my_mlx_pixel_put(cub, j * 10 + x, i * 10 + y, 0x000000);
                    else if (cub->map->map[i][j] == '0')
                        my_mlx_pixel_put(cub, j * 10 + x, i * 10 + y, 0xFFFFFF);
                    else if (cub->map->map[i][j] == 'N')
                        my_mlx_pixel_put(cub, j * 10 + x, i * 10 + y, 0xFF0000);
                }
            }
        }
    }
    mlx_put_image_to_window(cub->mlx_ptr, cub->win, cub->img, 0, 0);
}

void	ft_image_hub(t_cub *cub)
{
    cub->img = MLX_NI(cub->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!cub->img)
    {
        ERROR_PRINT(ERROR_MSG(1, ERROR_IMG), 1);
        return;
    }
    cub->addr = MLX_GDA(cub->img, &cub->bpp, &cub->line_lenght, &cub->endian);
    if (!cub->addr)
    {
        ERROR_PRINT(ERROR_MSG(1, ERROR_GDA), 1);
        return;
    }
    ft_draw_map(cub);
}
