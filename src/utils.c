/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:34:16 by brunhenr          #+#    #+#             */
/*   Updated: 2024/12/24 18:56:42 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.h"

//degrees to radians
double	ft_deg_to_rad(double deg)
{
	return (deg * (PI / 180));
}

bool	ft_is_walkable(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == '3')
		return (true);
	return (false);
}

bool	ft_perpendicular_vect(t_dirVector *dirVector, t_dirVector *camVector)
{
	double	dot_product;

	dot_product = dirVector->x * camVector->x + dirVector->y * camVector->y;
	return (fabs(dot_product) < 0.000001);
}

void	ft_rotate_vect(double angle, t_dirVector *vector)
{
	double	old_x;

	old_x = vector->x;
	vector->x = vector->x * cos(angle) - vector->y * sin(angle);
	vector->y = old_x * sin(angle) + vector->y * cos(angle);
	return ;
}

void	ft_free_int_array(int **array)
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
