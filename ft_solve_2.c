/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 21:23:03 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/06/25 21:25:25 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_paint_x_end(t_coord *ptr, int i, int n)
{
	while (i != 0)
	{
		if (ptr->mas_x[i][n] && ptr->mas_x[i - 1][n])
		{
			ptr->x0 = ft_atoi(ptr->mas_x[i][n]) + 200;
			ptr->y0 = ft_atoi(ptr->mas_y[i][n]) + 200;
			ptr->color_1 = ft_atoi_base(ptr->colors[i][n] + 2, 16);
			ptr->x1 = ft_atoi(ptr->mas_x[i - 1][n]) + 200;
			ptr->y1 = ft_atoi(ptr->mas_y[i - 1][n]) + 200;
			ptr->color_2 = ft_atoi_base(ptr->colors[i][n] + 2, 16);
		}
		else
		{
			ft_putendl("Found wrong line length. Exiting.");
			ft_free_mas(ptr->mas_y);
			ft_free_mas(ptr->mas_x);
			ft_free_mas(ptr->colors);
			ft_success_end(ptr);
		}
		ft_brezenhem(ptr);
		i--;
	}
}

void	ft_paint_y_end(t_coord *ptr, int i, int n)
{
	while (n != 0)
	{
		if (ptr->mas_x[i][n] && ptr->mas_x[i][n - 1])
		{
			ptr->x0 = ft_atoi(ptr->mas_x[i][n]) + 200;
			ptr->y0 = ft_atoi(ptr->mas_y[i][n]) + 200;
			ptr->color_1 = ft_atoi_base(ptr->colors[i][n] + 2, 16);
			ptr->x1 = ft_atoi(ptr->mas_x[i][n - 1]) + 200;
			ptr->y1 = ft_atoi(ptr->mas_y[i][n - 1]) + 200;
			ptr->color_2 = ft_atoi_base(ptr->colors[i][n] + 2, 16);
		}
		else if (ptr->mas_x[i][n] == NULL && n != 0)
			n--;
		else
		{
			ft_putendl("Found wrong line length. Exiting.");
			ft_free_mas(ptr->mas_y);
			ft_free_mas(ptr->mas_x);
			ft_free_mas(ptr->colors);
			ft_success_end(ptr);
		}
		ft_brezenhem(ptr);
		n--;
	}
}

void	ft_paint_y(t_coord *ptr)
{
	int i;
	int n;

	i = 0;
	while (ptr->mas_y[i + 1] != NULL)
	{
		n = 0;
		while (ptr->mas_y[i][n + 1] != NULL)
		{
			ptr->x0 = ft_atoi(ptr->mas_x[i][n]) + 200;
			ptr->y0 = ft_atoi(ptr->mas_y[i][n]) + 200;
			ptr->color_1 = ft_atoi_base(ptr->colors[i][n] + 2, 16);
			ptr->x1 = ft_atoi(ptr->mas_x[i][n + 1]) + 200;
			ptr->y1 = ft_atoi(ptr->mas_y[i][n + 1]) + 200;
			ptr->color_2 = ft_atoi_base(ptr->colors[i][n] + 2, 16);
			ft_brezenhem(ptr);
			n++;
		}
		i++;
	}
	ft_paint_y_end(ptr, i, n);
}

void	ft_paint_x(t_coord *ptr)
{
	int i;
	int n;
	int zoom;

	i = 0;
	zoom = 0;
	while (ptr->mas_y[i + 1] != NULL)
	{
		n = 0;
		while (ptr->mas_y[i][n + 1] != NULL)
		{
			ptr->x0 = ft_atoi(ptr->mas_x[i][n]) + 200;
			ptr->y0 = ft_atoi(ptr->mas_y[i][n]) + 200;
			ptr->color_1 = ft_atoi_base(ptr->colors[i][n] + 2, 16);
			ptr->x1 = ft_atoi(ptr->mas_x[i + 1][n]) + 200;
			ptr->y1 = ft_atoi(ptr->mas_y[i + 1][n]) + 200;
			ptr->color_2 = ft_atoi_base(ptr->colors[i][n] + 2, 16);
			ft_brezenhem(ptr);
			n++;
		}
		zoom += ptr->zoom;
		i++;
	}
	ft_paint_x_end(ptr, i, n);
}

void	ft_solve_2(t_coord *ptr)
{
	ft_paint_y(ptr);
	ft_paint_x(ptr);
}
