/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 20:44:34 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/20 22:22:34 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

// static int	check_flags(t_all *node)
// {
// 	if (node->h->r == 1 || node->h->f == 1 || node->h->c == 1 ||
// 	node->h->so == 1 || node->h->no == 1 || node->h->we == 1 || node->h->ea == 1
// 	|| node->h->spr == 1)
// 		return (1);
// 	else
// 		return (0);
// }

// static void	pars_map(t_all *node)
// {
// 	// printf("node->mapa->y = %d\nnode->lst_size = %d\n", node->mapa->y, node->lst_size);
// }

void		pars_data(t_all *node)
{
	int y;
	int x;

	node->h = malloc(sizeof(t_h));
	x = 0;
	y = 0;
	while (y < node->lst_size)
	{
		if (node->map[y][x] == 'R' && node->map[y][x + 1] == ' ' && node->h->r == 0)
			node->h->r = go_pars_r(node, y, 2);
		else if (node->map[y][x] == 'F' && node->map[y][x + 1] == ' ')
			node->h->f = go_pars_f(node, y, 2);
		else if (node->map[y][x] == 'C' && node->map[y][x + 1] == ' ')
			node->h->c = go_pars_c(node, y, 2);
		// else if (node->map[y][x] == 'S' && node->map[y][x + 1] == ' ')
		// 	go_pars_spr(node);
		// else if (node->map[y][x] == 'S' && node->map[y][x + 1] == 'O' && node->map[y][x + 2] == ' ')
		// 	go_pars_south(node);
		// else if (node->map[y][x] == 'N' && node->map[y][x + 1] == 'O' && node->map[y][x + 2] == ' ')
		// 	go_pars_north(node);
		// else if (node->map[y][x] == 'W' && node->map[y][x + 1] == 'E' && node->map[y][x + 2] == ' ')
		// 	go_pars_west(node);
		// else if (node->map[y][x] == 'E' && node->map[y][x + 1] == 'A' && node->map[y][x + 2] == ' ')
		// 	go_pars_east(node);
		// else
		// {
		// 	if (check_flags(node))
		// 		pars_map(node);
		// 	if (y == node->lst_size)
		// 		error_found("Not full identifiers");
		// }
		y++;
	}
}