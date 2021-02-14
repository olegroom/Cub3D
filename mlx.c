/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:52:46 by rosfryd           #+#    #+#             */
/*   Updated: 2021/02/14 09:09:15 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"



int		ft_key(int key_code, t_all *node)
{
	if (key_code == 123)
	{
		node->player->dir -= 0.1;
		printf("DIRECTION: %.1f\n", node->player->dir);
	}
	else if (key_code == 124)
	{
		node->player->dir += 0.1;
		printf("DIRECTION: %.1f\n", node->player->dir);
	}
	else if (key_code == 125)
	{
		node->player->y++;
		printf("down and x = %f\n", node->player->x);
		printf("down and y = %f\n", node->player->y);
	}
	else if (key_code == 126)
	{	
		node->player->y--;
		printf("up and x = %f\n", node->player->x);
		printf("up and y = %f\n", node->player->y);
	}
	else if (key_code == 53)
		exit(0);
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
				draw_square(node, 0xFFFFFF);
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
	while (node->help->y < node->help->y_scale)
	{
		while (node->help->x < node->help->x_scale)
			my_mlx_pixel_put(node->image, node->help->x++, node->help->y, color);
		node->help->x -= SCALE;
		node->help->y++;
	}
}

void	draw_vector(t_all *node)
{
	t_player plr = *node->player;

	double f;
	double l;
	l = plr.x * SCALE;
	f = plr.y * SCALE;

	plr.start = node->player->dir - M_PI_4;
	plr.end = node->player->dir + M_PI_4;

	while (plr.start < plr.end)
	{
		plr.x = l;
		plr.y = f;
		while (node->map[(int)plr.y/SCALE][(int)plr.x/SCALE] != '1')
		{
			plr.x += cos(plr.start);
			plr.y += sin(plr.start);
			my_mlx_pixel_put(node->image, plr.x, plr.y, 0xF05500);
		}
		plr.start += M_PI_2 / 120;
	}
}

void	draw_map_2d(t_all *node, int size)
{
	mlx_loop_hook(node->mlx, draw_image, node);
	mlx_hook(node->win, 2, 1L<<0, ft_key, node);
	mlx_loop(node->mlx);
}