/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:38:34 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/25 19:38:41 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

void	ft_print_map(t_map *map)
{
	int	i;

	printf("TEXTURES\n");
	printf("NO: %s\n", map->texture->north);
	printf("SO: %s\n", map->texture->south);
	printf("WE: %s\n", map->texture->west);
	printf("EA: %s\n", map->texture->east);
	printf("COLORS\n");
	printf("C: %s\n", map->texture->ceiling);
	printf("F: %s\n", map->texture->floor);
	printf("\nMAP\n");
	i = 0;
	while (i < map->rows)
	{
		printf("%s\n", map->map[i]);
		i++;
	}
}