/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:49:58 by brunhenr          #+#    #+#             */
/*   Updated: 2024/12/17 15:09:37 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:47:40 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/17 14:48:56 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

#define COLLISION_MARGIN 0.5

int	is_colliding(t_map *map, double x, double y)
{
	int grid_x = (int)floor(x);
	int grid_y = (int)floor(y);

	if (grid_x < 0 || grid_x >= (int)map->rows || grid_y < 0 || grid_y >= (int)map->cols)
		return 1;

	return (!ft_is_walkable(map->map[grid_x][grid_y]));
}

int	is_colliding_with_margin(t_map *map, double x, double y)
{
	return (is_colliding(map, x + COLLISION_MARGIN, y + COLLISION_MARGIN) || \
	is_colliding(map, x + COLLISION_MARGIN, y - COLLISION_MARGIN) || \
	is_colliding(map, x - COLLISION_MARGIN, y + COLLISION_MARGIN) || \
	is_colliding(map, x - COLLISION_MARGIN, y - COLLISION_MARGIN));
}

void	ft_move_forward(t_cub *cub)
{
    t_map	*map;
    int		new_x;
    int		new_y;

    map = cub->map;
    new_x = (int)(map->player->p_x + (map->player->dirVector->x * cub->frameTime.move_speed));
    new_y = (int)(map->player->p_y + (map->player->dirVector->y * cub->frameTime.move_speed));

	if (!is_colliding_with_margin(map, new_x, new_y))
    {
        map->player->p_x = new_x;
        map->player->p_y = new_y;
        ft_ray_casting(cub);
    }
    else
    {
        system("printf '\\a'");
    }

    // if (new_x < 0 || new_x >= (int)map->rows || new_y < 0 || new_y >= (int)map->cols)
	// {
	// 	system("printf \"\\a\"");
    //     return;
	// }
    // if (ft_is_walkable(map->map[new_x][new_y]))
    // {
    //     map->player->p_x += map->player->dirVector->x * cub->frameTime.move_speed;
    //     map->player->p_y += map->player->dirVector->y * cub->frameTime.move_speed;
    //     ft_ray_casting(cub);
    // }
	// else
	// 	system("printf \"\\a\"");
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
