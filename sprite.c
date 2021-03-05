/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 21:55:16 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/05 23:55:14 by rosfryd          ###   ########.fr       */
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

void		ft_sort(t_all *node, int i)
{
	t_sprite temp;
	while (++i < node->num_sprts - 1)
		if (node->sprite[i].hyp < node->sprite[i+1].hyp)
		{
			temp = node->sprite[i];
			node->sprite[i] = node->sprite[i+1];
			node->sprite[i+1] = temp;
			i = -1;
		}
}

double		get_delta(double start, double spr_angle)
{
	double delta_angle;

	delta_angle = start - spr_angle;
	if (delta_angle <= -M_PI)
		delta_angle += 2 * M_PI;
	else if (delta_angle >= M_PI)
		delta_angle -= 2 * M_PI;
	return (delta_angle);
}

void		get_params(t_all *node, t_help3 help3)
{
	int		i;
	double	start;

	start = node->player->dir + M_PI/4;
	i = -1;
	while (++i < node->num_sprts)
	{
		node->sprite[i].hyp = hypot(help3.plrx - (node->sprite[i].x * SCALE),\
		 help3.plry - (node->sprite[i].y * SCALE));
		// node->sprite[i].screen_size = RES_Y/node->sprite[i].hyp;
		node->sprite[i].screen_size = SCALE/node->sprite[i].hyp * node->column->dist_to_pp;
		node->sprite[i].v_offset = RES_Y/2 - node->sprite[i].screen_size/2;
		node->sprite[i].angle = atan2(node->player->y - node->sprite[i].y, node->sprite[i].x - node->player->x);
		node->sprite[i].del_angle = get_delta(start, node->sprite[i].angle);
		node->sprite[i].v_offset = (RES_Y/2 - node->sprite[i].screen_size/2);
		node->sprite[i].h_offset = (node->sprite[i].del_angle/(M_PI_2/RES_X) - node->sprite[i].screen_size/2);
	}

}

void		get_sprite_data(t_all *node, t_help3 help3)
{
	find_spr_pos(node, -1, 0);
	get_params(node, help3);
	ft_sort(node, -1);
	// while (++i < node->num_sprts)
	// {
	// 	printf("sprite[%d]\nhyp = %f\nx = %f\ny = %f\n", i, node->sprite[i].hyp\
	// 	, node->sprite[i].x, node->sprite[i].y);
	// 	printf("scr_size = %f\n", node->sprite[i].screen_size);
	// 	printf("sprite angle = %f\n", node->sprite[i].angle);
	// 	printf("plr_dir = %f\n", node->player->dir);
	// }
}

int			get_sprite_color(t_all *node, int y, int i)
{
	int color;
	int texture_x;
	int texture_y;
	
	if (node->sprite[i].screen_size > 1)
	{
		texture_y = y * (node->texture[4].height - 1) / (node->sprite[i].screen_size - 1);
		texture_x = (node->mapa->l - node->sprite[i].h_offset) *
		(node->texture[4].width - 1) / (node->sprite[i].screen_size - 1);
		color = *(node->texture[4].addr + (int)((int)(texture_y) *\
		node->texture[4].size_line / sizeof(int) +\
		texture_x * (node->texture[4].bpp / 8) / sizeof(int)));
	}
	return (color);
}


void		draw_sprite(t_all *node)
{
	int				y;
	int				i;
	unsigned int	color;

	i = 0;
	while (i < node->num_sprts)
	{
		if (node->sprite[i].screen_size > RES_Y)
			node->sprite[i].screen_size = 0;
		if (node->mapa->l >= node->sprite[i].h_offset && \
		node->mapa->l <= (node->sprite[i].h_offset + node->sprite[i].screen_size) && \
		node->sprite[i].hyp < node->player->i)
		{
			y = 0;
			while (y < node->sprite[i].screen_size)
			{
				color = get_sprite_color(node, y, i);
				if (color != create_trgb(0, 152, 0, 136))
				{
					// printf("mapa->l = %d\n", node->mapa->l);
					// printf("v_draw = %d\ny = %d\n", (int)(node->sprite[i].v_offset + y), y);
					my_mlx_pixel_put(node->image, node->mapa->l, (int)(node->sprite[i].v_offset + y), color);
					// printf("i = %d\n", i);
					// printf("Screen size sprite[%d] = %f\n", i, node->sprite[i].screen_size);
		
				}
				y++;
			}
		}
		i++;
	}
}
