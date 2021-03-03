/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 21:55:16 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/03 23:54:57 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		find_num_sprites(t_all *node)
{
	int n;
	int m;

	n = 0;
	m = 0;
	while (n < node->lst_size)
	{
		m = 0;
		while (node->map[n][m] != '\0')
		{
			if (node->map[n][m] == '2')
				node->num_sprts++;
			m++;
		}
		n++;
	}
}

void		find_spr_pos(t_all *node, int n, int m)
{
	int i;

	i = 0;
	while (++n < node->lst_size)
	{
		m = 0;
		while (node->map[n][m++] != '\0')
			if (node->map[n][m] == '2')
			{
				node->sprite[i].x = m + 0.5;
				node->sprite[i].y = n + 0.5;
				i++;
			}
	}	
}

void		find_hypotenuz(t_all *node, t_help3 help3)
{
	int i;

	i = -1;
	while (++i < node->num_sprts)
		node->sprite[i].hyp = hypot(help3.plrx - (node->sprite[i].x * SCALE),\
		 help3.plry - (node->sprite[i].y * SCALE));
}

void		ft_sort(t_all *node, int i)
{
	double temp;
	double tempx;
	double tempy;

	while (++i < node->num_sprts)
		if (node->sprite[i].hyp < node->sprite[i+1].hyp)
		{
			temp = node->sprite[i].hyp;
			tempx = node->sprite[i].x;
			tempy = node->sprite[i].y;
			node->sprite[i].hyp = node->sprite[i+1].hyp;
			node->sprite[i].x = node->sprite[i+1].x;
			node->sprite[i].y = node->sprite[i+1].y;
			node->sprite[i+1].hyp = temp;
			node->sprite[i+1].x = tempx;
			node->sprite[i+1].y = tempy;
			i = -1;
		}
}

void		find_screen_size(t_all *node)
{
	int i;

	i = -1;
	while (++i < node->num_sprts)
		node->sprite[i].screen_size = RES_Y/node->sprite[i].hyp;
}

void		get_sprite_data(t_all *node, t_help3 help3)
{
	find_spr_pos(node, -1, 0);
	find_hypotenuz(node, help3);
	ft_sort(node, -1);
	find_screen_size(node);
	// int i = -1;
	// while (++i < node->num_sprts)
	// {
		// printf("sprite[%d]\nhyp = %f\nx = %f\ny = %f\n", i, node->sprite[i].hyp\
		// , node->sprite[i].x, node->sprite[i].y);
		// printf("%f\n", node->sprite[i].screen_size);
	// }
}