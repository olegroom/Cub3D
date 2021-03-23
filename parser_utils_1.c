/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:36:29 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/24 02:06:14 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			check_flags(t_all *node)
{
	if (node->h->r == 1 && node->h->f == 1 && node->h->c == 1 &&
	node->h->so == 1 && node->h->no == 1 && node->h->we == 1 && node->h->ea == 1
	&& node->h->spr == 1)
		return (1);
	else
		return (0);
}

void		init_flags(t_all *node, t_help *n)
{
	n->x = 0;
	n->y = 0;
	node->h->r = 0;
	node->h->f = 0;
	node->h->c = 0;
	node->h->so = 0;
	node->h->no = 0;
	node->h->we = 0;
	node->h->ea = 0;
	node->h->spr = 0;
}

int			check_zero(t_all *node, int y, int x)
{
	int j;
	int k;

	k = -2;
	j = -2;
	while (++k < 2)
	{
		j = -2;
		while (++j < 2)
		{
			if (node->map[y + k][x + j] == ' ')
				error_found("Space around \'0\'");
		}
	}
	return (1);
}

void		help_init(t_all *node, t_pars_h *he, int y)
{
	he->flag = 0;
	he->x = 0;
	if (!(node->mapa = malloc(sizeof(t_mapa))))
		error_found("Malloc error");
	node->mapa->x = y;
}

void		check_errors(t_all *node, t_pars_h *he, int y)
{
	if (node->map[y][he->x] == '0')
		check_zero(node, y, he->x);
	if (node->map[y][he->x] == 'N' || node->map[y][he->x] == 'S' || \
	node->map[y][he->x] == 'W' || node->map[y][he->x] == 'E')
		he->flag = 1;
	else if (node->map[y][he->x] != '0' && node->map[y][he->x] != '1' && \
	node->map[y][he->x] != '2' && node->map[y][he->x] != 'N' && \
	node->map[y][he->x] != 'S' && node->map[y][he->x] != 'W' && \
	node->map[y][he->x] != 'E' && node->map[y][he->x] != ' ')
		error_found("Non valid characters in map");
	he->x++;
}
