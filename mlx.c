/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:52:46 by rosfryd           #+#    #+#             */
/*   Updated: 2021/02/16 21:34:26 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"



int		ft_key(int key_code, t_all *node)
{
	if (key_code == 123)
	{
		node->player->dir -= M_PI_2 / 360 * 10;
		printf("DIRECTION: %.1f\n", node->player->dir);
		printf("sin = %f\ncos = %f\n", sin(node->player->dir), cos(node->player->dir));
	}
	else if (key_code == 124)
	{
		node->player->dir += M_PI_2 / 360 * 10;
		printf("DIRECTION: %.1f\n", node->player->dir);
		printf("sin = %f\ncos = %f\n", sin(node->player->dir), cos(node->player->dir));
	}
	else if (key_code == 13)
	{
		if (node->map[(int)(node->player->y + sin(node->player->dir)/3)]\
		[(int)(node->player->x + cos(node->player->dir)/3)] != '1')
		{
			node->player->x += cos(node->player->dir)/4;
			node->player->y += sin(node->player->dir)/4;
			printf("forward: x = %.3f\n", node->player->x);
			printf("forward: y = %.3f\n", node->player->y);
		}
	}
	else if (key_code == 1)
	{	
		if (node->map[(int)(node->player->y - sin(node->player->dir)/3)]\
		[(int)(node->player->x - cos(node->player->dir)/3)] != '1')
		{
			node->player->x -= cos(node->player->dir)/4;
			node->player->y -= sin(node->player->dir)/4;
		}
	}
	else if (key_code == 0)
	{
		if (node->map[(int)(node->player->y - cos(node->player->dir)/3)]\
		[(int)(node->player->x + sin(node->player->dir)/3)] != '1')
		{
		node->player->x += sin(node->player->dir)/4;
		node->player->y -= cos(node->player->dir)/4;
		}
	}
	else if (key_code == 2)
	{
		if (node->map[(int)(node->player->y + cos(node->player->dir)/3)]\
		[(int)(node->player->x - sin(node->player->dir)/3)] != '1')
		{
		node->player->x -= sin(node->player->dir)/4;
		node->player->y += cos(node->player->dir)/4;
		}
	}
	else if (key_code == 53)
		exit(0);
	printf("\n%d\n", key_code);
	return (0);
}

int		draw_image(t_all *node)
{
	node->image->img = mlx_new_image(node->mlx, RES_X, RES_Y);
	node->image->addr = mlx_get_data_addr(node->image->img, &node->image->bpp, &node->image->size_line, &node->image->endian);
	node->mapa->x = 0;
	while (node->mapa->x < node->lst_size)
	{
		node->mapa->y = 0;
		while (node->map[node->mapa->x][node->mapa->y] != '\0')
		{
			if (node->map[node->mapa->x][node->mapa->y] == '1')
			{
					draw_square(node, 0xFFFFFF);
			}
			node->mapa->y++;
			if (node->help->max_y < node->mapa->y)
				node->help->max_y = node->mapa->y;
		}
		node->mapa->x++;
	}
	draw_vector(node);
	mlx_put_image_to_window(node->mlx, node->win, node->image->img, 0, 0);
	mlx_destroy_image(node->mlx, node->image->img);
	return (0);
}

void	draw_square(t_all *node, int color)
{
	node->help->x = node->mapa->y * SCALE;
	node->help->y = node->mapa->x * SCALE;
	
	node->help->y_scale = node->help->y + SCALE;
	node->help->x_scale = node->help->x + SCALE;
	while (node->help->y < node->help->y_scale - 1)
	{
		while (node->help->x < node->help->x_scale - 1)
			my_mlx_pixel_put(node->image, node->help->x++, node->help->y, color);
		node->help->x -= SCALE - 1;
		node->help->y++;
	}
}

// void		draw_column(t_all *node, double angle)
// {

// 	node->player->i *= cos(angle);

// 	while (node->column->k < node->column->l)
// 		my_mlx_pixel_put(node->image, node->mapa->x, node->column->k++, 0x9999FF);	
// }

void	draw_vector(t_all *node)
{
	t_player plr = *node->player;

	double f;
	double l;
	l = plr.x * SCALE;
	f = plr.y * SCALE;

	plr.start = node->player->dir - M_PI_4;
	plr.end = node->player->dir + M_PI_4;
	node->mapa->x = 0;
	while (plr.start < plr.end)
	{
		plr.x = l;
		plr.y = f;
		node->player->i = 0;
		while (node->map[(int)plr.y/SCALE][(int)plr.x/SCALE] != '1')
		{
			plr.x += cos(plr.start);
			plr.y += sin(plr.start);
			node->player->i++;
			my_mlx_pixel_put(node->image, plr.x, plr.y, 0xF05500);
		}
		// draw_column(node, plr.start - plr.dir);
		// node->mapa->x++;
		plr.start += M_PI_2 / RES_X;
	}
}

void	draw_map_2d(t_all *node, int size)
{
	mlx_loop_hook(node->mlx, draw_image, node);
	mlx_hook(node->win, 2, 1L<<0, ft_key, node);
	mlx_loop(node->mlx);
}