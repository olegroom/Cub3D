/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 21:51:02 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/24 03:31:12 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	node_init(t_all *node)
{
	node->step = (M_PI_2) / node->res_x;
	if (!(node->player = malloc(sizeof(t_player))))
		error_found("Malloc error");
	if (!(node->help = malloc(sizeof(t_help))))
		error_found("Malloc error");
	if (!(node->help2 = malloc(sizeof(t_help2))))
		error_found("Malloc error");
	node->mlx = mlx_init();
	node->win = mlx_new_window(node->mlx, \
	node->res_x, node->res_y, "Privet drug");
	if (!(node->image = malloc(sizeof(t_image))))
		error_found("Malloc error");
	if (!(node->column = malloc(sizeof(t_column))))
		error_found("Malloc error");
	node->column->height_wall = SCALE;
	node->column->dist_to_pp = (node->res_x / 2) / tan(M_PI_4);
	if (!(node->te = malloc(sizeof(t_texture) * 5)))
		error_found("Malloc error");
	find_num_sprites(node);
	if (!(node->sprite = malloc(sizeof(t_sprite) * node->num_sprts)))
		error_found("Malloc error");
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
	node->te[2].path = node->no;
	node->te[3].path = node->so;
	node->te[1].path = node->we;
	node->te[0].path = node->ea;
	node->te[4].path = node->spr;
	while (++i < 5)
	{
		if (!(node->te[i].img = mlx_xpm_file_to_image(node->mlx, \
		node->te[i].path, &(node->te[i].width), &(node->te[i].height))))
			error_found("Texture file wasn't opened or doesn't exist");
		if (!(node->te[i].addr = (int*)mlx_get_data_addr(node->te[i].img,\
		&node->te[i].bpp, &node->te[i].size_line, &node->te[i].endian)))
			error_found("Address wasn't allocated");
	}
}
