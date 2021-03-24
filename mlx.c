/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:52:46 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/24 03:50:44 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_map_2d(t_all *node)
{
	draw_image(node);
	mlx_hook(node->win, 2, 1L << 0, ft_key, node);
	mlx_hook(node->win, 17, 0, endx, node);
	mlx_loop(node->mlx);
}

int		draw_image(t_all *node)
{
	if (!(node->image->img = mlx_new_image(node->mlx, \
	node->res_x, node->res_y)))
		error_found("imag wasn't created");
	node->image->addr = mlx_get_data_addr(node->image->img, \
	&node->image->bpp, &node->image->size_line, &node->image->endian);
	draw_vector(node);
	mlx_put_image_to_window(node->mlx, node->win, node->image->img, 0, 0);
	mlx_destroy_image(node->mlx, node->image->img);
	return (0);
}

void	draw_vector(t_all *node)
{
	t_player	plr;
	t_help3		help3;

	node->mapa->l = node->res_x - 1;
	plr_init(node, &plr, &help3);
	rot_protection(node);
	get_sprite_data(node, help3);
	while (plr.start < plr.end)
	{
		node->player->i = 0;
		plr.y = plr.f;
		plr.x = plr.l;
		while (plr.x > 0 && plr.y > 0 && node->map[(int)plr.y / SCALE]\
		[(int)plr.x / SCALE] != '1')
			cast_ray(node, &plr, &help3);
		draw_column(node, plr, help3);
		draw_sprite(node, 0);
		node->mapa->l--;
		if (node->mapa->l == -1)
			break ;
		plr.start += node->step;
	}
}

void	draw_column(t_all *node, t_player plr, t_help3 help3)
{
	t_help	help;
	t_start	start;

	ft_draw_init(node, &help, &start, &plr);
	while (help.x < help.max_x)
		my_mlx_pixel_put(node, node->mapa->l, help.x++, \
		create_trgb(node->ceiling->r, node->ceiling->g, node->ceiling->b));
	while (node->column->k < node->column->l)
	{
		if ((int)help3.y == (int)plr.y / SCALE && help3.x < plr.x / SCALE)
			find_color(node, &plr, &start, 0);
		else if ((int)help3.y == (int)plr.y / SCALE && help3.x > plr.x / SCALE)
			find_color(node, &plr, &start, 1);
		else if (help3.y > plr.y / SCALE && (int)help3.x == (int)plr.x / SCALE)
			find_color(node, &plr, &start, 2);
		else if (help3.y < plr.y / SCALE && (int)help3.x == (int)plr.x / SCALE)
			find_color(node, &plr, &start, 3);
		else
			borders_draw(node, &start);
		my_mlx_pixel_put(node, node->mapa->l, node->column->k++, start.color);
		start.ind++;
	}
	while (help.y < node->res_y)
		my_mlx_pixel_put(node, node->mapa->l, help.y++, \
		create_trgb(node->floor->r, node->floor->g, node->floor->b));
}

int		ft_key(int key_code, t_all *node)
{
	if (key_code == 123)
		node->player->dir += 0.06;
	else if (key_code == 124)
		node->player->dir -= 0.06;
	else if (key_code == 13)
		check_next_step(node, 'w');
	else if (key_code == 1)
		check_next_step(node, 's');
	else if (key_code == 0)
		check_next_step(node, 'z');
	else if (key_code == 2)
		check_next_step(node, 'e');
	else if (key_code == 53)
		exit(0);
	draw_image(node);
	return (0);
}
