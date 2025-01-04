/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:19:08 by ncampbel          #+#    #+#             */
/*   Updated: 2025/01/04 20:31:20 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

t_image	*load_sprite_sheet(void *mlx_ptr, char *path, int width, int height)
{
	t_image	*img;

	img = malloc(sizeof(t_image));
	img->img = mlx_xpm_file_to_image(mlx_ptr, path, &width, &height);
	img->width = width;
	img->height = height;
	img->path = ft_strdup(path);
	img->tex = ft_get_image_pixels(img->img, width, height);
	return (img);
}

t_sprite	*init_sprite(t_image *ss, int frame_w, int frame_h, int num_frames)
{
	t_sprite	*anim;

	anim = malloc(sizeof(t_sprite));
	anim->sprite_sheet = ss;
	anim->frame_w = frame_w;
	anim->frame_h = frame_h;
	anim->num_frames = num_frames;
	anim->cur_frame = 0;
	anim->frame_time = SPRITE_FRAME_TIME;
	anim->last_frame_time = ft_get_time_s();
	return (anim);
}

void	update_animation(t_sprite *anim)
{
	long	current_time_in_s;

	current_time_in_s = ft_get_time_s();
	if (current_time_in_s - anim->last_frame_time > anim->frame_time)
	{
		anim->last_frame_time = current_time_in_s;
		anim->cur_frame++;
	}
}

// void	draw_sword_attack(t_cub *cub, t_player *player)
// {
// 	float	scale;
// 	int		frame_y;
// 	int		new_width;
// 	int		new_height;
// 	int		start_x;
// 	int		start_y;
// 	int		i;
// 	int		j;
// 	int		tex_x;
// 	int		tex_y;
// 	int		color;

// 	frame_y = player->attack->frame_w * player->attack->cur_frame;
// 	if (frame_y == player->attack->sprite_sheet->width)
// 		return ;
// 	scale = (float)SCREEN_HEIGHT / player->attack->frame_h;
// 	new_width = player->attack->frame_w * scale;
// 	new_height = player->attack->frame_h * scale;
// 	start_x = SCREEN_WIDTH - (SCREEN_WIDTH / 1.7f);
// 	start_y = SCREEN_HEIGHT - (new_height / 1.3f);
// 	i = -1;
// 	while (++i < new_height)
// 	{
// 		j = -1;
// 		while (++j < new_width)
// 		{
// 			tex_x = i / scale;
// 			tex_y = (new_width - j - 1) / scale;
// 			color = player->attack->sprite_sheet->tex[frame_y + tex_y][tex_x];
// 			if (color != NONE)
// 			{
// 				if (start_y + i >= 0 && start_y + i < SCREEN_HEIGHT)
// 					ft_my_mlx_pixel_put(cub, start_x + j, start_y + i, color);
// 			}
// 		}
// 	}
// }

void	draw_pixel(t_cub *cub, int i, int j, int color)
{
	t_sprite	*attack;

	attack = cub->map->player->attack;
	if (color != NONE)
	{
		if (attack->start_y + i >= 0 && attack->start_y + i < SCREEN_HEIGHT)
			ft_my_mlx_pixel_put(cub, attack->start_x + j, \
			attack->start_y + i, color);
	}
}

void	draw_frame(t_cub *cub, t_player *player)
{
	int	i;
	int	j;
	int	tex_x;
	int	tex_y;
	int	color;

	i = -1;
	while (++i < player->attack->new_h)
	{
		j = -1;
		while (++j < player->attack->new_w)
		{
			tex_x = i / player->attack->sprt_scl;
			tex_y = (player->attack->new_w - j - 1) / player->attack->sprt_scl;
			color = player->attack->sprite_sheet->tex[player->attack->frame_y \
			+ tex_y][tex_x];
			draw_pixel(cub, i, j, color);
		}
	}
}
