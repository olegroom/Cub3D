/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:50:34 by rosfryd           #+#    #+#             */
/*   Updated: 2021/02/24 22:48:49 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s != '\0')
		write(1, s++, 1);
}

void	ft_putendl(char *s)
{
	if (!s)
		return ;
	while (*s != '\0')
		write(1, s++, 1);
	write(1, "\n", 1);
}

void	revert_x_y(t_all *node)
{
	int		temp;

	temp = node->mapa->x;
	node->mapa->x = node->mapa->y;
	node->mapa->y = temp;
}

void	node_init(t_all *node, int size)
{
	node->mapa = malloc(sizeof(t_mapa));
	node->player = malloc(sizeof(t_player));
	node->help = malloc(sizeof(t_help));
	node->help2 = malloc(sizeof(t_help2));
	node->help2->x = 0.125;
	node->lst_size = size;
	node->mlx = mlx_init();
	node->win = mlx_new_window(node->mlx, RES_X, RES_Y, "new window");
	node->image = malloc(sizeof(t_image));
	node->column = malloc(sizeof(t_column));
	node->column->height_wall = SCALE;
	node->column->dist_to_pp = (RES_X/2)/tan(M_PI_4);
	node->texture = malloc(sizeof(t_texture));
	node->texture->img = mlx_xpm_file_to_image(node->mlx, "./wood.xpm", &node->texture->width, &node->texture->height);
	node->texture->addr = (int*)mlx_get_data_addr(node->texture->img, &node->texture->bpp, &node->texture->size_line, &node->texture->endian);
	ft_init_1(node);
}

void	ft_init_1(t_all *node)
{
	node->ceiling = malloc(sizeof(t_color));
	node->ceiling->r = 230;
	node->ceiling->b = 255;
	node->ceiling->g = 230;
	node->floor = malloc(sizeof(t_color));
	node->floor->r = 0;
	node->floor->b = 0;
	node->floor->g = 200;
}

void	plr_init(t_all *node, t_player *plr, t_help *help)
{
	*plr = *node->player;
	plr->l = plr->x * SCALE;
	plr->f = plr->y * SCALE;
	plr->start = node->player->dir - (M_PI_4 - node->help2->x);
	plr->end = node->player->dir + (M_PI_4 - node->help2->x);
	node->mapa->x = 0;
	help->x = 0;
	help->y = 0;
	node->help2->i = -1;
}

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= RES_X || y < 0 || y >= RES_Y)
		return ;
	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}
