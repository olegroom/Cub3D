/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:50:34 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/20 19:50:06 by rosfryd          ###   ########.fr       */
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

void	my_mlx_pixel_put(t_all *node, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= node->res_x || y >= node->res_y)
		return ;
	dst = node->image->addr + (y * node->image->size_line + x * (node->image->bpp / 8));
	*(unsigned int*)dst = color;
}
