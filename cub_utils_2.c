/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 00:46:34 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/23 23:24:40 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		create_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
		if (s1[i] == '\0' && s2[i] == '\0')
			return (1);
	}
	return (0);
}

void	check_resol(t_all *node, t_help *help)
{
	if (node->res_x > help->x)
		node->res_x = help->x;
	if (node->res_y > help->y)
		node->res_y = help->y;
}

int			go_pars_f(t_all *node, int y, int x, int flag)
{
	while (node->map[y][x] != '\0')
	{
		while (node->map[y][x] == ' ' || node->map[y][x] == ',')
			reduce(node, x++, y, flag);
		if (flag == 3)
			return (error_found("More than 3 input data"));
		if (ft_isnum(node->map[y][x]))
		{
			if (flag == 0)
				node->floor->r = ft_atoi(&node->map[y][x]);
			else if (flag == 1)
				node->floor->g = ft_atoi(&node->map[y][x]);
			else if (flag == 2)
				node->floor->b = ft_atoi(&node->map[y][x]);
			while (ft_isnum(node->map[y][x]))
				x++;
			flag++;
		}
		else if (ft_isnum(node->map[y][x]) == 0)
			return (error_found("Wrong floor color input"));
	}
	if (check_color_range(node, 0))
		return (error_found("Too big color value in floor [0 - 255]"));
	return (1);
}

int			go_pars_r(t_all *node, int y, int x)
{
	int flag;

	flag = 0;
	while (node->map[y][x] != '\0')
	{
		while (node->map[y][x] == ' ' || node->map[y][x] == ',')
			x++;
		if (node->map[y][x] == '\0')
			return (error_found("Where resolution input man?"));
		if (flag == 2)
			return (error_found("More than 2 input data"));
		if (ft_isnum(node->map[y][x]))
		{
			if (flag == 0)
				node->res_x = ft_atoi(&node->map[y][x]);
			else if (flag == 1)
				node->res_y = ft_atoi(&node->map[y][x]);
			while (ft_isnum(node->map[y][x]))
				x++;
			flag++;
		}
		else if (ft_isnum(node->map[y][x]) == 0)
			return (error_found("Wrong resolution input"));
	}
	return (1);
}
