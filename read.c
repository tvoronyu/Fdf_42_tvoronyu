/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 15:50:32 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/06/25 21:34:09 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_mas(char ***mas)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (mas[i])
	{
		n = 0;
		while (mas[i][n])
		{
			free(mas[i][n]);
			n++;
		}
		free(mas[i]);
		i++;
	}
	free(mas);
}

void	ft_free_mas_2(char **mas)
{
	int i;

	i = 0;
	while (mas[i])
	{
		free(mas[i]);
		i++;
	}
	free(mas);
}

int		ft_read_help(int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		free(line);
		i++;
	}
	return (i);
}

int		ft_read_helper(char *name_file)
{
	int fd;

	if ((fd = open(name_file, O_RDWR)) == -1)
		ft_error();
	return (fd);
}

char	**ft_read(char *name_file, int fd)
{
	char	*line;
	char	**str;
	int		i;

	i = ft_read_help(fd);
	close(fd);
	fd = ft_read_helper(name_file);
	str = (char**)malloc(sizeof(char*) * (i + 1));
	str[i] = NULL;
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		str[i++] = ft_strdup(line);
		if (line[0] == '\0')
			ft_error_map(1);
		free(line);
	}
	close(fd);
	if (ft_valid_map(str))
	{
		ft_free_mas_2(str);
		ft_error_map(2);
	}
	return (str);
}
