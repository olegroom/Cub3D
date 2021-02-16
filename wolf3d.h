/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 22:02:54 by rosfryd           #+#    #+#             */
/*   Updated: 2021/02/15 17:08:58 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define RES_X 2560
# define RES_Y 1440

# define SCALE 70
# define PERS "NWSE"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "libs/libft/libft.h"
# include "libs/minilibx/mlx.h"

typedef struct	s_help
{
	int		max_y;
	int		max_x;
	int		x;
	int		y;
	int		x_scale;
	int		y_scale;
}				t_help;

typedef struct	s_mapa
{
	int		x;
	int		y;
	int		x_max;
	int		y_max;
}				t_mapa;

typedef struct	s_player
{
	double	x;
	double	y;
	double	dir;
	double	start;
	double	end;
	double	i;
}				t_player;

typedef struct	s_image
{
	char	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}				t_image;

typedef struct	s_point
{
	int	x;
	int y;
}				t_point;

typedef struct	s_all
{
	void		*mlx;
	void		*win;
	char		**map;
	t_image		*image;
	t_help		*help;
	t_player	*player;
	t_mapa		*mapa;
	int			lst_size;
}				t_all;

void		draw_vector(t_all *node);
void		draw_space(t_all *node);
void		make_array_map(t_list **head, int size);
void		ft_putendl(char *s);
void		ft_putchar(char c);
void		draw_map_2d(t_all *node, int size);
int			draw_image(t_all *node);
void		draw_person(t_all *node);
void		node_init(t_all *node, int size);
void		revert_x_y(t_all *node);
void		draw_square(t_all *node, int color);
void		my_mlx_pixel_put(t_image *image, int x, int y, int color);
void		draw_column(t_all *node);

#endif
