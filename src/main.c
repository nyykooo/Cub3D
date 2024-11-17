/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:09:38 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/17 18:08:56 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.h"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		ERROR_PRINT(ERROR_MSG(1, ERROR_AC), 1);
		return (1);
	}
	if (ft_strlen(av[1]) > 10)
	{
		ERROR_PRINT(ERROR_MSG(2, "Error: Argument too long\n"), 1);
		return (1);
	}
	return (0);
}
