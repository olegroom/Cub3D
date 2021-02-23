/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:50:34 by rosfryd           #+#    #+#             */
/*   Updated: 2021/02/23 21:13:12 by rosfryd          ###   ########.fr       */
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
	node->mapa->x = 0;
	node->mapa->y = 0;
	node->mapa->x_max = 0;
	node->mapa->y_max = 0;

	node->player = malloc(sizeof(t_player));
	node->player->x = 0;
	node->player->y = 0;
	node->player->i = 0;

	node->help = malloc(sizeof(t_help));
	node->help->max_y = 0;
	node->help->x = 0;
	node->help->x = 0;
	node->help->x = 0;
	node->help->x = 0;

	node->help2 = malloc(sizeof(t_help2));
	node->help2->x = 0.125;

	node->lst_size = size;
	node->mlx = mlx_init();
	node->win = mlx_new_window(node->mlx, RES_X, RES_Y, "new window");
	
	node->image = malloc(sizeof(t_image));
	node->image->bpp = 0;
	node->image->size_line = 0;
	node->image->endian = 0;
	node->image->addr = NULL;
	node->image->img = NULL;

	node->column = malloc(sizeof(t_column));
	node->column->height_wall = SCALE;
	node->column->dist_to_pp = (RES_X/2)/tan(M_PI_4);
	node->column->height_pp = 0;
	node->column->dist_to_wall = 0;
	node->column->k = 0;
	node->column->l = 0;

	node->texture = malloc(sizeof(t_texture));
	node->texture->img = mlx_xpm_file_to_image(node->mlx, "./wood.xpm", &node->texture->width, &node->texture->height);
	node->texture->addr = (int*)mlx_get_data_addr(node->texture->img, &node->texture->bpp, &node->texture->size_line, &node->texture->endian);
	

	node->ceiling = malloc(sizeof(t_color));
	node->ceiling->r = 230;	
	node->ceiling->b = 255;
	node->ceiling->g = 230;

	node->floor = malloc(sizeof(t_color));
	node->floor->r = 0;	
	node->floor->b = 50;
	node->floor->g = 250;
}

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char    *dst;

	if (x < 0 || x >= RES_X || y < 0 || y >= RES_Y)
		return ;
    dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
    *(unsigned int*)dst = color;
}
