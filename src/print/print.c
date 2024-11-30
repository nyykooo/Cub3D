/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:38:34 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/30 13:51:13 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

void	ft_print_map(t_map *map)
{
	unsigned int	i;

	printf("TEXTURES\n");
	printf("NO: %s\n", map->texture->north);
	printf("SO: %s\n", map->texture->south);
	printf("WE: %s\n", map->texture->west);
	printf("EA: %s\n", map->texture->east);
	printf("COLORS\n");
	printf("C: %s\n", map->texture->ceiling->input);
	printf("F: %s\n", map->texture->floor->input);
	printf("\nMAP\n");
	i = 0;
	while (i < map->rows)
	{
		printf("%s\n", map->map[i]);
		i++;
	}
	printf("\nFLOODED MAP\n");
	i = 0;
	while (i < map->rows)
	{
		printf("%s\n", map->ff_map[i]);
		i++;
	}

	printf("\nPLAYER\n");
	printf("X: %d\n", map->player->p_x);
	printf("Y: %d\n", map->player->p_y);
	printf("DIR: %c\n", map->player->p_dir);
}
