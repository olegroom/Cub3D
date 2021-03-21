/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:52:46 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/21 20:12:49 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		endx(t_all *node)
{
	exit(0);
	return (0);
}

void	draw_map_2d(t_all *node, int size)
{
	mlx_loop_hook(node->mlx, draw_image, node);
	mlx_hook(node->win, 2, 1L << 0, ft_key, node);
	mlx_hook(node->win, 17, 0, endx, node);
	mlx_loop(node->mlx);
}

int		draw_image(t_all *node)
{
	node->image->img = mlx_new_image(node->mlx, node->res_x, node->res_y);
	node->image->addr = mlx_get_data_addr(node->image->img, \
	&node->image->bpp, &node->image->size_line, &node->image->endian);
	draw_vector(node);
	mlx_put_image_to_window(node->mlx, node->win, node->image->img, 0, 0);
	mlx_destroy_image(node->mlx, node->image->img);
	return (0);
}

void	draw_vector(t_all *node)
{
	t_player	plr;
	t_help3		help3;

	node->mapa->l = node->res_x - 1;
	plr_init(node, &plr, &help3);
	if (node->player->dir >= 2 * M_PI)
		node->player->dir -= 2 * M_PI;
	else if (node->player->dir <= -2 * M_PI)
		node->player->dir += 2 * M_PI;
	get_sprite_data(node, help3);
	while (plr.start < plr.end)
	{
		node->player->i = 0;
		plr.y = plr.f;
		plr.x = plr.l;
		while (plr.x > 0 && plr.y > 0 && node->map[(int)plr.y / SCALE]\
		[(int)plr.x / SCALE] != '1')
		{
			help3.x = plr.x / SCALE;
			help3.y = plr.y / SCALE;
			plr.x += cos(plr.start);
			plr.y -= sin(plr.start);
			node->player->i++;
		}
		draw_column(node, plr, help3);
		draw_sprite(node, 0);
		node->mapa->l--;
		if (node->mapa->l == -1)
			break ;
		plr.start += node->step;
	}
}

void	draw_column(t_all *node, t_player plr, t_help3 help3)
{
	t_help	help;
	int		color;
	int		ind;

	node->column->height_pp = node->column->height_wall / \
	(node->player->i * cos(plr.start - plr.dir)) * node->column->dist_to_pp;
	node->column->k = (node->res_y - node->column->height_pp) / 2;
	node->column->l = node->res_y - node->column->k;
	help.x = 0;
	help.y = node->column->l;
	help.max_x = (node->res_y - node->column->height_pp) / 2;
	ind = 0;
	while (help.x < help.max_x)
		my_mlx_pixel_put(node, node->mapa->l, help.x++, \
		create_trgb(node->ceiling->r, node->ceiling->g, node->ceiling->b));
	while (node->column->k < node->column->l)
	{
		if ((int)help3.y == (int)plr.y / SCALE && help3.x < plr.x / SCALE)
		{
			node->texture[0].step_x = (int)plr.y % 64;
			node->texture[0].step_y = 64 / node->column->height_pp;
			color = *(node->texture[0].addr + (int)((int)(node->texture[0].\
			step_y * ind) * node->texture[0].width + node->texture[0].step_x));
			node->help2->i = 0;
		}
		else if ((int)help3.y == (int)plr.y / SCALE && help3.x > plr.x / SCALE)
		{
			node->texture[1].step_x = (int)plr.y % 64;
			node->texture[1].step_y = 64 / node->column->height_pp;
			color = *(node->texture[1].addr + (int)((int)(node->texture[1].\
			step_y * ind) * node->texture[1].width + node->texture[1].step_x));
			node->help2->i = 1;
		}
		else if (help3.y > plr.y / SCALE && (int)help3.x == (int)plr.x / SCALE)
		{
			node->texture[2].step_x = (int)plr.x % 64;
			node->texture[2].step_y = 64 / node->column->height_pp;
			color = *(node->texture[2].addr + (int)((int)(node->texture[2].\
			step_y * ind) * node->texture[2].width + node->texture[2].step_x));
			node->help2->i = 2;
		}
		else if (help3.y < plr.y / SCALE && (int)help3.x == (int)plr.x / SCALE)
		{
			node->texture[3].step_x = (int)plr.x % 64;
			node->texture[3].step_y = 64 / node->column->height_pp;
			color = *(node->texture[3].addr + (int)((int)(node->texture[3].\
			step_y * ind) * node->texture[3].width + node->texture[3].step_x));
			node->help2->i = 3;
		}
		else
		{
			if (node->help2->i == 0)
				color = *(node->texture[0].addr + (int)((int)(node->texture[0].\
				step_y * ind) * node->texture[0].width + node->texture[0].step_x));
			else if (node->help2->i == 1)
				color = *(node->texture[1].addr + (int)((int)(node->texture[1].\
				step_y * ind) * node->texture[1].width + node->texture[1].step_x));
			else if (node->help2->i == 2)
				color = *(node->texture[2].addr + (int)((int)(node->texture[2].\
				step_y * ind) * node->texture[2].width + node->texture[2].step_x));
			else if (node->help2->i == 3)
				color = *(node->texture[3].addr + (int)((int)(node->texture[3].\
				step_y * ind) * node->texture[3].width + node->texture[3].step_x));
		}
		my_mlx_pixel_put(node, node->mapa->l, node->column->k++, color);
		ind++;
	}
	while (help.y < node->res_y)
		my_mlx_pixel_put(node, node->mapa->l, help.y++, \
		create_trgb(node->floor->r, node->floor->g, node->floor->b));
}

int		ft_key(int key_code, t_all *node)
{
	if (key_code == 123)
		node->player->dir += 0.06;
	else if (key_code == 124)
		node->player->dir -= 0.06;
	else if (key_code == 13)
	{
		if (node->map[(int)(node->player->y - sin(node->player->dir)/8)]\
		[(int)(node->player->x + cos(node->player->dir)/8)] != '1')
		{
			node->player->x += cos(node->player->dir)/8;
			node->player->y -= sin(node->player->dir)/8;
		}
	}
	else if (key_code == 1)
	{
		if (node->map[(int)(node->player->y + sin(node->player->dir)/8)]\
		[(int)(node->player->x - cos(node->player->dir)/8)] != '1')
		{
			node->player->x -= cos(node->player->dir)/8;
			node->player->y += sin(node->player->dir)/8;
		}
	}
	else if (key_code == 0)
	{
		if (node->map[(int)(node->player->y - cos(node->player->dir)/12)]\
		[(int)(node->player->x - sin(node->player->dir)/12)] != '1')
		{
			node->player->x -= sin(node->player->dir)/12;
			node->player->y -= cos(node->player->dir)/12;
		}
	}
	else if (key_code == 2)
	{
		if (node->map[(int)(node->player->y + cos(node->player->dir)/12)]\
		[(int)(node->player->x + sin(node->player->dir)/12)] != '1')
		{
			node->player->x += sin(node->player->dir)/12;
			node->player->y += cos(node->player->dir)/12;
		}
	}
	else if (key_code == 53)
		exit(0);
	return (0);
}
