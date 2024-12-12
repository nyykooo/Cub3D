/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:47:40 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/11 18:00:00 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	ft_move_forward(t_cub *cub)
{
	t_map	*map;

	map = cub->map;
	if (map->rows <= (unsigned int)(map->player->p_x + map->player->dirVector->x) || map->cols <= (unsigned int)(map->player->p_y + map->player->dirVector->y))
		return ;
	if (ft_is_walkable(cub->map->map[(int)cub->map->player->p_x + (int)cub->map->player->dirVector->x][(int)cub->map->player->p_y]))
	{
		cub->map->player->p_x += cub->map->player->dirVector->x;
		if (ft_is_walkable(cub->map->map[(int)cub->map->player->p_x][(int)cub->map->player->p_y + (int)cub->map->player->dirVector->y]))
		{
			cub->map->player->p_y += cub->map->player->dirVector->y;
			ft_ray_casting(cub);
		}
		else
			return ;
	}
	else
		return ;
}

void	ft_move_backward(t_cub *cub)
{
	t_map	*map;

	map = cub->map;
	if (map->rows <= (unsigned int)(map->player->p_x + map->player->dirVector->x) || map->cols <= (unsigned int)(map->player->p_y + map->player->dirVector->y))
		return ;
	if (ft_is_walkable(cub->map->map[(int)cub->map->player->p_x - (int)cub->map->player->dirVector->x][(int)cub->map->player->p_y]))
	{
		cub->map->player->p_x -= cub->map->player->dirVector->x;
		if (ft_is_walkable(cub->map->map[(int)cub->map->player->p_x][(int)cub->map->player->p_y - (int)cub->map->player->dirVector->y]))
		{
			cub->map->player->p_y -= cub->map->player->dirVector->y;
			ft_ray_casting(cub);
		}
		else
			return ;
	}
	else
		return ;
}

void	ft_move_right(t_cub *cub)
{
	t_map	*map;

	map = cub->map;
	if (map->rows <= (unsigned int)(map->player->p_x + map->player->dirVector->y) || map->cols <= (unsigned int)(map->player->p_y - map->player->dirVector->x))
		return ;
	if (ft_is_walkable(cub->map->map[(int)cub->map->player->p_x + (int)cub->map->player->dirVector->y][(int)cub->map->player->p_y - (int)cub->map->player->dirVector->x]))
	{
		cub->map->player->p_x += cub->map->player->dirVector->y;
		if (ft_is_walkable(cub->map->map[(int)cub->map->player->p_x - (int)cub->map->player->dirVector->x][(int)cub->map->player->p_y - (int)cub->map->player->dirVector->y]))
		{
			cub->map->player->p_y -= cub->map->player->dirVector->x;
			ft_ray_casting(cub);
		}
		else
			return ;
	}
	else
		return ;
}

void	ft_move_left(t_cub *cub)
{
	t_map	*map;

	map = cub->map;
	if (map->rows <= (unsigned int)(map->player->p_x - map->player->dirVector->y) || map->cols <= (unsigned int)(map->player->p_y + map->player->dirVector->x))
		return ;
	if (ft_is_walkable(cub->map->map[(int)cub->map->player->p_x - (int)cub->map->player->dirVector->y][(int)cub->map->player->p_y + (int)cub->map->player->dirVector->x]))
	{
		cub->map->player->p_x -= cub->map->player->dirVector->y;
		if (ft_is_walkable(cub->map->map[(int)cub->map->player->p_x + (int)cub->map->player->dirVector->x][(int)cub->map->player->p_y + (int)cub->map->player->dirVector->y]))
		{
			cub->map->player->p_y += cub->map->player->dirVector->x;
			ft_ray_casting(cub);
		}
		else
			return ;
	}
	else
		return ;
}
