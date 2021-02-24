/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:52:46 by rosfryd           #+#    #+#             */
/*   Updated: 2021/02/24 22:27:09 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_map_2d(t_all *node, int size)
{
	mlx_loop_hook(node->mlx, draw_image, node);
	mlx_hook(node->win, 2, 1L << 0, ft_key, node);
	mlx_loop(node->mlx);
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

void	draw_vector(t_all *node)
{
	t_player	plr;
	t_help		help;

	plr_init(node, &plr, &help);
	while (plr.start < plr.end)
	{
		plr.x = plr.l;
		plr.y = plr.f;
		node->player->i = 0;
		while (plr.x > 0 && plr.y > 0 && node->map[(int)plr.y/SCALE][(int)plr.x/SCALE] != '1')
		{
			help.x = plr.x/SCALE;
			help.y = plr.y/SCALE;
			plr.x += cos(plr.start);
			plr.y += sin(plr.start);
			node->player->i++;
			// my_mlx_pixel_put(node->image, plr.x, plr.y, 0xF05500);
		}
		draw_wall_side(node, help, plr);
		// draw_column(node, plr, 0xFF0000);
		node->mapa->x++;
		plr.start += STEP;
	}
}

void	draw_wall_side(t_all *node, t_help help, t_player plr)
{
	int color;
	if ((int)help.y == (int)plr.y/SCALE && help.x < plr.x/SCALE)
	{
		node->texture->step_x = (int)plr.x % 64;
		node->texture->step_y = 64/node->column->height_pp;
		draw_column(node, plr, color);
		node->help2->i = 0;
	}
	else if ((int)help.y == (int)plr.y/SCALE && help.x > plr.x/SCALE)
	{
		draw_column(node, plr, color);
		node->help2->i = 1;
	}
	else if (help.y > plr.y/SCALE && (int)help.x == (int)plr.x/SCALE)
	{
		draw_column(node, plr, color);
		node->help2->i = 2;
	}
	else if (help.y < plr.y/SCALE && (int)help.x == (int)plr.x/SCALE)
	{
		draw_column(node, plr, color);
		node->help2->i = 3;
	}
	else
	{
		if (node->help2->i == 0)
			draw_column(node, plr, color);
		else if (node->help2->i == 1)
			draw_column(node, plr, color);
		else if (node->help2->i == 2)
			draw_column(node, plr, color);
		else if (node->help2->i == 3)
			draw_column(node, plr, color);
	}
}

void		draw_column(t_all *node, t_player plr, int color)
{
	t_help help;

	node->column->height_pp = node->column->height_wall/\
	(node->player->i * cos(plr.start - plr.dir)) * node->column->dist_to_pp;
	node->column->k = (RES_Y - node->column->height_pp)/2;
	node->column->l = RES_Y - node->column->k;
	help.x = 0;
	help.y = node->column->l;
	help.max_x = (RES_Y - node->column->height_pp)/2;

	double ind = 0;
	while (help.x < help.max_x)
		my_mlx_pixel_put(node->image, node->mapa->x, help.x++, create_trgb(node->ceiling->r, node->ceiling->g, node->ceiling->b));
	while (node->column->k < node->column->l)
	{
		color = *(node->texture->addr + (int)((int)(node->texture->step_y * ind) * node->texture->width + node->texture->step_x));
		my_mlx_pixel_put(node->image, node->mapa->x, node->column->k++, color);
		ind++;
	}
	while (help.y < RES_Y)
		my_mlx_pixel_put(node->image, node->mapa->x, help.y++, create_trgb(node->floor->r, node->floor->g, node->floor->b));
}

int		ft_key(int key_code, t_all *node)
{
	if (key_code == 123)
		node->player->dir -= 0.025;
	else if (key_code == 124)
		node->player->dir += 0.025;
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
