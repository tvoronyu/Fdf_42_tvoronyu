/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 20:55:58 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/06/25 20:58:08 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_colors_key(t_coord *ptr, int key)
{
	if (key == 18 || key == 83)
	{
		ptr->color_random = "0x00ff00";
		ft_solve(ptr, 1);
	}
	else if (key == 19 || key == 84)
	{
		ptr->color_random = "0x00ff";
		ft_solve(ptr, 1);
	}
	else if (key == 20 || key == 85)
	{
		ptr->color_random = "0xFA1F02";
		ft_solve(ptr, 1);
	}
	else if (key == 21 || key == 86)
	{
		ptr->color_random = "0xFFFFFF";
		ft_solve(ptr, 1);
	}
}

char	**ft_clear_mas_colors(t_coord *ptr, char **str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		tmp = ft_strstr(str[i], "0x");
		if (tmp == NULL)
			tmp = ptr->color_random;
		free(str[i]);
		str[i] = ft_strdup(tmp);
		i++;
	}
	return (str);
}

void	ft_creat_mas_colors(t_coord *ptr)
{
	int		i;
	char	**tmp;

	i = 0;
	ptr->colors = (char***)malloc(sizeof(char**) * (ptr->len_mas_y_reserv + 1));
	ptr->colors[ptr->len_mas_y_reserv] = NULL;
	while (i < ptr->len_mas_y_reserv)
	{
		tmp = ft_strsplit(ptr->str[i], ' ');
		ptr->colors[i] = ft_clear_mas_colors(ptr, tmp);
		i++;
	}
}

void	ft_colors(t_coord *ptr)
{
	ft_creat_mas_colors(ptr);
}
