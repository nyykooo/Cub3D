/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:44:27 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/02 16:44:56 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

t_cub	*ft_get_cub(void)
{
	static t_cub	cub;

	return (&cub);
}

void	ft_init_cub(void)
{
	t_cub	*cub;

	cub = ft_get_cub();
	ft_alloc_map(cub);
	ft_look_for_invalid_map(cub);
	ft_trim_map(cub);
	ft_call_flood(cub->map);
	ft_check_player(cub->map);
	ft_print_map(cub->map);
	// ft_init_mlx(cub);
}
