/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 15:13:39 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/06/30 04:42:41 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define UP "Move up    -  press up"
# define DOWN "Move down  -  press down"
# define LEFT "Move left  -  press left"
# define RIGHT "Move right -  press right"
# define ZOOM_1 "ZOOM '-'   -  press '-'"
# define ZOOM_2 "ZOOM '+'   -  press '+'"
# define HIGHT_UP "HIGHT_UP   -  press '['"
# define HIGHT_DOWN "HIGHT_DOWN -  press ']'"
# define ZOOM_1_WINDOW "CHANCHE SIZE WINDOW - press"
# define ZOOM_2_WINDOW "A', 'D', 'W', 'S', 'Q', 'E'"
# define COLOR_1 "COLOR GREY - press 1"
# define COLOR_2 "COLOR BLUE - press 2"
# define COLOR_3 "COLOR RED - press 3"
# define RESET_COLOR "RESET COLOR - press 4"
# include <math.h>
# include "mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"

typedef	struct	s_mas
{
	char				*name_file;
	int					count_x0;
	int					count_y0;
	int					len_mas_y;
	int					len_mas_x;
	char				**str;
	void				*mlx[3];
	int					wight;
	int					hight;
	int					vid_x;
	int					vid_y;
	int					x0;
	int					y0;
	int					x1;
	int					y1;
	int					flag;
	int					len_mas_x_reserv;
	int					len_mas_y_reserv;
	float				zoom;
	float				rost;
	float				shag;
	float				up_down;
	float				left_right;
	char				***mas_y;
	char				***mas_x;
	char				***colors;
	int					color_1;
	int					color_2;
	char				*color_random;
}				t_coord;

void			ft_error(void);
void			ft_error_map(int i);
void			ft_success_end(t_coord *ptr);
int				exit_x(t_coord *ptr);
void			ft_free_mas(char ***mas);
char			**ft_read(char *name_file, int fd);
void			ft_creat_mas_y(t_coord *ptr);
void			ft_creat_mas_x(t_coord *ptr);
void			ft_write_mas(t_coord *mas);
int				ft_int_str_count(t_coord *ptr, char c);
void			ft_solve(t_coord *ptr, int flag);
void			ft_brezenhem(t_coord *ptr);
void			ft_solve_1(t_coord *ptr, char *name_file);
void			ft_solve_2(t_coord *ptr);
int				ft_count_y(t_coord *ptr);
void			ft_free_mas_2(char **mas);
char			**ft_clear_mas_x(t_coord *ptr, char **str, int n);
int				ft_valid_map(char **str);
int				ft_count_str(char **str);
void			ft_creat_window_1(t_coord *ptr, int flag);
void			ft_creat_window_2(t_coord *ptr, int flag);
void			ft_colors(t_coord *ptr);
void			ft_key_up_down_right_left(t_coord *ptr, int key);
void			ft_key_rost_shag(t_coord *ptr, int key);
void			ft_key_zoom(t_coord *ptr, int key);
int				deal_key(int key, t_coord *ptr);
int				deal_key_mouse(int key, int x, int y, t_coord *ptr);
void			ft_colors_key(t_coord *ptr, int key);
int				ft_read_helper(char *name_file);

#endif
