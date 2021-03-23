# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/30 21:57:18 by rosfryd           #+#    #+#              #
#    Updated: 2021/03/24 01:40:31 by rosfryd          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC = 	parser_utils_3.c parser_utils_1.c parser_utils_2.c mlx_utils_1.c mlx_utils_2.c \
		parser.c main_parser.c parser_id.c ft_bmp.c sprite1.c mlx.c cub_utils_1.c \
		sprite.c ft_init.c cub_utils_2.c

OBJ = $(SRC:.c=.o)

LIBFT = ./libs/libft/libft.a

MINILIBX = ./libs/libft/libmlx.dylib

MLX = -lmlx -framework OpenGL -framework Appkit

MLX_N = libs/minilibx/libmlx.dylib -framework OpenGL -framework Appkit

CC = gcc -Wall -Wextra -Werror -g

all: libft minilibx $(NAME)

$(%.o): $(%.c)
	$(CC) -o $@ -c $^

libft:
	$(MAKE) -C libs/libft
	$(MAKE) bonus -C libs/libft

minilibx:
	$(MAKE) -C libs/minilibx

$(NAME): $(OBJ)
	@echo "\n\033[0;33mCompiling..."
	$(CC) -o $@ $^ $(LIBFT) $(MLX) $(MLX_N)
	@echo "\033[0m"

clean:
	$(MAKE) clean -C libs/libft
	$(MAKE) clean -C libs/minilibx
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) fclean -C libs/libft
	rm -rf $(NAME)

re: fclean all