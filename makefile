# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 17:04:18 by tvoronyu          #+#    #+#              #
#    Updated: 2018/05/30 17:12:49 by tvoronyu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c \
	  read.c \
	  ft_write.c \
	  ft_solve_1.c \
	  mlx_pixel_put.c \
	  ft_solve_2.c \
	  ft_error.c \
	  ft_valid_map.c \
	  ft_key.c \
	  ft_creat_window.c \
	  ft_colors.c \
	  ft_key_2.c \

CC = gcc

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -I fdf.h

LIBFT = libft/libft.a

IN = -I /usr/local/include

IN_2 = -L /usr/local/lib/ -lmlx\
	   	-framework OpenGl -framework AppKit

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(IN) $(OBJ) $(IN_2) $(LIBFT) -o $(NAME)

$(OBJ): $(SRC)
	$(CC) $(FLAGS) -c $(SRC)

$(LIBFT):
	@make -C libft/

clean:
	@rm -f $(OBJ)
	@make clean -C libft/

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft/

re: fclean all