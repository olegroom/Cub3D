# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/30 21:57:18 by rosfryd           #+#    #+#              #
#    Updated: 2021/03/21 20:03:13 by rosfryd          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC = 

OBJ = $(SRC:.o=.c)

LIBFT = ./libs/libft/libft.a

MINILIBX = ./libs/libft/libmlx.dylib

MLX = -lmlx -framework OpenGL -framework Appkit

MLX_N = libmlx.dylib -framework OpenGL -framework Appkit

all: $(NAME)

lib:
	$(MAKE) bonus -C libs/libft
	$(MAKE) clean -C libs/libft
	cp $(LIBFT) .

$(NAME):
	gcc parser.c main_parser.c parser_id.c ft_bmp.c sprite1.c mlx.c \
	cub_utils_1.c sprite.c ft_init.c cub_utils_2.c libft.a $(MLX) $(MLX_N)
	./a.out map.cub

save:
	gcc parser.c main_parser.c parser_id.c ft_bmp.c sprite1.c mlx.c \
	cub_utils_1.c sprite.c ft_init.c cub_utils_2.c libft.a $(MLX) $(MLX_N)
	./a.out map.cub --save

norm:
	norminette -R CheckForbiddenSourceHeader cub_utils_1.c cub_utils_2.c ft_init.c sprite.c sprite1.c ft_bmp.c mlx.c parser.c
clean:

fclean:

re:

bonus: