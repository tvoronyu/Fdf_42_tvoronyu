/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 21:18:10 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/06/25 21:19:35 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_creat_window_2(t_coord *ptr, int flag)
{
	if (flag == 6)
	{
		mlx_destroy_window(ptr->mlx[0], ptr->mlx[1]);
		ptr->mlx[1] = mlx_new_window(ptr->mlx[0],
				(ptr->wight -= 10), ptr->hight, ptr->name_file);
	}
	else if (flag == 7)
	{
		mlx_destroy_window(ptr->mlx[0], ptr->mlx[1]);
		ptr->mlx[1] = mlx_new_window(ptr->mlx[0],
				(ptr->wight += 10), ptr->hight, ptr->name_file);
	}
	else if (flag == 0)
	{
		ptr->mlx[0] = mlx_init();
		ptr->mlx[1] = mlx_new_window(ptr->mlx[0],
				ptr->wight, ptr->hight, ptr->name_file);
	}
}

void	ft_creat_window_1(t_coord *ptr, int flag)
{
	if (flag == 2)
	{
		mlx_destroy_window(ptr->mlx[0], ptr->mlx[1]);
		ptr->mlx[1] = mlx_new_window(ptr->mlx[0],
				(ptr->wight += 10), (ptr->hight += 10), ptr->name_file);
	}
	else if (flag == 3)
	{
		mlx_destroy_window(ptr->mlx[0], ptr->mlx[1]);
		ptr->mlx[1] = mlx_new_window(ptr->mlx[0],
				(ptr->wight -= 10), (ptr->hight -= 10), ptr->name_file);
	}
	else if (flag == 4)
	{
		mlx_destroy_window(ptr->mlx[0], ptr->mlx[1]);
		ptr->mlx[1] = mlx_new_window(ptr->mlx[0],
				ptr->wight, (ptr->hight += 10), ptr->name_file);
	}
	else if (flag == 5)
	{
		mlx_destroy_window(ptr->mlx[0], ptr->mlx[1]);
		ptr->mlx[1] = mlx_new_window(ptr->mlx[0],
				ptr->wight, (ptr->hight -= 10), ptr->name_file);
	}
}
