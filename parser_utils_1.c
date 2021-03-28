/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:36:29 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/28 17:10:55 by rosfryd          ###   ########.fr       */
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
			if (node->map[y + k][x + j] == ' ')
				error_found("Space around symbol, where it shouldn't be");
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

void		check_errors(t_all *node, t_pars_h *he, int y, int l)
{
	if (node->lst_size - 1 == y && (node->map[node->lst_size - 1][he->x] != '1'\
	&& node->map[node->lst_size - 1][he->x] != ' '))
		error_found("Invalid map in last row of map");
	if (l == y && (node->map[l][he->x] != '1' && node->map[l][he->x] != ' '))
		error_found("Invalid map in first row of map");
	if (node->map[y][0] != '1' && node->map[y][0] != ' ')
		error_found("Invalid first symbol in a row");
	if (node->map[y][ft_strlen(node->map[y]) - 1] != '1' && node->map[y]\
	[ft_strlen(node->map[y]) - 1] != ' ')
		error_found("Invalid last symbol in a row");
	if (node->map[y][he->x] == '0')
		check_zero(node, y, he->x);
	if (ft_strchr(PERS, node->map[y][he->x]))
	{
		check_zero(node, y, he->x);
		he->flag = 1;
	}
	if (node->map[y][he->x] == '2')
		check_zero(node, y, he->x);
	else if (ft_strchr(VALID, node->map[y][he->x]) == NULL)
		error_found("Non valid characters in map");
	he->x++;
}
