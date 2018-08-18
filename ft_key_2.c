/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 21:20:01 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/06/25 21:20:44 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_key_up_down_right_left(t_coord *ptr, int key)
{
	if (key == 126)
	{
		ptr->up_down -= 5;
		ft_solve(ptr, 1);
	}
	if (key == 125)
	{
		ptr->up_down += 5;
		ft_solve(ptr, 1);
	}
	if (key == 123)
	{
		ptr->left_right -= 5;
		ft_solve(ptr, 1);
	}
	if (key == 124)
	{
		ptr->left_right += 5;
		ft_solve(ptr, 1);
	}
}

void	ft_key_rost_shag(t_coord *ptr, int key)
{
	if (key == 30)
	{
		ptr->rost += 1;
		ft_solve(ptr, 1);
	}
	if (key == 33)
	{
		ptr->rost -= 1;
		ft_solve(ptr, 1);
	}
	if (key == 39)
	{
		ptr->shag -= 1;
		ft_solve(ptr, 1);
	}
	if (key == 42)
	{
		ptr->shag += 1;
		ft_solve(ptr, 1);
	}
}

void	ft_key_zoom(t_coord *ptr, int key)
{
	if (key == 69)
	{
		ptr->zoom += 1;
		ptr->rost += 0.2;
		ptr->shag += 0.2;
		ft_solve(ptr, 1);
	}
	else if (key == 78)
	{
		ptr->zoom -= 1;
		ptr->rost -= 0.2;
		ptr->shag -= 0.2;
		ft_solve(ptr, 1);
	}
}
