/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:45:12 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/17 19:06:49 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

static bool	ft_validate_extension(char *name)
{
	int	len;

	len = ft_strlen(name);
	while (len > 0)
	{
		if (name[len] == '.')
		{
			if (ft_strcmp(&name[len], ".cub") == 0)
			{
				return (true);
			}
			else
			{
				ERROR_PRINT(ERROR_MSG(4, ERROR_EXT, name, "\"\n"), 1);
				return (false);
			}
		}
		len--;
	}
	ERROR_PRINT(ERROR_MSG(4, ERROR_EXT, name, "\"\n"), 1);
	return (false);
}

static bool	ft_open_file(char *input)
{
	int	fd;

	fd = open(input, O_RDONLY);
	if (fd == -1)
	{
		ERROR_PRINT(ERROR_MSG(3, ERROR_OPEN, input, "\"\n"), 1);
		return (false);
	}
	close (fd);
	return (true);
}

bool	ft_parse_input(char *input)
{
	if (ft_validate_extension(input))
	{
		printf("Extension validated\n");
	}
	if (ft_open_file(input))
	{
		printf("File opened successfully\n");
		return (true);
	}
	return (false);
}