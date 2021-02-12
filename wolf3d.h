/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 22:02:54 by rosfryd           #+#    #+#             */
/*   Updated: 2021/02/11 21:47:48 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define RES_X 1980
# define RES_Y 1080

# define SCALE 40
# define PERS "NWSE"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libs/libft/libft.h"
# include "libs/minilibx/mlx.h"

typedef struct	s_help
{
	int		max_y;
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
	int x;
	int y;
}				t_player;

typedef struct	s_image
{
	char			*img;
	unsigned int	*addr;
	int				bpp;
	int				size_line;
	int				endian;
}				t_image;

typedef struct	s_all
{
	void		*mlx;
	void		*win;
	char		**map;
	t_help		*help;
	t_player	*player;
	t_mapa		*mapa;
	int			lst_size;
}				t_all;

void		draw_space(t_all *node);
void		make_array_map(t_list **head, int size);
void		ft_putendl(char *s);
void		ft_putchar(char c);
void		draw_map_2d(t_all *node, int size);
void		draw_square(t_all *node);
void		draw_person(t_all *node);
void		node_init(t_all *node, int size);
void		revert_x_y(t_all *node);
void		draw(t_all *node);



#endif
