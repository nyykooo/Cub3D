/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:50:13 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/19 16:14:48 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	ft_get_sword_images(t_cub *cub, t_player *player)
{
	t_image		*sprite;

	sprite = load_sprite_sheet(cub->mlx_ptr, "./includes/textures/sprites/attack/attackss2.xpm", 192, 64);
	player->attack = init_sprite(sprite, 64, 64, 3, 120);
	player->sword = load_sprite_sheet(cub->mlx_ptr, "./includes/textures/anduril_rest.xpm", 64, 64);
}

int	ft_mouse_click(int button, int x, int y, t_cub *cub)
{
    t_player	*player;

    player = cub->map->player;
    (void)x;
    (void)y;
    if (button == 1)
    {
        if (!player->is_attacking)
        {
            player->is_attacking = true;
            player->attack->cur_frame = 0;
            while (player->attack->cur_frame <= player->attack->num_frames -1)
            {
                update_animation(player->attack);
                ft_ray_casting(cub);
            }
        }
    }
    player->is_attacking = false;
    ft_ray_casting(cub);
    return (0);
}

int	ft_mouse(int x, int y, t_cub *cub)
{
	t_player	*player;

	player = cub->map->player;
	(void)y;
	if (cub->mouse_x < x)
	{
		ft_rotate_right(player, cub);
		if (!ft_perpendicular_vect(player->dirVector, player->camVector))
			ERROR_PRINT(ERROR_MSG(1, ERROR_VECTORS), 1);
		ft_ray_casting(cub);
	}
	else if (cub->mouse_x > x)
	{
		ft_rotate_left(player, cub);
		if (!ft_perpendicular_vect(player->dirVector, player->camVector))
			ERROR_PRINT(ERROR_MSG(1, ERROR_VECTORS), 1);
		ft_ray_casting(cub);
	}
	cub->mouse_x = x;
	return (0);
}

void	ft_my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = cub->addr + (y * cub->line_length + x * (cub->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_init_mlx(t_cub *cub)
{
	cub->mlx_ptr = mlx_init();
	if (!cub->mlx_ptr)
		ERROR_PRINT(ERROR_MSG(1, ERROR_MLX), 1);
	cub->win = mlx_new_window(cub->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
	if (!cub->win)
		ERROR_PRINT(ERROR_MSG(1, ERROR_WIN), 1);
	ft_get_tex_imgs(cub, cub->map->texture);
	ft_get_sword_images(cub, cub->map->player);
	ft_image_hub(cub);
}

void	ft_mlx_hook_and_loop(t_cub *cub)
{
	cub->mouse_x = SCREEN_WIDTH / 2;
	mlx_hook(cub->win, 6, PointerMotionMask, ft_mouse, cub);
	mlx_hook (cub->win, 17, 0, ft_close_x, cub);
	mlx_hook(cub->win, 2, KeyPressMask, ft_key_press, cub);
	mlx_hook(cub->win, 3, KeyReleaseMask, ft_key_release, cub);
	mlx_hook (cub->win, 4, ButtonPressMask, ft_mouse_click, cub);
	mlx_expose_hook(cub->win, ft_ray_casting, cub);
	mlx_loop_hook(cub->mlx_ptr, ft_keys, cub);
	mlx_loop (cub->mlx_ptr);
}
