/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:10:15 by brunhenr          #+#    #+#             */
/*   Updated: 2024/12/23 12:56:16 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

static void	ft_check_for_null(t_texture *texture)
{
	if (!texture->north->path || !texture->south->path || \
	!texture->west->path || !texture->east->path \
	|| !texture->ceiling || !texture->floor)
		ERROR_PRINT(ERROR_MSG(1, ERROR_NULL_TEXT), 1);
}

static void	ft_check_files(t_cub *cub, t_texture *texture)
{
	ft_validate_extension(texture->north->path, ".xpm");
	cub->fd = open(texture->north->path, O_RDONLY);
	if (cub->fd < 0)
		ERROR_PRINT(ERROR_MSG(3, ERROR_TEXT, \
		texture->north->path, "\"\n", 0), 1);
	close(cub->fd);
	ft_validate_extension(texture->south->path, ".xpm");
	cub->fd = open(texture->south->path, O_RDONLY);
	if (cub->fd < 0)
		ERROR_PRINT(ERROR_MSG(3, ERROR_TEXT, \
		texture->south->path, "\"\n", 0), 1);
	close(cub->fd);
	ft_validate_extension(texture->west->path, ".xpm");
	cub->fd = open(texture->west->path, O_RDONLY);
	if (cub->fd < 0)
		ERROR_PRINT(ERROR_MSG(3, ERROR_TEXT, \
		texture->west->path, "\"\n", 0), 1);
	close(cub->fd);
	ft_validate_extension(texture->east->path, ".xpm");
	cub->fd = open(texture->east->path, O_RDONLY);
	if (cub->fd < 0)
		ERROR_PRINT(ERROR_MSG(3, ERROR_TEXT, \
		texture->east->path, "\"\n", 0), 1);
	close(cub->fd);
}

void	ft_get_tex_imgs(t_cub *cub, t_texture *texture)
{
	int	width;
	int	height;

	width = TEX_WIDTH;
	height = TEX_HEIGHT;
	texture->north->img = mlx_xpm_file_to_image(cub->mlx_ptr, \
	texture->north->path, &width, &height);
	texture->south->img = mlx_xpm_file_to_image(cub->mlx_ptr, \
	texture->south->path, &width, &height);
	texture->west->img = mlx_xpm_file_to_image(cub->mlx_ptr, \
	texture->west->path, &width, &height);
	texture->east->img = mlx_xpm_file_to_image(cub->mlx_ptr, \
	texture->east->path, &width, &height);
	texture->north->tex = ft_get_image_pixels(texture->north->img,
			width, height);
	texture->south->tex = ft_get_image_pixels(texture->south->img,
			width, height);
	texture->west->tex = ft_get_image_pixels(texture->west->img, width, height);
	texture->east->tex = ft_get_image_pixels(texture->east->img, width, height);
}

void	ft_parse_texture(void)
{
	t_texture	*texture;
	t_cub		*cub;

	cub = ft_get_cub();
	texture = cub->map->texture;
	ft_check_for_null(texture);
	ft_check_files(cub, texture);
}
