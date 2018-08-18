/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 21:28:00 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/06/25 21:30:50 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_count_y(t_coord *ptr)
{
	int y;

	y = 0;
	while (ptr->str[y])
		y++;
	return (y);
}

void	ft_creat_mas_y(t_coord *ptr)
{
	int		i;
	int		res;
	char	*tmp;
	int		n;

	i = 0;
	ptr->mas_y = (char***)malloc(sizeof(char**) * (ptr->len_mas_y_reserv + 1));
	ptr->mas_y[ptr->len_mas_y_reserv] = NULL;
	while (i < ptr->len_mas_y_reserv)
	{
		ptr->mas_y[i] = ft_strsplit(ptr->str[i], ' ');
		n = 0;
		while (ptr->mas_y[i][n])
		{
			res = ft_atoi(ptr->mas_y[i][n]);
			tmp = ft_itoa((res * -1) - (ptr->rost * res)
					+ (ptr->zoom * i) + ptr->up_down);
			free(ptr->mas_y[i][n]);
			ptr->mas_y[i][n] = tmp;
			n++;
		}
		i++;
	}
}

void	ft_creat_mas_x(t_coord *ptr)
{
	int		i;
	char	**tmp;

	i = 0;
	ptr->mas_x = (char***)malloc(sizeof(char**) * (ptr->len_mas_y_reserv + 1));
	ptr->mas_x[ptr->len_mas_y_reserv] = NULL;
	while (i < ptr->len_mas_y_reserv)
	{
		tmp = ft_strsplit(ptr->str[i], ' ');
		ptr->mas_x[i] = ft_clear_mas_x(ptr, tmp, i);
		i++;
	}
}

char	**ft_clear_mas_x(t_coord *ptr, char **str, int n)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		tmp = ft_itoa((ptr->zoom * i) + ptr->left_right + ptr->shag * n);
		free(str[i]);
		str[i] = tmp;
		i++;
	}
	return (str);
}
