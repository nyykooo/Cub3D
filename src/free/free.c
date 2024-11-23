/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:43:29 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/23 00:11:23 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

void	ft_clear_cub(void)
{
	t_cub	*cub;

	cub = ft_get_cub();
	if (cub->file)
		free(cub->file);
	if (cub->map)
		ft_clear_map(cub->map);
}

void	ft_clear_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->map)
	{
		while (i < map->rows)
		{
			if (map->map[i])
				free(map->map[i]);
			i++;
		}
		free(map->map);
	}
	if (map->path)
		free(map->path);
	if (map)
		free(map);
}
