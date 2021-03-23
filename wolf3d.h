/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 22:02:54 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/23 22:48:12 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define SCALE 64
# define PERS "NWSE"

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include "libs/libft/libft.h"
# include "libs/minilibx/mlx.h"

typedef struct	s_pars_h
{
	int flag;
	int x;
	int curr_x;
	int next_x;
	int temp_x;
}				t_pars_h;

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

typedef struct	s_parser
{
	int x;
	int y;
}				t_parser;

typedef struct	s_h
{
	int 	r;
	int 	f;
	int 	c;
	int		so;
	int		no;
	int		we;
	int		ea;
	int		spr;
}				t_h;

typedef struct	s_start
{
	int 	ind;
	int 	color;
}				t_start;

typedef struct	s_all
{
	t_mapa		*mapa;
	void		*win;
	void		*mlx;
	int			lst_size;
	char		*so;
	char		*no;
	char		*we;
	char		**map;
	char		*ea;
	char		*spr;
	double		step;
	int			res_x;
	int			res_y;
	int			num_sprts;
	t_player	*player;
	t_texture	*te;
	t_sprite	*sprite;
	t_image		*image;
	t_column	*column;
	t_color		*ceiling;
	t_help		*help;
	t_help2		*help2;
	t_h			*h;
	t_color		*floor;
}				t_all;

int			check_flags(t_all *node);
void		init_flags(t_all *node, t_help *n);
void		help_init(t_all *node, t_pars_h *he, int y);
void		check_errors(t_all *node, t_pars_h *he, int y);
void		check_next_x(t_all *node, int curr_x, int next_x, int y);
void		check_curr_x(t_all *node, int curr_x, int next_x, int y);
void		check_next_step(t_all *node, char direct);
void		ft_draw_init(t_all *node, t_help *help, t_start *start, t_player *plr);
void		borders_draw(t_all *node, t_start *start);
void		rot_protection(t_all *node);
void		find_color(t_all *node, t_player *plr, t_start *start, int st);
void		cast_ray(t_all *node, t_player *plr, t_help3 *help3);
void		check_resol(t_all *node, t_help *help);
int			get_sprite_color(t_all *node, int y, int i);
void		find_spr_pos(t_all *node, int n, int m);
void		ft_sort(t_all *node, int i);
double		get_delta(double start, double spr_angle);
void		get_params(t_all *node, t_help3 help3);
int			go_pars_east(t_all *node, int y, int x);
int			go_pars_west(t_all *node, int y, int x);
int			go_pars_north(t_all *node, int y, int x);
int			go_pars_south(t_all *node, int y, int x);
int			go_pars_spr(t_all *node, int y, int x);
int			go_pars_c(t_all *node, int y, int x);
int			go_pars_f(t_all *node, int y, int x);
int			go_pars_r(t_all *node, int y, int x);
void		pars_data(t_all *node);
int			check_extension(char **argv);
int			error_found(char *s1);
int			endx(t_all *node);
int			ft_strcmp(char *s1, char *s2);
void		ft_fill(t_all *node);
void		make_bmp(t_list **head, int size, int i);
void		ft_bmp(t_all *node);
void		draw_sprite(t_all *node, int i);
void		find_num_sprites(t_all *node);
void		get_sprite_data(t_all *node, t_help3 help3);
void		fill_sprite_x_y(t_all *node);
void		init_textures(t_all *node);
void		draw_vector(t_all *node);
void		make_array_map(t_list **head, int size);
void		ft_putendl(char *s);
void		ft_putchar(char c);
void		draw_map_2d(t_all *node, int size);
int			draw_image(t_all *node);
void		node_init(t_all *node);
void		revert_x_y(t_all *node);
void		my_mlx_pixel_put(t_all *node, int x, int y, int color);
void		draw_column(t_all *node, t_player plr, t_help3 help3);
int			create_trgb(int r, int g, int b);
int			ft_key(int key_code, t_all *node);
void		plr_init(t_all *node, t_player *plr, t_help3 *help3);

#endif
