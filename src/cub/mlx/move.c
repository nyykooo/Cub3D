/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:47:40 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/12 19:15:49 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	ft_move_forward(t_cub *cub)
{
    t_map	*map;
    int		new_x;
    int		new_y;

    map = cub->map;
    new_x = (int)(map->player->p_x + map->player->dirVector->x);
    new_y = (int)(map->player->p_y + map->player->dirVector->y);

    if (new_x < 0 || new_x >= (int)map->rows || new_y < 0 || new_y >= (int)map->cols)
        return;
    if (ft_is_walkable(map->map[new_x][new_y]))
    {
        map->player->p_x += map->player->dirVector->x;
        map->player->p_y += map->player->dirVector->y;
        ft_ray_casting(cub);
    }
}

void	ft_move_backward(t_cub *cub)
{
    t_map	*map;
    int		new_x;
    int		new_y;

    map = cub->map;
    new_x = (int)(map->player->p_x - map->player->dirVector->x);
    new_y = (int)(map->player->p_y - map->player->dirVector->y);

    if (new_x < 0 || new_x >= (int)map->rows || new_y < 0 || new_y >= (int)map->cols)
        return;

    if (ft_is_walkable(map->map[new_x][new_y]))
    {
        map->player->p_x -= map->player->dirVector->x;
        map->player->p_y -= map->player->dirVector->y;
        ft_ray_casting(cub);
    }
}

void	ft_move_right(t_cub *cub)
{
    t_map	*map;
    int		new_x;
    int		new_y;

    map = cub->map;
    new_x = (int)(map->player->p_x + map->player->dirVector->y);
    new_y = (int)(map->player->p_y - map->player->dirVector->x);

    if (new_x < 0 || new_x >= (int)map->rows || new_y < 0 || new_y >= (int)map->cols)
        return;

    if (ft_is_walkable(map->map[new_x][new_y]))
    {
        map->player->p_x += map->player->dirVector->y;
        map->player->p_y -= map->player->dirVector->x;
        ft_ray_casting(cub);
    }
}

void	ft_move_left(t_cub *cub)
{
    t_map	*map;
    int		new_x;
    int		new_y;

    map = cub->map;
    new_x = (int)(map->player->p_x - map->player->dirVector->y);
    new_y = (int)(map->player->p_y + map->player->dirVector->x);

    if (new_x < 0 || new_x >= (int)map->rows || new_y < 0 || new_y >= (int)map->cols)
        return;

    if (ft_is_walkable(map->map[new_x][new_y]))
    {
        map->player->p_x -= map->player->dirVector->y;
        map->player->p_y += map->player->dirVector->x;
        ft_ray_casting(cub);
    }
}
