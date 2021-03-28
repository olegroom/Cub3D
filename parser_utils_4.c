/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 19:39:00 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/28 19:49:56 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			depend_on_color(int flag, t_all *node, int x, int y)
{
	if (flag == 0)
		node->floor->r = ft_atoi(&node->map[y][x]);
	else if (flag == 1)
		node->floor->g = ft_atoi(&node->map[y][x]);
	else if (flag == 2)
		node->floor->b = ft_atoi(&node->map[y][x]);
}

void			depend_on_color_ceil(int flag, t_all *node, int x, int y)
{
	if (flag == 0)
		node->ceiling->r = ft_atoi(&node->map[y][x]);
	else if (flag == 1)
		node->ceiling->g = ft_atoi(&node->map[y][x]);
	else if (flag == 2)
		node->ceiling->b = ft_atoi(&node->map[y][x]);
}

void			depend_on_color1(int flag, t_all *node, int x, int y)
{
	if (flag == 0)
		node->res_x = my_ft_atoi(&node->map[y][x]);
	else if (flag == 1)
		node->res_y = my_ft_atoi(&node->map[y][x]);
}
