/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:31:26 by brunhenr          #+#    #+#             */
/*   Updated: 2024/12/19 15:27:50 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	ft_draw_sword(t_cub *cub, t_player *player)
{
    int	width;
    int	height;
    int	y;
    int x;
    int new_width;
    int new_height;
    float scale;
    int start_x;
    int start_y;

    width = SWORD_WIDTH;
    height = SWORD_HEIGHT;
    player->sword = malloc(sizeof(t_wall));
    player->sword->img = mlx_xpm_file_to_image(cub->mlx_ptr, "./includes/textures/anduril_rest.xpm", &width, &height);
    player->sword->tex = ft_get_image_pixels(player->sword->img, width, height);

    scale = (float)SCREEN_HEIGHT / (height);
    new_width = width * scale;
    new_height = height * scale;

    start_x = SCREEN_WIDTH - (SCREEN_WIDTH / 1.7f);
    start_y = SCREEN_HEIGHT - (new_height / 1.3f);

    // Desenhar a espada na nova posição e tamanho
    for (y = 0; y < new_height; y++)
    {
        for (x = 0; x < new_width; x++)
        {
            int tex_x = x / scale;
            int tex_y = y / scale;
            if (player->sword->tex[tex_x][tex_y] != NONE){
				if (start_y + y >= 0 && start_y + y < SCREEN_HEIGHT)
                ft_my_mlx_pixel_put(cub, start_x + x, start_y + y, player->sword->tex[tex_x][tex_y]);}
        }
    }
}

void	draw_column(t_cub *cub, int x, t_player *player)
{
	t_ray	ray;
	int		line_height;
	int		draw_start;
	double	orto_wall_dist;
	int		draw_end;
	int		color;
	int		i = 0;
	int		tex_y;
	int		y;

	calculate_ray_direction(x, &ray, player);
	calculate_initial_distances(player, &ray);
	perform_dda(cub, &ray);
	if (ray.side == 0 || ray.side == 2)
		orto_wall_dist = (ray.sideDistX - ray.deltaDistX);
	else
		orto_wall_dist = (ray.sideDistY - ray.deltaDistY);
	line_height = (int)(SCREEN_HEIGHT / orto_wall_dist);
	draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
	draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
	
	double	wall_cord;
	int		tex_x;
	
	if(ray.side == 0 || ray.side == 2)
		wall_cord = player->p_y + orto_wall_dist * ray.dirY;
	else
		wall_cord = player->p_x + orto_wall_dist * ray.dirX;
    wall_cord -= floor((wall_cord));

	tex_x = (int)(wall_cord * (double)TEX_WIDTH);

	if((ray.side == 0 || ray.side == 2) && ray.dirX > 0)
		tex_x = TEX_WIDTH - tex_x - 1;
	if((ray.side == 1 || ray.side == 3) && ray.dirY < 0)
		tex_x = TEX_WIDTH - tex_x - 1;
	
	double step = 1.0 * TEX_HEIGHT / line_height; // 1.00 para ser double

    double texPos = (draw_start - SCREEN_HEIGHT / 2 + line_height / 2) * step;

	int		len = draw_end - draw_start;
	int		buffer[len];

	y = draw_start;
	while (y < draw_end)
	{
		tex_y = (int)texPos & (TEX_HEIGHT - 1);
		texPos += step;
		if (ray.side == 1)
			color = cub->map->texture->east->tex[tex_x][tex_y];
		else if (ray.side == 0)
			color = cub->map->texture->south->tex[tex_x][tex_y];
		else if (ray.side == 2)
			color = cub->map->texture->north->tex[tex_x][tex_y];
		else if (ray.side == 3)
			color = cub->map->texture->west->tex[tex_x][tex_y];
		buffer[i] = color;
		i++;
		y++;
	}
	ft_draw_vertical_line(x, draw_start, draw_end, cub, buffer);
}

int	ft_ray_casting(t_cub *cub)
{
	int			x;
	t_player	*player;

	x = 0;
	player = cub->map->player;
	ft_image_hub(cub);
	ft_start_frame(&cub->frameTime);
	while (x < SCREEN_WIDTH)
	{
		draw_column(cub, x, player);
		x++;
	}
	ft_draw_sword(cub, player);
	ft_end_frame(&cub->frameTime);
	mlx_put_image_to_window(cub->mlx_ptr, cub->win, cub->img, 0, 0);
	return (0);
}
