/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:43:29 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/23 12:52:42 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

static void	ft_clear_player(t_player *player)
{
	if (player)
	{
		if (player->dirVector)
			free(player->dirVector);
		if (player->camVector)
			free(player->camVector);
		if (player->ray)
			free(player->ray);
		free(player);
	}
}

static void	ft_clear_color(t_color *color)
{
	if (color->input)
		free(color->input);
	if (color)
		free(color);
}

void	free_array(int **array)
{
	int	i;

	i = 0;
	while (i < TEX_WIDTH)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static void	ft_clear_texture(t_texture *texture)
{
	if (texture->north->path)
	{
		free(texture->north->path);
		if (texture->north->tex)
			free_array(texture->north->tex);
		free(texture->north);
	}
	if (texture->south->path)
	{
		free(texture->south->path);
		if (texture->south->tex)
			free_array(texture->south->tex);
		free(texture->south);
	}
	if (texture->east->path)
	{
		free(texture->east->path);
		if (texture->east->tex)
			free_array(texture->east->tex);
		free(texture->east);
	}
	if (texture->west->path)
	{
		free(texture->west->path);
		if (texture->west->tex)
			free_array(texture->west->tex);
		free(texture->west);
	}
	if (texture->door->path)
	{
		free(texture->door->path);
		if (texture->door->tex)
			free_array(texture->door->tex);
		free(texture->door);
	}
	if (texture->ceiling)
		ft_clear_color(texture->ceiling);
	if (texture->floor)
		ft_clear_color(texture->floor);
	if (texture)
		free(texture);
}

static void	ft_clear_map(t_map *map)
{
	if (map && map->map)
		ft_free_array(map->map);
	if (map && map->ff_map)
		ft_free_array(map->ff_map);
	if (map->texture)
		ft_clear_texture(map->texture);
	if (map->path)
		free(map->path);
	if (map->player)
		ft_clear_player(map->player);
	if (map)
		free(map);
}

void	ft_clear_cub(void)
{
	t_cub	*cub;

    cub = ft_get_cub();
    if (cub->img)
    {
        mlx_destroy_image(cub->mlx_ptr, cub->img);
		if (cub->map->texture->north->img)
			mlx_destroy_image(cub->mlx_ptr, cub->map->texture->north->img);
		if (cub->map->texture->south->img)
			mlx_destroy_image(cub->mlx_ptr, cub->map->texture->south->img);
		if (cub->map->texture->west->img)
			mlx_destroy_image(cub->mlx_ptr, cub->map->texture->west->img);
		if (cub->map->texture->east->img)
			mlx_destroy_image(cub->mlx_ptr, cub->map->texture->east->img);
		if (cub->map->texture->door->img)
			mlx_destroy_image(cub->mlx_ptr, cub->map->texture->door->img);
    }
    if (cub->win)
    {
        mlx_destroy_window(cub->mlx_ptr, cub->win);
    }
    if (cub->mlx_ptr)
    {
        mlx_loop_end(cub->mlx_ptr);
        mlx_destroy_display(cub->mlx_ptr);
        free(cub->mlx_ptr);
    }
    if (cub->fd != -1)
        close(cub->fd);
    if (cub->line)
        free(cub->line);				
    if (cub->file)
        free(cub->file);
    if (cub->map)
        ft_clear_map(cub->map);
}
