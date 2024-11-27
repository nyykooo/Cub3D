/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:46:29 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/27 21:00:20 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

static void	ft_analyze_cell(t_map *map, int col, int row)
{
	if ((col >= 0 || col < (int)ft_strlen(map->map[row])
			|| row >= 0 || row < map->rows ) &&
		(map->map[row][col] == ' ' || map->map[row][col] == 0))
		return ;
}

static void	ft_floodfill(t_map *map, int col, int row)
{
	if (col < 0 || col >= (int)ft_strlen(map->map[row])
		|| row < 0 || row >= map->rows || map->map[row][col] == ' '
		|| map->map[row][col] == '1' || map->map[row][col] == 'x'
		|| map->map[row][col] == 0)
	{
		ft_analyze_cell(map, col, row);
		return ;
	}
	map->map[row][col] = 'x';
	ft_floodfill(map, col + 1, row);
	ft_floodfill(map, col - 1, row);
	ft_floodfill(map, col, row + 1);
	ft_floodfill(map, col, row - 1);
}

void	ft_call_flood(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < (int)ft_strlen(map->map[i]))
		{
			if (map->map[i][j] == '0')
				ft_floodfill(map, j, i);
			j++;
		}
		i++;
	}
}
