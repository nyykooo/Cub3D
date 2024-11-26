/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed_hole.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:59:32 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/26 18:36:25 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	ft_fcol_fline(char **map, int col, int row)
{
	if ((map[row][col + 1] == '1' || map[row][col + 1] == ' ') && \
		(map[row + 1][col] == '1' || map[row + 1][col] == ' ') && \
		(map[row + 1][col + 1] == '1' || map[row + 1][col + 1] == ' '))
		return ;
	else
		ERROR_PRINT(ERROR_MSG(1, ERROR_MAP_CLOSE), 1);
}

void	ft_fcol_lline(char **map, int col, int row)
{
	if ((map[row][col + 1] == '1' || map[row][col + 1] == ' ') && \
	(map[row - 1][col] == '1' || map[row - 1][col] == ' ') && \
	(map[row - 1][col + 1] == '1' || map[row - 1][col + 1] == ' '))
		return ;
	else
		ERROR_PRINT(ERROR_MSG(1, ERROR_MAP_CLOSE), 1);
}

void	ft_fline(char **map, int col, int row)
{
	if ((map[row][col - 1] == '1' || map[row][col - 1] == ' ') && \
		(map[row][col + 1] == '1' || map[row][col + 1] == ' '
			|| map[row][col + 1] == '\0') && \
		(map[row + 1][col] == '1' || map[row + 1][col] == ' ') && \
		(map[row + 1][col - 1] == '1' || map[row + 1][col - 1] == ' ') && \
		(map[row + 1][col + 1] == '1' || map[row + 1][col + 1] == ' '
			|| map[row + 1][col + 1] == '\0'))
		return ;
	else
		ERROR_PRINT(ERROR_MSG(1, ERROR_MAP_CLOSE), 1);
}

void	ft_lline(char **map, int col, int row)
{
	if ((map[row][col - 1] == '1' || map[row][col - 1] == ' ') && \
		(map[row][col + 1] == '1' || map[row][col + 1] == ' '
			|| map[row][col + 1] == '\0') && \
		(map[row - 1][col] == '1' || map[row - 1][col] == ' ') && \
		(map[row - 1][col - 1] == '1' || map[row - 1][col - 1] == ' ') && \
		(map[row - 1][col + 1] == '1' || map[row - 1][col + 1] == ' '
			|| map[row - 1][col + 1] == '\0'))
		return ;
	else
		ERROR_PRINT(ERROR_MSG(1, ERROR_MAP_CLOSE), 1);
}

void	ft_fcol(char **map, int col, int row)
{
	if ((map[row][col + 1] == '1' || map[row][col + 1] == ' ') && \
		(map[row - 1][col] == '1' || map[row - 1][col] == ' ') && \
		(map[row - 1][col + 1] == '1' || map[row - 1][col + 1] == ' ') && \
		(map[row + 1][col] == '1' || map[row + 1][col] == ' ') && \
		(map[row + 1][col + 1] == '1' || map[row + 1][col + 1] == ' '))
		return ;
	else
		ERROR_PRINT(ERROR_MSG(1, ERROR_MAP_CLOSE), 1);
}
