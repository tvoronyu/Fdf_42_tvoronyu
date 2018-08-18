/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 14:03:43 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/06/22 12:20:15 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_brezenhem(t_coord *ptr)
{
	int delta[2];
	int sign[2];
	int error[2];

	delta[0] = abs(ptr->x1 - ptr->x0);
	delta[1] = abs(ptr->y1 - ptr->y0);
	sign[0] = ptr->x0 < ptr->x1 ? 1 : -1;
	sign[1] = ptr->y0 < ptr->y1 ? 1 : -1;
	error[0] = delta[0] - delta[1];
	mlx_pixel_put(ptr->mlx[0], ptr->mlx[1], ptr->x1, ptr->y1, ptr->color_2);
	while (ptr->x0 != ptr->x1 || ptr->y0 != ptr->y1)
	{
		mlx_pixel_put(ptr->mlx[0], ptr->mlx[1], ptr->x0, ptr->y0, ptr->color_1);
		error[1] = error[0] * 2;
		if (error[1] > -delta[1])
		{
			error[0] -= delta[1];
			ptr->x0 += sign[0];
		}
		else
		{
			error[0] += delta[0];
			ptr->y0 += sign[1];
		}
	}
}
