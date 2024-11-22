/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:44:27 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/22 20:29:50 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.h"

t_cub	*ft_get_cub(void)
{
	static t_cub	cub;

	return (&cub);
}

void	ft_init_cub(char *av)
{
	t_cub	*cub;

	cub = ft_get_cub();
	cub->map = (t_map *)malloc(sizeof(t_map));
	if (!cub->map)
		ft_put_error_msg("Malloc failed", 1);
	cub->map->rows = 0;
	cub->map->cols = 0;
	ft_parse_map(av);
	printf("Rows: %d\n", cub->map->rows);
}
