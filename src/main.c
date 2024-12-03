/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:09:38 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/03 08:12:52 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.h"

int	main(int ac, char **av)
{
	t_cub	*cub;

	ft_input_validation(av, ac);
	ft_input_parse(av, ac);

	cub = ft_init_cub();
    // if (cub->fd != -1)
	// 	close(cub->fd);
	// if (cub->file)
	// 	free(cub->file);
    // if (cub->line)
	// 	free(cub->line);
	
	ft_mlx_inicialization(cub);
	ft_mlx_getdata_and_loop(cub);
	return (0);
}