/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:34:16 by brunhenr          #+#    #+#             */
/*   Updated: 2024/12/11 15:45:24 by ncampbel         ###   ########.fr       */
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
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

bool	ft_perpendicular_vect(t_dirVector *dirVector, t_dirVector *camVector)
{
	double	dot_product;

	dot_product = dirVector->x * camVector->x + dirVector->y * camVector->y;
	return (fabs(dot_product) < 0.000001);
}

void	normalize_vector(t_dirVector *vector)
{
	double length = sqrt(vector->x * vector->x + vector->y * vector->y);
	if (length != 0)
	{
		vector->x /= length;
		vector->y /= length;
	}
}