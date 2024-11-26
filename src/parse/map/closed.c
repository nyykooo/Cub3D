/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:58:07 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/26 20:58:50 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	ft_lcol(char **map, int col, int row)
{
	if ((map[row][col - 1] == '1' || map[row][col - 1] == ' ') && \
		(map[row - 1][col] == '1' || map[row - 1][col] == ' ') && \
		(map[row - 1][col - 1] == '1' || map[row - 1][col - 1] == ' ') && \
		(map[row + 1][col] == '1' || map[row + 1][col] == ' ') && \
		(map[row + 1][col - 1] == '1' || map[row + 1][col - 1] == ' '))
		return ;
	else
		ERROR_PRINT(ERROR_MSG(1, ERROR_MAP_CLOSE), 1);
}

void	ft_middle(char **map, int col, int row)
{
	if ((map[row][col - 1] == '1' || map[row][col - 1] == ' ') && \
		(map[row][col + 1] == '1' || map[row][col + 1] == ' ') && \
		(map[row - 1][col] == '1' || map[row - 1][col] == ' ') && \
		(map[row + 1][col] == '1' || map[row + 1][col] == ' ') && \
		(map[row - 1][col - 1] == '1' || map[row - 1][col - 1] == ' ') && \
		(map[row - 1][col + 1] == '1' || map[row - 1][col + 1] == ' ') && \
		(map[row + 1][col - 1] == '1' || map[row + 1][col - 1] == ' ') && \
		(map[row + 1][col + 1] == '1' || map[row + 1][col + 1] == ' '))
		return ;
	else
		ERROR_PRINT(ERROR_MSG(1, ERROR_MAP_CLOSE), 1);
}

void	ft_check_hole(int col, int row)
{
	t_cub	*cub;
	char	**map;

	cub = ft_get_cub();
	map = cub->map->map;
	if (col == 0 && row == 0)
		ft_fcol_fline(map, col, row);
	else if (col == 0 && row == cub->map->rows - 1)
		ft_fcol_lline(map, col, row);
	else if (row == 0)
		ft_fline(map, col, row);
	else if (row == cub->map->rows - 1)
		ft_lline(map, col, row);
	else if (col == 0)
		ft_fcol(map, col, row);
	else if (col == cub->map->cols - 1)
		ft_lcol(map, col, row);
	else
		ft_middle(map, col, row);
}

void	ft_closed_map(t_cub *cub)
{
	int		i;

	i = -1;
	while (++i < cub->map->rows)
	{
		if (i == 0 || i == cub->map->rows - 1)
			ft_check_first_last(cub->map->map[i], i);
		else
			ft_check_line(cub->map->map[i], i);
	}
}
