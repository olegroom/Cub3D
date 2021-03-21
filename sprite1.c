/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:43:49 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/21 19:49:49 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		draw_sprite(t_all *node, int i)
{
	int				y;
	unsigned int	color;

	while (i < node->num_sprts)
	{
		if (node->sprite[i].screen_size > node->res_y)
			node->sprite[i].screen_size = 0;
		if (node->mapa->l >= node->sprite[i].h_offset && \
		node->mapa->l <= (node->sprite[i].h_offset + \
		node->sprite[i].screen_size) && \
		node->sprite[i].hyp < node->player->i)
		{
			y = 0;
			while (y < node->sprite[i].screen_size)
			{
				color = get_sprite_color(node, y, i);
				if (color != create_trgb(152, 0, 136))
					my_mlx_pixel_put(node, node->mapa->l, \
					(int)(node->sprite[i].v_offset + y), color);
				y++;
			}
		}
		i++;
	}
}

void		get_sprite_data(t_all *node, t_help3 help3)
{
	find_spr_pos(node, -1, 0);
	get_params(node, help3);
	ft_sort(node, -1);
}

int			get_sprite_color(t_all *node, int y, int i)
{
	int color;
	int texture_x;
	int texture_y;

	if (node->sprite[i].screen_size > 1)
	{
		texture_y = y * (node->texture[4].height - 1) \
		/ (node->sprite[i].screen_size - 1);
		texture_x = (node->mapa->l - node->sprite[i].h_offset) *
		(node->texture[4].width - 1) / (node->sprite[i].screen_size - 1);
		color = *(node->texture[4].addr + (int)((int)(texture_y) *\
		node->texture[4].size_line / sizeof(int) +\
		texture_x * (node->texture[4].bpp / 8) / sizeof(int)));
	}
	return (color);
}
