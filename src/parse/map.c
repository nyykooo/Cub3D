/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:54:54 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/22 20:35:32 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

void	ft_parse_map(char *name)
{
	t_cub	*cub;
	char	*line;
	int		fd;

	cub = ft_get_cub();
	fd = open(name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		cub->map->rows++;
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
}
