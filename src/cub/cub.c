/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:44:27 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/22 23:47:09 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

t_cub	*ft_get_cub(void)
{
	static t_cub	cub;

	return (&cub);
}

void	ft_init_cub(char *av)
{
	t_cub	*cub;

	cub = ft_get_cub();
	ft_init_map(cub);
	ft_parse_map(av);
	printf("Rows: %d\n", cub->map->rows);
}
