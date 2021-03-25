/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:36:29 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/25 04:35:06 by rosfryd          ###   ########.fr       */
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

	if (x == 0)
		error_found("0 is first symbol in row");
	if (node->map[y][x + 1] == '\0')
		error_found("0 is last symbol in row");
	k = -2;
	j = -2;
	while (++k < 2)
	{
		j = -2;
		while (++j < 2)
			if (node->map[y + k][x + j] == ' ')
				error_found("Space around \'0\'");
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
	if (y > 2000)
		error_found("Too big map in y. Need to be less than 2000 lines");
	if (he->x > 2000)
		error_found("Too big map in x. Need to be less than 2000 columns");
	if (node->lst_size - 1 == y && node->map[node->lst_size - 1][he->x] == '0')
		error_found("Invalid map in last row of map");
	if (l == y && node->map[l][he->x] == '0')
		error_found("Invalid map in first row of map");
	if (node->map[y][he->x] == '0')
		check_zero(node, y, he->x);
	if (node->map[y][he->x] == 'N' || node->map[y][he->x] == 'S' || \
	node->map[y][he->x] == 'W' || node->map[y][he->x] == 'E')
		he->flag = 1;
	else if (ft_strchr(VALID, node->map[y][he->x]) == NULL)
		error_found("Non valid characters in map");
	he->x++;
}
