/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:45:12 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/22 20:32:04 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

static void	ft_validate_arguments(int ac)
{
	if (ac == 2)
		return ;
	else
		ERROR_PRINT(ERROR_MSG(1, ERROR_AC), 1);
}

static void	ft_validate_extension(char *name)
{
	int	len;

	len = ft_strlen(name);
	while (len > 0)
	{
		if (name[len] == '.')
		{
			if (ft_strcmp(&name[len], ".cub") == 0)
			{
				return ;
			}
			else
			{
				ERROR_PRINT(ERROR_MSG(4, ERROR_EXT, name, "\"\n"), 1);
			}
		}
		len--;
	}
	ERROR_PRINT(ERROR_MSG(4, ERROR_EXT, name, "\"\n"), 1);
}

static void	ft_clear(char *line, int fd)
{
	if (line)
		free(line);
	close(fd);
}

static void	ft_open_file(char *input)
{
	char	*line;
	int		fd;

	fd = open(input, O_RDONLY);
	if (fd == -1)
	{
		ft_clear(NULL, fd);
		ERROR_PRINT(ERROR_MSG(3, ERROR_OPEN, input, "\"\n"), 1);
	}
	line = get_next_line(fd);
	if (line == NULL)
	{
		ft_clear(line, fd);
		ERROR_PRINT(ERROR_MSG(3, ERROR_READ, input, "\"\n"), 1);
	}
	ft_clear(line, fd);
}

// confirm later if there is more to look for in the parse intput function and how many arguments the program receives
void	ft_parse_input(char **av, int ac) 
{
	ft_validate_arguments(ac);
	ft_validate_extension(av[1]);
	ft_open_file(av[1]);
}
