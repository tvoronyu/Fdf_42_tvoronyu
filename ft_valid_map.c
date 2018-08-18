/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 21:25:49 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/06/25 21:27:39 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_count_str(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	ft_free_mas_2(str);
	return (i);
}

int		ft_digits_str(char **str)
{
	int i;
	int n;
	int flag;

	i = -1;
	while (str[++i])
	{
		n = -1;
		flag = 1;
		while (str[i][++n] != '\0')
		{
			if (ft_isdigit(str[i][n]))
				flag = 0;
		}
		if (flag == 1)
			break ;
	}
	ft_free_mas_2(str);
	return (flag);
}

int		ft_valid_map(char **str)
{
	int count_y;
	int i;

	i = 0;
	count_y = 0;
	while (str[count_y])
		count_y++;
	if (count_y < 2)
		return (1);
	while (i < count_y - 1)
	{
		if (ft_count_str(ft_strsplit(str[i], ' '))
				!= ft_count_str(ft_strsplit(str[i + 1], ' ')))
			return (1);
		i++;
	}
	i = 0;
	while (i < count_y)
		if (ft_digits_str(ft_strsplit(str[i++], ' ')))
			return (1);
	return (0);
}
