/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:52:46 by rosfryd           #+#    #+#             */
/*   Updated: 2021/02/12 04:37:19 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"



int		ft_key(int key_code, t_all *node)
{
	if (key_code == 123)
	{
		node->player->x--;
		printf("left and x = %d\n", node->player->x);
		printf("left and y = %d\n", node->player->y);
	}
	else if (key_code == 124)
	{
		node->player->x++;
		printf("right and x = %d\n", node->player->x);
		printf("right and y = %d\n", node->player->y);
	}
	else if (key_code == 125)
	{
		node->player->y++;
		printf("down and x = %d\n", node->player->x);
		printf("down and y = %d\n", node->player->y);
	}
	else if (key_code == 126)
	{	
		node->player->y--;
		printf("up and x = %d\n", node->player->x);
		printf("up and y = %d\n", node->player->y);
	}
	return (0);
}

int		render_next_frame(t_all *node)
{
	t_image image;
	image.img = mlx_new_image(node->mlx, RES_X, RES_Y);
	image.addr = mlx_get_data_addr(image.img, &image.bpp, &image.size_line, &image.endian);
	draw_image(node, &image);
	mlx_put_image_to_window(node->mlx, node->win, image.img, 0, 0);
	return (0);
}

void	draw_image(t_all *node, t_image *image)
{
	node->mapa->x = 0;
	while (node->mapa->x < node->lst_size)
	{
		node->mapa->y = 0;
		while (node->map[node->mapa->x][node->mapa->y] != '\0')
		{
			draw(node, image);
			draw_person(node, image);
			node->mapa->y++;
			if (node->help->max_y < node->mapa->y)
				node->help->max_y = node->mapa->y;
		}
		node->mapa->x++;
	}	
}

void	draw_map_2d(t_all *node, int size)
{
	mlx_loop_hook(node->mlx, render_next_frame, node);
	mlx_hook(node->win, 2, 1L<<0, ft_key, node);
	mlx_loop(node->mlx);
}

void	draw(t_all *node, t_image *image)
{
	int i;
	int j;
	int x;
	int y;

	x = node->mapa->y * SCALE;
	y = node->mapa->x * SCALE;
	i = y + SCALE;
	j = x + SCALE;
	while (y < i)
	{
		while (x < j)
		{
			if (node->map[node->mapa->x][node->mapa->y] == '1')
				my_mlx_pixel_put(image, x, y, 0xFFFFFF);
			else if (node->map[node->mapa->x][node->mapa->y] == '0'|| \
			ft_strchr(PERS, node->map[node->mapa->x][node->mapa->y]))
				my_mlx_pixel_put(image, x, y, 0x000000);
			x++;
		}
		x -= SCALE;
		y++;
	}
}

void	draw_person(t_all *node, t_image *image)
{
	int i;
	int j;
	int x;
	int y;

	x = (node->player->x - 1) * SCALE;
	y = (node->player->y - 1) * SCALE;
	i = y + SCALE;
	j = x + SCALE;
	while (y < i)
	{
		while (x < j)
		{
			my_mlx_pixel_put(image, x, y, 0x00F0F0);
			x++;
		}
		x -= SCALE;
		y++;
	}
}
