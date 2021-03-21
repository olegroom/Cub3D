/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 20:44:34 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/21 04:23:20 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	check_flags(t_all *node)
{
	if (node->h->r == 1 && node->h->f == 1 && node->h->c == 1 &&
	node->h->so == 1 && node->h->no == 1 && node->h->we == 1 && node->h->ea == 1
	&& node->h->spr == 1)
		return (1);
	else
		return (0);
}

static void	init_flags(t_all *node)
{
	node->h->r = 0;
	node->h->f = 0;
	node->h->c = 0;
	node->h->so = 0;
	node->h->no = 0;
	node->h->we = 0;
	node->h->ea = 0;
	node->h->spr = 0;
}

static int	check_zero(t_all *node, int y, int x)
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

static int	go_pars_map(t_all *node, int y)
{
	int x;
	int curr_x;
	int next_x;
	int temp_x;
	
	x = 0;
	node->mapa = malloc(sizeof(t_mapa));
	node->mapa->x = y;
	while (y < node->lst_size)
	{
		x = 0;
		next_x = 0;
		while (node->map[y][x] != '\0')
		{
			if (node->map[y][x] == '0')
				check_zero(node, y, x);
			x++;
		}
		curr_x = x;
		if (y + 1 != node->lst_size)
			while (node->map[y + 1][next_x] != '\0')
				next_x++;
		while (--curr_x <= next_x)
		{
			if (node->map[y + 1][curr_x] == '0')
				error_found("Invalid map");
			curr_x += 2;
		} 
		y++;
	}
	return (1);
}

static int	pars_map(t_all *node, int y)
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

void		pars_data(t_all *node)
{
	int y;
	int x;

	node->h = malloc(sizeof(t_h));
	x = 0;
	y = 0;
	init_flags(node);
	while (y < node->lst_size)
	{
		if (node->map[y][x] == 'R' && node->map[y][x + 1] == ' ' && node->h->r == 0)
			node->h->r = go_pars_r(node, y, 2);
		else if (node->map[y][x] == 'F' && node->map[y][x + 1] == ' ')
			node->h->f = go_pars_f(node, y, 2);
		else if (node->map[y][x] == 'C' && node->map[y][x + 1] == ' ')
			node->h->c = go_pars_c(node, y, 2);
		else if (node->map[y][x] == 'S' && node->map[y][x + 1] == ' ')
			node->h->spr = go_pars_spr(node, y, 2);
		else if (node->map[y][x] == 'S' && node->map[y][x + 1] == 'O' && node->map[y][x + 2] == ' ')
			node->h->so = go_pars_south(node, y, 3);
		else if (node->map[y][x] == 'N' && node->map[y][x + 1] == 'O' && node->map[y][x + 2] == ' ')
			node->h->no = go_pars_north(node, y, 3);
		else if (node->map[y][x] == 'W' && node->map[y][x + 1] == 'E' && node->map[y][x + 2] == ' ')
			node->h->we = go_pars_west(node, y, 3);
		else if (node->map[y][x] == 'E' && node->map[y][x + 1] == 'A' && node->map[y][x + 2] == ' ')
			node->h->ea = go_pars_east(node, y, 3);
		else
		{
			if (check_flags(node))
			{
				pars_map(node, y);
				return ;
			}
			else if (y + 1 == node->lst_size)
				error_found("Not full identifiers");
		}
		y++;
	}
}