/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 20:59:36 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/06/25 21:00:48 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key_1(int key, t_coord *ptr)
{
	if (key == 126)
		ft_key_up_down_right_left(ptr, key);
	else if (key == 125)
		ft_key_up_down_right_left(ptr, key);
	else if (key == 123)
		ft_key_up_down_right_left(ptr, key);
	else if (key == 124)
		ft_key_up_down_right_left(ptr, key);
	else if (key == 14)
		ft_solve(ptr, 2);
	else if (key == 12)
		ft_solve(ptr, 3);
	else if (key == 13)
		ft_solve(ptr, 4);
	else if (key == 1)
		ft_solve(ptr, 5);
	else if (key == 0)
		ft_solve(ptr, 6);
	else if (key == 2)
		ft_solve(ptr, 7);
	return (0);
}

int		deal_key_mouse(int key, int x, int y, t_coord *ptr)
{
	x = 0;
	y = 0;
	if (key == 5)
		ft_key_zoom(ptr, 69);
	else if (key == 4)
		ft_key_zoom(ptr, 78);
	return (0);
}

int		deal_key(int key, t_coord *ptr)
{
	if (key == 53)
		exit(0);
	else if (key == 69)
		ft_key_zoom(ptr, key);
	else if (key == 78)
		ft_key_zoom(ptr, key);
	else if (key == 30)
		ft_key_rost_shag(ptr, key);
	else if (key == 33)
		ft_key_rost_shag(ptr, key);
	else if (key == 39)
		ft_key_rost_shag(ptr, key);
	else if (key == 42)
		ft_key_rost_shag(ptr, key);
	else if (key >= 18 && 21 >= key)
		ft_colors_key(ptr, key);
	else
		deal_key_1(key, ptr);
	return (0);
}
