/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:09:38 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/16 22:42:40 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.h"

int	main(int ac, char **av)
{
	t_cub	*cub;

	ft_input_validation(av, ac);
	ft_input_parse(av, ac);
	cub = ft_init_cub();

	cub->time = 0;
	cub->old_time = 0;
	// gettimeofday(&tv, NULL);
	// cub->time = tv.tv_sec + tv.tv_usec / 1000000.0;
	// printf("TIME: %f\n", cub->time);

	// gettimeofday(&tv, NULL);
	// cub->time = tv.tv_sec + tv.tv_usec / 1000000.0;
	// printf("TIME: %f\n", cub->time);

	//ft_clear_cub();
	ft_mlx_inicialization(cub);
	ft_mlx_getdata_and_loop(cub);
	return (0);
}