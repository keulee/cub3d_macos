# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keulee <keulee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 18:18:39 by keulee            #+#    #+#              #
#    Updated: 2021/05/21 00:29:38 by keulee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = srcs/cub3d.c \
		srcs/get_next_line.c \
		srcs/cub3d_utiles_01.c srcs/cub3d_utiles_02.c \
		srcs/cub3d_keypress.c srcs/cub3d_set_tex_img.c \
		srcs/cub3d_render.c srcs/cub3d_player_move.c \
		srcs/cub3d_bmp_screenshot.c \
		srcs/cub01_init.c \
		srcs/cub02_info_validation_check.c \
		srcs/cub03_read_info.c srcs/cub03_parsing_resolution.c srcs/cub03_parsing_color.c \
		srcs/cub04_read_map.c srcs/cub04_create_player.c \
		srcs/cub05_map_validation_check.c \
		srcs/cub06_ray.c \
		srcs/cub07_sort_sprite.c srcs/cub07_sprite_ray.c srcs/cub07_set_sprite.c \
		srcs/cub06_ray_processing.c

OBJS = $(SRCS:.c=.o)

CC = clang

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

MLX = -L. -lft -L. -lmlx -framework OpenGL -framework AppKit

MINILIB = libmlx.a

LIBFT = libft.a

RM = rm -f

BMP = screenshot.bmp

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIB) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX)

$(MINILIB):
	$(MAKE) -C mlx
	mv mlx/$(MINILIB) .

$(LIBFT):
	$(MAKE) -C libft
	mv libft/$(LIBFT) .

clean:
	$(MAKE) -C mlx clean
	$(MAKE) -C libft clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME) $(MINILIB) $(LIBFT)
	$(RM) $(BMP)

re: fclean all

.PHONY: all clean fclean re
