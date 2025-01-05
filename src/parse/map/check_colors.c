/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:00:34 by brunhenr          #+#    #+#             */
/*   Updated: 2025/01/04 20:04:48 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	ft_check_dup_color(t_color *color, char *line)
{
	if (color->input)
		free(color->input);
	color->input = ft_strdup(line);
}

void	ft_check_errors(t_cub *cub, char *color)
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