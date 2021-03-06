# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/30 21:57:18 by rosfryd           #+#    #+#              #
#    Updated: 2021/03/06 05:13:12 by rosfryd          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC = 

OBJ = $(SRC:.o=.c)

LIBFT = ./libs/libft/libft.a

MINILIBX = ./libs/libft/libmlx.dylib

MLX = -lmlx -framework OpenGL -framework Appkit

all: $(NAME)

lib:
	$(MAKE) bonus -C libs/libft
	$(MAKE) clean -C libs/libft
	cp $(LIBFT) .

$(NAME):
	gcc parser.c ft_bmp.c mlx.c cub_utils_1.c sprite.c ft_init.c cub_utils_2.c libft.a $(MLX)
	./a.out map.cub

img:
	gcc img_test.c libft.a $(MLX)
	./a.out