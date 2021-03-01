/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 00:46:34 by rosfryd           #+#    #+#             */
/*   Updated: 2021/02/28 18:22:58 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_put_2d_map_draw(t_all *node)
{
	node->num_sprts = 0;
	node->mapa->x = 0;
	while (node->mapa->x < node->lst_size)
	{
		node->mapa->y = 0;
		while (node->map[node->mapa->x][node->mapa->y] != '\0')
		{
			if (node->map[node->mapa->x][node->mapa->y] == '1')
				draw_square(node, 0xFFFFFF);
			node->mapa->y++;
		}
		node->mapa->x++;
	}
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

int		create_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
