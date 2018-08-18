/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 20:58:42 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/06/25 20:58:57 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error_map(int i)
{
	if (i == 1)
		ft_putendl("Error!\nEmpty line in map!");
	else if (i == 2)
		ft_putendl("Error!\nIncorrect number of characters in the string!");
	else
		ft_putendl("Error map!");
	exit(EXIT_FAILURE);
}

void	ft_error(void)
{
	ft_putendl("Error!\nThis is not FDF map file!");
	exit(EXIT_FAILURE);
}

void	ft_success_end(t_coord *ptr)
{
	mlx_destroy_window(ptr->mlx[0], ptr->mlx[1]);
	exit(EXIT_SUCCESS);
}
