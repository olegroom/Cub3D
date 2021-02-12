/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:50:34 by rosfryd           #+#    #+#             */
/*   Updated: 2021/02/12 04:32:42 by rosfryd          ###   ########.fr       */
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

	node->help = malloc(sizeof(t_help));
	node->help->max_y = 0;

	node->lst_size = size;
	node->mlx = mlx_init();
	node->win = mlx_new_window(node->mlx, RES_X, RES_Y, "new window");
	
	// node->image = malloc(sizeof(t_image));
	// node->image->bpp = 0;
	// node->image->size_line = 0;
	// node->image->endian = 0;
	// node->image->addr = NULL;
	// node->image->img = NULL;
}

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	// img->img[y * RES_X + x] = color;
	char    *dst;

    dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
    *(unsigned int*)dst = color;
}
