/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 21:31:57 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/06/25 21:32:10 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		exit_x(t_coord *ptr)
{
	mlx_destroy_window(ptr->mlx[0], ptr->mlx[1]);
	ptr = NULL;
	exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_coord *ptr;

	ptr = NULL;
	if (argc == 2)
		ft_solve_1(ptr, argv[1]);
	else
	{
		ft_putendl("usage :fdf input map");
		exit(0);
	}
	return (0);
}
