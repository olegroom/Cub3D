/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 21:51:02 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/04 23:23:59 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	node_init(t_all *node, int size)
{
	node->mapa = malloc(sizeof(t_mapa));
	node->player = malloc(sizeof(t_player));
	node->help = malloc(sizeof(t_help));
	node->help2 = malloc(sizeof(t_help2));
	node->help2->x = 0.125;
	node->lst_size = size;
	node->mlx = mlx_init();
	node->win = mlx_new_window(node->mlx, RES_X, RES_Y, "new window");
	node->image = malloc(sizeof(t_image));
	node->column = malloc(sizeof(t_column));
	node->column->height_wall = SCALE;
	node->column->dist_to_pp = (RES_X/2)/tan(M_PI_4);
	node->texture = malloc(sizeof(t_texture) * 4);
	find_num_sprites(node);
	printf("%d\n\n", node->num_sprts);
	node->sprite = malloc(sizeof(t_sprite) * node->num_sprts);
	ft_init_1(node);
	init_textures(node);
}

void	ft_init_1(t_all *node)
{
	node->ceiling = malloc(sizeof(t_color));
	node->ceiling->r = 230;
	node->ceiling->b = 255;
	node->ceiling->g = 230;
	node->floor = malloc(sizeof(t_color));
	node->floor->r = 0;
	node->floor->b = 0;
	node->floor->g = 200;
}

void	plr_init(t_all *node, t_player *plr, t_help3 *help3)
{
	*plr = *node->player;
	plr->l = plr->x * SCALE;
	plr->f = plr->y * SCALE;
	plr->start = node->player->dir - (M_PI_4 - node->help2->x);
	plr->end = node->player->dir + (M_PI_4 - node->help2->x);
	node->mapa->x = 0;
	help3->plrx = plr->x * SCALE;
	help3->plry = plr->y * SCALE;
	node->help2->i = -1;
}

void	init_textures(t_all *node)
{
	int i;

	i = -1;
	node->texture[0].path = "images/bluestone.xpm";
	node->texture[1].path = "images/brick.xpm";
	node->texture[2].path = "images/colorstone_1.xpm";
	node->texture[3].path = "images/wall_1.xpm";
	while (++i < 4)
	{
		node->texture[i].img = mlx_xpm_file_to_image(node->mlx, node->texture[i].path, &(node->texture[i].width),\
		 &(node->texture[i].height));
		node->texture[i].addr = (int*)mlx_get_data_addr(node->texture[i].img, &node->texture[i].bpp,\
		 &node->texture[i].size_line, &node->texture[i].endian);
	}
}
