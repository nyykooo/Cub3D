/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:39:18 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/13 15:59:46 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

static void	ft_check_errors(t_cub *cub, char *color)
{
	if (strcmp(color, "F") == 0)
	{
		if (cub->map->texture->floor->red == -1
			|| cub->map->texture->floor->green == -1
			|| cub->map->texture->floor->blue == -1)
			ERROR_PRINT(ERROR_MSG(1, ERROR_NULL_TEXT), 1);
	}
	else if (strcmp(color, "C") == 0)
	{
		if (cub->map->texture->ceiling->red == -1
			|| cub->map->texture->ceiling->green == -1
			|| cub->map->texture->ceiling->blue == -1)
			ERROR_PRINT(ERROR_MSG(1, ERROR_NULL_TEXT), 1);
	}
}

static void	ft_prepare_line(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (ft_isspace(line[i]))
			line[i] = ',';
}

static void	ft_check_dup_color(t_color *color, char *line)
{
	if (color->input)
		free(color->input);
	color->input = ft_strdup(line);
}

static void	ft_get_color(t_cub *cub, char *line)
{
	t_texture	*texture;
	char		**split;

	split = ft_split(line, ',');
	texture = cub->map->texture;
	if (!split)
		ERROR_PRINT(ERROR_MSG(1, ERROR_SPLIT), 1);
	if (ft_strcmp(split[0], "F") == 0)
	{
		ft_check_dup_color(texture->floor, line);
		texture->floor->red = ft_atoi(split[1]);
		texture->floor->green = ft_atoi(split[2]);
		texture->floor->blue = ft_atoi(split[3]);
	}
	else if (ft_strcmp(split[0], "C") == 0)
	{
		ft_check_dup_color(texture->ceiling, line);
		texture->ceiling->red = ft_atoi(split[1]);
		texture->ceiling->green = ft_atoi(split[2]);
		texture->ceiling->blue = ft_atoi(split[3]);
	}
	ft_check_errors(cub, split[0]);
	ft_free_array(split);
}

static void	ft_create_colors(t_cub *cub, char *line)
{
	t_color	*color;

	if (strncmp(line, "F", 1) == 0)
		color = cub->map->texture->floor;
	else
		color = cub->map->texture->ceiling;
	color->color = ft_create_rgb(color->red, color->green, color->blue);
}

void	ft_parse_color(t_cub *cub, char	*line)
{
	ft_prepare_line(line);
	ft_get_color(cub, line);
	ft_create_colors(cub, line);
}
