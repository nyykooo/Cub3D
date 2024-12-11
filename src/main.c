/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:09:38 by ncampbel          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/12/04 15:51:35 by ncampbel         ###   ########.fr       */
=======
/*   Updated: 2024/12/10 19:13:24 by brunhenr         ###   ########.fr       */
>>>>>>> bruno
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.h"

int	main(int ac, char **av)
{
	t_cub	*cub;

	ft_input_validation(av, ac);
	ft_input_parse(av, ac);
	cub = ft_init_cub();
	ft_init_mlx(cub);
	ft_mlx_hook_and_loop(cub);
	return (0);
}
