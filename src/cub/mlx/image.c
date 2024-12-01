/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:14:37 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/01 18:38:56 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	ft_image_hub(t_cub *cub)
{
	cub->img_ptr = mlx_new_image(cub->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!cub->img_ptr)
		ERROR_PRINT(ERROR_MSG(1, ERROR_IMG), 1);
	cub->addr = mlx_get_data_addr(cub->img_ptr, &cub->bpp, 
			&cub->line_len, &cub->endian);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img_ptr, 0, 0);
}
