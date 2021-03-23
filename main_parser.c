/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 20:44:34 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/23 22:47:28 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			go_pars_map(t_all *node, int y)
{
	t_pars_h he;

	help_init(node, &he, y);
	while (y < node->lst_size)
	{
		he.x = 0;
		he.next_x = 0;
		while (node->map[y][he.x] != '\0')
			check_errors(node, &he, y);
		he.curr_x = he.x;
		if (y + 1 != node->lst_size)
			while (node->map[y + 1][he.next_x] != '\0')
				he.next_x++;
		if (he.curr_x < he.next_x)
			check_curr_x(node, he.curr_x, he.next_x, y);
		else if (he.next_x < he.curr_x)
			check_next_x(node, he.curr_x, he.next_x, y);
		y++;
	}
	if (he.flag == 0)
		error_found("Where is a player?");
	return (1);
}

int			pars_map(t_all *node, int y)
{
	int x;

	x = 0;
	while (node->map[y][x] != ' ' && node->map[y][x] != '1')
		y++;
	if (node->map[y][x] == ' ' || node->map[y][x] == '1')
	{
		go_pars_map(node, y);
		return (1);
	}
	return (1);
}

int			else_id(t_all *node, t_help n)
{
	if (check_flags(node))
	{
		pars_map(node, n.y);
		return (1);
	}
	else if (n.y + 1 == node->lst_size)
		error_found("Not full identifiers");
	return (0);
}

int			check_ident(t_all *node, t_help n)
{
	if (node->map[n.y][n.x] == 'R' && node->map[n.y][n.x + 1] == ' ')
		node->h->r = go_pars_r(node, n.y, 2);
	else if (node->map[n.y][n.x] == 'F' && node->map[n.y][n.x + 1] == ' ')
		node->h->f = go_pars_f(node, n.y, 2);
	else if (node->map[n.y][n.x] == 'C' && node->map[n.y][n.x + 1] == ' ')
		node->h->c = go_pars_c(node, n.y, 2);
	else if (node->map[n.y][n.x] == 'S' && node->map[n.y][n.x + 1] == ' ')
		node->h->spr = go_pars_spr(node, n.y, 2);
	else if (node->map[n.y][n.x] == 'S' && node->map[n.y][n.x + 1] == 'O' \
	&& node->map[n.y][n.x + 2] == ' ')
		node->h->so = go_pars_south(node, n.y, 3);
	else if (node->map[n.y][n.x] == 'N' && node->map[n.y][n.x + 1] == 'O' \
	&& node->map[n.y][n.x + 2] == ' ')
		node->h->no = go_pars_north(node, n.y, 3);
	else if (node->map[n.y][n.x] == 'W' && node->map[n.y][n.x + 1] == 'E' \
	&& node->map[n.y][n.x + 2] == ' ')
		node->h->we = go_pars_west(node, n.y, 3);
	else if (node->map[n.y][n.x] == 'E' && node->map[n.y][n.x + 1] == 'A' \
	&& node->map[n.y][n.x + 2] == ' ')
		node->h->ea = go_pars_east(node, n.y, 3);
	else if (else_id(node, n) == 1)
		return (1);
	return (0);
}

void		pars_data(t_all *node)
{
	t_help	n;
	int		i;

	node->h = malloc(sizeof(t_h));
	init_flags(node, &n);
	while (n.y < node->lst_size)
	{
		if (check_ident(node, n) == 1)
			return ;
		n.y++;
	}
}
