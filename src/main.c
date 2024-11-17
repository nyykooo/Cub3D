/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:09:38 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/17 18:46:11 by ncampbel         ###   ########.fr       */
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
	else
	{
		if (ft_parse_input(av[1]))
			return (0);
		else
			return (1);
	}
	return (0);
}
