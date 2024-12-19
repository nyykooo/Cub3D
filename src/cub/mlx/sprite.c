/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:19:08 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/18 22:41:09 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

t_image *load_sprite_sheet(void *mlx_ptr, char *file_path, int width, int height) {
    t_image *img = malloc(sizeof(t_image));
    img->img = mlx_xpm_file_to_image(mlx_ptr, file_path, &width, &height);
    img->width = width;
    img->height = height;
    img->tex = ft_get_image_pixels(img->img, width, height);
    return img;
}

t_sprite *init_sprite(t_image *sprite_sheet, int frame_w, int frame_h, int num_frames, float frame_time) {
    t_sprite *anim = malloc(sizeof(t_sprite));
    anim->sprite_sheet = sprite_sheet;
    anim->frame_w = frame_w;
    anim->frame_h = frame_h;
    anim->num_frames = num_frames;
    anim->cur_frame = 0;
    anim->frame_time = frame_time;
    anim->last_frame_time = ft_get_time_s();
    return (anim);
}

void update_animation(t_sprite *anim) {
    long current_time_in_s;
    
    current_time_in_s = ft_get_time_s();
    if (current_time_in_s - anim->last_frame_time > anim->frame_time) {
        anim->last_frame_time = current_time_in_s;
        anim->cur_frame++;
    }
}

void draw_sword_attack(t_cub *cub, t_player *player)
{
    int frame_y = player->attack->frame_w * player->attack->cur_frame;
    if (frame_y == player->attack->sprite_sheet->width)
        return ;

    float scale = (float)SCREEN_HEIGHT / player->attack->frame_h;
    int new_width = player->attack->frame_w * scale;
    int new_height = player->attack->frame_h * scale;

    int start_x = SCREEN_WIDTH - (SCREEN_WIDTH / 1.7f);
    int start_y = SCREEN_HEIGHT - (new_height / 1.3f);

    for (int i = 0; i < new_height; i++) {
        for (int j = 0; j < new_width; j++) {
            int tex_x = i / scale;
            int tex_y = (new_width - j - 1) / scale;
            int color = player->attack->sprite_sheet->tex[frame_y + tex_y][tex_x];
            if (color != NONE) {
                if (start_y + i >= 0 && start_y + i < SCREEN_HEIGHT)
                    ft_my_mlx_pixel_put(cub, start_x + j, start_y + i, color);
            }
        }
    }
}
