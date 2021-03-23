/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:15:03 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/24 01:26:08 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_draw_init(t_all *node, t_help *help, t_start *start, t_player *plr)
{
	node->column->height_pp = node->column->height_wall / \
	(node->player->i * cos(plr->start - plr->dir)) * node->column->dist_to_pp;
	node->column->k = (node->res_y - node->column->height_pp) / 2;
	node->column->l = node->res_y - node->column->k;
	help->x = 0;
	help->y = node->column->l;
	help->max_x = (node->res_y - node->column->height_pp) / 2;
	start->ind = 0;
}

void	borders_draw(t_all *node, t_start *start)
{
	if (node->help2->i == 0)
		start->color = *(node->te[0].addr + (int)((int)(node->te[0].\
		step_y * start->ind) * node->te[0].width + node->te[0].step_x));
	else if (node->help2->i == 1)
		start->color = *(node->te[1].addr + (int)((int)(node->te[1].\
		step_y * start->ind) * node->te[1].width + node->te[1].step_x));
	else if (node->help2->i == 2)
		start->color = *(node->te[2].addr + (int)((int)(node->te[2].\
		step_y * start->ind) * node->te[2].width + node->te[2].step_x));
	else if (node->help2->i == 3)
		start->color = *(node->te[3].addr + (int)((int)(node->te[3].\
		step_y * start->ind) * node->te[3].width + node->te[3].step_x));
}

void	cast_ray(t_all *node, t_player *plr, t_help3 *help3)
{
	help3->x = plr->x / SCALE;
	help3->y = plr->y / SCALE;
	plr->x += cos(plr->start);
	plr->y -= sin(plr->start);
	node->player->i++;
}

void	find_color(t_all *node, t_player *plr, t_start *start, int st)
{
	if (st == 0 || st == 1)
		node->te[st].step_x = (int)plr->y % 64;
	else if (st == 2 || st == 3)
		node->te[st].step_x = (int)plr->x % 64;
	node->te[st].step_y = 64 / node->column->height_pp;
	start->color = *(node->te[st].addr + (int)((int)(node->te[st].\
	step_y * start->ind) * node->te[st].width + node->te[st].step_x));
	node->help2->i = st;
}

void	check_next_step(t_all *node, char direct)
{
	if (direct == 'w' && node->map[(int)(node->player->y - sin(node->player\
	->dir) / 8)][(int)(node->player->x + cos(node->player->dir) / 8)] != '1')
	{
		node->player->x += cos(node->player->dir) / 8;
		node->player->y -= sin(node->player->dir) / 8;
	}
	if (direct == 's' && node->map[(int)(node->player->y + sin(node->player\
	->dir) / 8)][(int)(node->player->x - cos(node->player->dir) / 8)] != '1')
	{
		node->player->x -= cos(node->player->dir) / 8;
		node->player->y += sin(node->player->dir) / 8;
	}
	if (direct == 'z' && node->map[(int)(node->player->y - cos(node->player->\
	dir) / 12)][(int)(node->player->x - sin(node->player->dir) / 12)] != '1')
	{
		node->player->x -= sin(node->player->dir) / 12;
		node->player->y -= cos(node->player->dir) / 12;
	}
	if (direct == 'e' && node->map[(int)(node->player->y + cos(node->player->\
	dir) / 12)][(int)(node->player->x + sin(node->player->dir) / 12)] != '1')
	{
		node->player->x += sin(node->player->dir) / 12;
		node->player->y += cos(node->player->dir) / 12;
	}
}
