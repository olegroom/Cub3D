/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 21:51:02 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/21 19:14:01 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	node_init(t_all *node)
{
	node->step = M_PI_2 / node->res_x;
	node->player = malloc(sizeof(t_player));
	node->help = malloc(sizeof(t_help));
	node->help2 = malloc(sizeof(t_help2));
	node->mlx = mlx_init();
	node->win = mlx_new_window(node->mlx, \
	node->res_x, node->res_y, "Privet drug");
	node->image = malloc(sizeof(t_image));
	node->column = malloc(sizeof(t_column));
	node->column->height_wall = SCALE;
	node->column->dist_to_pp = (node->res_x / 2) / tan(M_PI_4);
	node->texture = malloc(sizeof(t_texture) * 5);
	find_num_sprites(node);
	node->sprite = malloc(sizeof(t_sprite) * node->num_sprts);
	init_textures(node);
}

void	plr_init(t_all *node, t_player *plr, t_help3 *help3)
{
	*plr = *node->player;
	plr->l = plr->x * SCALE;
	plr->f = plr->y * SCALE;
	plr->start = node->player->dir - M_PI_4;
	plr->end = node->player->dir + M_PI_4;
	node->mapa->x = 0;
	help3->plrx = plr->x * SCALE;
	help3->plry = plr->y * SCALE;
	node->help2->i = -1;
}

void	init_textures(t_all *node)
{
	int i;

	i = -1;
	node->texture[2].path = node->no;
	node->texture[3].path = node->so;
	node->texture[1].path = node->we;
	node->texture[0].path = node->ea;
	node->texture[4].path = node->spr;
	while (++i < 5)
	{
		node->texture[i].img = mlx_xpm_file_to_image(node->mlx, \
		node->texture[i].path, &(node->texture[i].width),\
		&(node->texture[i].height));
		node->texture[i].addr = (int*)mlx_get_data_addr(node->texture[i].img,\
		&node->texture[i].bpp, &node->texture[i].size_line,\
		&node->texture[i].endian);
	}
}
