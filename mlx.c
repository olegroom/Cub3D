/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:52:46 by rosfryd           #+#    #+#             */
/*   Updated: 2021/02/20 20:23:48 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_key(int key_code, t_all *node)
{
	if (key_code == 123)
		node->player->dir -= 0.05;
	else if (key_code == 124)
		node->player->dir += 0.05;
	else if (key_code == 13)
	{
		if (node->map[(int)(node->player->y + sin(node->player->dir)/4)]\
		[(int)(node->player->x + cos(node->player->dir)/4)] != '1')
		{
			node->player->x += cos(node->player->dir)/8;
			node->player->y += sin(node->player->dir)/8;
		}
	}
	else if (key_code == 1)
	{	
		if (node->map[(int)(node->player->y - sin(node->player->dir)/4)]\
		[(int)(node->player->x - cos(node->player->dir)/4)] != '1')
		{
			node->player->x -= cos(node->player->dir)/8;
			node->player->y -= sin(node->player->dir)/8;
		}
	}
	else if (key_code == 0)
	{
		if (node->map[(int)(node->player->y - cos(node->player->dir)/4)]\
		[(int)(node->player->x + sin(node->player->dir)/4)] != '1')
		{
			node->player->x += sin(node->player->dir)/12;
			node->player->y -= cos(node->player->dir)/12;
		}
	}
	else if (key_code == 2)
	{
		if (node->map[(int)(node->player->y + cos(node->player->dir)/4)]\
		[(int)(node->player->x - sin(node->player->dir)/4)] != '1')
		{
			node->player->x -= sin(node->player->dir)/12;
			node->player->y += cos(node->player->dir)/12;
		}
	}
	else if (key_code == 53)
		exit(0);
	// printf("\n%d\n", key_code);
	return (0);
}

int		draw_image(t_all *node)
{
	node->image->img = mlx_new_image(node->mlx, RES_X, RES_Y);
	node->image->addr = mlx_get_data_addr(node->image->img, &node->image->bpp, &node->image->size_line, &node->image->endian);
	draw_vector(node);
	// ft_put_2d_map_draw(node);
	mlx_put_image_to_window(node->mlx, node->win, node->image->img, 0, 0);
	mlx_destroy_image(node->mlx, node->image->img);
	return (0);
}

void		draw_column(t_all *node, double angle, double start)
{
	t_help help;

	node->column->height_pp = node->column->height_wall/\
	(node->player->i * cos(angle)) * node->column->dist_to_pp;
	node->column->k = (RES_Y - node->column->height_pp)/2;
	node->column->l = RES_Y - node->column->k;
	help.x = 0;
	help.y = node->column->l;
	help.max_x = (RES_Y - node->column->height_pp)/2;
	while (help.x < help.max_x)
		my_mlx_pixel_put(node->image, node->mapa->x, help.x++, create_trgb(node->ceiling->r, node->ceiling->g, node->ceiling->b));
	while (node->column->k < node->column->l)
		my_mlx_pixel_put(node->image, node->mapa->x, node->column->k++, 0x4444FF);
	while (help.y < RES_Y)
		my_mlx_pixel_put(node->image, node->mapa->x, help.y++, create_trgb(node->floor->r, node->floor->g, node->floor->b));
}

void	draw_vector(t_all *node)
{
	t_player plr;
	
	plr = *node->player;
	plr.l = plr.x * SCALE;
	plr.f = plr.y * SCALE;
	plr.start = node->player->dir - M_PI_4;
	plr.end = node->player->dir + M_PI_4;
	node->mapa->x = 0;
	while (plr.start < plr.end)
	{
		plr.x = plr.l;
		plr.y = plr.f;
		node->player->i = 0;
		while (/*plr.x < RES_X && plr.y < RES_Y && */plr.x > 0 && plr.y > 0 && node->map[(int)plr.y/SCALE][(int)plr.x/SCALE] != '1')
		{
			plr.x += cos(plr.start);
			plr.y += sin(plr.start);
			node->player->i++;
			// my_mlx_pixel_put(node->image, plr.x, plr.y, 0xF05500);
		}
		draw_column(node, plr.start - plr.dir, plr.start);
		node->mapa->x++;
		plr.start += STEP;
	}
}

void	draw_map_2d(t_all *node, int size)
{
	mlx_loop_hook(node->mlx, draw_image, node);
	mlx_hook(node->win, 2, 1L<<0, ft_key, node);
	mlx_loop(node->mlx);
}