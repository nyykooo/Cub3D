/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:47:40 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/17 00:23:15 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	ft_move_forward(t_cub *cub)
{
    t_map	*map;
    int		new_x;
    int		new_y;

    map = cub->map;
    new_x = (int)(map->player->p_x + (map->player->dirVector->x * cub->frameTime.move_speed));
    new_y = (int)(map->player->p_y + (map->player->dirVector->y * cub->frameTime.move_speed));

    if (new_x < 0 || new_x >= (int)map->rows || new_y < 0 || new_y >= (int)map->cols)
        return;
    if (ft_is_walkable(map->map[new_x][new_y]))
    {
        map->player->p_x += map->player->dirVector->x * cub->frameTime.move_speed;
        map->player->p_y += map->player->dirVector->y * cub->frameTime.move_speed;
        ft_ray_casting(cub);
    }
}

void	ft_move_backward(t_cub *cub)
{
    t_map	*map;
    int		new_x;
    int		new_y;

    map = cub->map;
    new_x = (int)(map->player->p_x - (map->player->dirVector->x * cub->frameTime.move_speed));
    new_y = (int)(map->player->p_y - (map->player->dirVector->y * cub->frameTime.move_speed));

    if (new_x < 0 || new_x >= (int)map->rows || new_y < 0 || new_y >= (int)map->cols)
        return;

    if (ft_is_walkable(map->map[new_x][new_y]))
    {
        map->player->p_x -= map->player->dirVector->x * cub->frameTime.move_speed;
        map->player->p_y -= map->player->dirVector->y * cub->frameTime.move_speed;
        ft_ray_casting(cub);
    }
}

void	ft_move_right(t_cub *cub)
{
    t_map	*map;
    int		new_x;
    int		new_y;

    map = cub->map;
    new_x = (int)(map->player->p_x + (map->player->dirVector->y * cub->frameTime.move_speed));
    new_y = (int)(map->player->p_y - (map->player->dirVector->x * cub->frameTime.move_speed));

    if (new_x < 0 || new_x >= (int)map->rows || new_y < 0 || new_y >= (int)map->cols)
        return;

    if (ft_is_walkable(map->map[new_x][new_y]))
    {
        map->player->p_x += map->player->dirVector->y * cub->frameTime.move_speed;
        map->player->p_y -= map->player->dirVector->x * cub->frameTime.move_speed;
        ft_ray_casting(cub);
    }
}

void	ft_move_left(t_cub *cub)
{
    t_map	*map;
    int		new_x;
    int		new_y;

    map = cub->map;
    new_x = (int)(map->player->p_x - (map->player->dirVector->y * cub->frameTime.move_speed));
    new_y = (int)(map->player->p_y + (map->player->dirVector->x * cub->frameTime.move_speed));

    if (new_x < 0 || new_x >= (int)map->rows || new_y < 0 || new_y >= (int)map->cols)
        return;

    if (ft_is_walkable(map->map[new_x][new_y]))
    {
        map->player->p_x -= map->player->dirVector->y * cub->frameTime.move_speed;
        map->player->p_y += map->player->dirVector->x * cub->frameTime.move_speed;
        ft_ray_casting(cub);
    }
}
