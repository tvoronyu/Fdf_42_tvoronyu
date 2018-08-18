/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 21:21:10 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/06/25 21:22:45 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_creat_window(t_coord *ptr)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (ptr->str[i])
		i++;
	while (ptr->str[0][n] != '\0')
		n++;
	ptr->hight = i * (ptr->zoom * 3.4);
	ptr->wight = n * (ptr->zoom * 1.8);
	if (ptr->hight < 500)
		ptr->hight = 500;
	else if (ptr->hight > 3000)
		ptr->hight = 3000;
	if (ptr->wight > 2500)
		ptr->wight = 2500;
	else if (ptr->wight < 400)
		ptr->wight = 400;
}

void	ft_user_instruction(t_coord *ptr)
{
	mlx_string_put(ptr->mlx[0], ptr->mlx[1], 20, 20, 0xffff00, UP);
	mlx_string_put(ptr->mlx[0], ptr->mlx[1], 20, 40, 0xffff00, DOWN);
	mlx_string_put(ptr->mlx[0], ptr->mlx[1], 20, 60, 0xffff00, LEFT);
	mlx_string_put(ptr->mlx[0], ptr->mlx[1], 20, 80, 0xffff00, RIGHT);
	mlx_string_put(ptr->mlx[0], ptr->mlx[1], 20, 100, 0xffff00, ZOOM_1);
	mlx_string_put(ptr->mlx[0], ptr->mlx[1], 20, 120, 0xffff00, ZOOM_2);
	mlx_string_put(ptr->mlx[0], ptr->mlx[1], 20, 140, 0xffff00, HIGHT_UP);
	mlx_string_put(ptr->mlx[0], ptr->mlx[1], 20, 160, 0xffff00, HIGHT_DOWN);
	mlx_string_put(ptr->mlx[0], ptr->mlx[1], 20, 180, 0xffff00, ZOOM_1_WINDOW);
	mlx_string_put(ptr->mlx[0], ptr->mlx[1], 20, 200, 0xffff00, ZOOM_2_WINDOW);
	mlx_string_put(ptr->mlx[0], ptr->mlx[1], 20, 220, 0xffff00, COLOR_1);
	mlx_string_put(ptr->mlx[0], ptr->mlx[1], 20, 240, 0xffff00, COLOR_2);
	mlx_string_put(ptr->mlx[0], ptr->mlx[1], 20, 260, 0xffff00, COLOR_3);
	mlx_string_put(ptr->mlx[0], ptr->mlx[1], 20, 280, 0xffff00, RESET_COLOR);
}

void	ft_write_mas(t_coord *ptr)
{
	mlx_clear_window(ptr->mlx[0], ptr->mlx[1]);
	ft_creat_mas_x(ptr);
	ft_creat_mas_y(ptr);
	ft_colors(ptr);
	ft_solve_2(ptr);
	ft_user_instruction(ptr);
	ft_free_mas(ptr->mas_y);
	ft_free_mas(ptr->mas_x);
	ft_free_mas(ptr->colors);
}

void	ft_solve(t_coord *ptr, int flag)
{
	if (flag == 2)
		ft_creat_window_1(ptr, flag);
	else if (flag == 3)
		ft_creat_window_1(ptr, flag);
	else if (flag == 4)
		ft_creat_window_1(ptr, flag);
	else if (flag == 5)
		ft_creat_window_1(ptr, flag);
	else if (flag == 6)
		ft_creat_window_2(ptr, flag);
	else if (flag == 7)
		ft_creat_window_2(ptr, flag);
	else if (flag == 0)
		ft_creat_window_2(ptr, flag);
	mlx_hook(ptr->mlx[1], 17, 1L << 17, exit_x, ptr);
	mlx_hook(ptr->mlx[1], 2, 5, deal_key, ptr);
	mlx_mouse_hook(ptr->mlx[1], deal_key_mouse, ptr);
	ptr->len_mas_y_reserv = ft_count_y(ptr);
	ft_write_mas(ptr);
}

void	ft_solve_1(t_coord *ptr, char *name_file)
{
	int fd;

	ptr = (t_coord*)malloc(sizeof(t_coord));
	ptr->rost = 1;
	ptr->zoom = 10;
	ptr->shag = 2;
	ptr->color_random = "0xffffff";
	fd = ft_read_helper(name_file);
	ptr->str = ft_read(name_file, fd);
	ft_creat_window(ptr);
	ptr->name_file = name_file;
	ft_solve(ptr, 0);
	mlx_loop(ptr->mlx[0]);
}
