/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:32:07 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/26 18:33:02 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	ft_check_first_last(char *line, int row)
{
	int		col;

	col = -1;
	while (line[++col])
	{
		if (line[col] == '0')
			ERROR_PRINT(ERROR_MSG(1, ERROR_MAP_CLOSE), 1);
		else if (line[col] == ' ')
			ft_check_hole(col, row);
	}
}

void	ft_check_line(char *line, int row)
{
	int		len;
	int		col;

	len = ft_strlen(line);
	if (line[0] != '1' || line[len - 1] != '1')
		ERROR_PRINT(ERROR_MSG(1, ERROR_MAP_CLOSE), 1);
	col = -1;
	while (line[++col])
	{
		if (line[col] == ' ')
			ft_check_hole(col, row);
	}
}
