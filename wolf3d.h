/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 22:02:54 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/08 14:45:18 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define RES_X 1800
# define RES_Y 1200
# define STEP M_PI_2/RES_X
# define SCALE 64
# define PERS "NWSE"

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "libs/libft/libft.h"
# include "libs/minilibx/mlx.h"

typedef struct	s_help3
{
	int		x;
	int		y;
	double	plrx;
	double	plry;
}				t_help3;

typedef struct	s_help2
{
	int		i;
	double	x;
}				t_help2;

typedef struct	s_help
{
	int		max_y;
	int		max_x;
	int		x;
	int		y;
	int		x_scale;
	int		y_scale;
	int		i;
}				t_help;

typedef struct	s_mapa
{
	int		x;
	int		y;
	int		l;
}				t_mapa;

typedef struct	s_player
{
	double	x;
	double	y;
	double	dir;
	double	start;
	double	end;
	double	i;
	double	l;
	double	f;
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

typedef	struct	s_column
{
	double	height_wall;
	double	height_pp;
	double	dist_to_wall;
	double	dist_to_pp;
	double	k;
	double	l;
}				t_column;

typedef	struct	s_color
{
	int r;
	int g;
	int b;
}				t_color;

typedef struct	s_texture
{
	void	*img;
	int		*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
	double	step_y;
	double	step_x;
	char	*path;
}				t_texture;

typedef struct	s_sprite
{
	int		i;
	double	x;
	double	y;
	double	hyp;
	double	screen_size;
	int		v_offset;
	int		h_offset;
	double	angle;
	double	del_angle;
	
}				t_sprite;

typedef struct	s_bmp
{
	char		*img;
	int			size;
	int			color;
	int			fd;
	char		header[14];
	char		meta[40];
	char		padding[3];
}				t_bmp;


typedef struct	s_all
{
	void		*mlx;
	void		*win;
	char		**map;
	int			lst_size;
	int			num_sprts;
	t_sprite	*sprite;
	t_help		*help;
	t_help2		*help2;
	t_image		*image;
	t_texture	*texture;
	t_player	*player;
	t_column	*column;
	t_mapa		*mapa;
	t_color		*ceiling;
	t_color		*floor;
}				t_all;

int			ft_strcmp(char *s1, char *s2);
void		ft_fill(t_all *node);
void		make_bmp(t_list **head, int size);
void		ft_bmp(t_all *node);
void		draw_sprite(t_all *node);
void		find_num_sprites(t_all *node);
void		get_sprite_data(t_all *node, t_help3 help3);
void		get_params(t_all *node, t_help3 help3);
void		fill_sprite_x_y(t_all *node);
void		init_textures(t_all *node);
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
void		draw_column(t_all *node, t_player plr, t_help3 help3);
void		ft_put_2d_map_draw(t_all *node);
int			create_trgb(int r, int g, int b);
void		draw_wall_side(t_all *node, t_help help, t_player plr);
void		ft_init_1(t_all *node);
int			ft_key(int key_code, t_all *node);
void		plr_init(t_all *node, t_player *plr, t_help3 *help3);

#endif
