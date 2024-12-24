/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 23:38:48 by brunhenr          #+#    #+#             */
/*   Updated: 2024/12/24 14:13:27 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

void	ft_start_frame(t_frametime *frameTime)
{
	gettimeofday(&frameTime->start, NULL);
}

void	ft_end_frame(t_frametime *frameTime)
{
	gettimeofday(&frameTime->end, NULL);
	frameTime->frame_time = (frameTime->end.tv_sec - frameTime->start.tv_sec) + \
	(frameTime->end.tv_usec - frameTime->start.tv_usec) / 1000000.0;
	frameTime->move_speed = frameTime->frame_time * MOVE_FACTOR;
	frameTime->rot_speed = frameTime->frame_time * ROTATE_FACTOR;
}
