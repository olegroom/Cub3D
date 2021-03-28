/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 00:46:34 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/28 19:44:18 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

unsigned int	create_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int				ft_strcmp(char *s1, char *s2)
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

void			check_resol(t_all *node, t_help *help)
{
	if (node->res_x > help->x)
		node->res_x = help->x;
	if (node->res_y > help->y)
		node->res_y = help->y;
}

int				go_pars_f(t_all *node, int y, int x, int flag)
{
	if (node->h->f == 1)
		error_found("Dobule keys are forbidden");
	while (node->map[y][x] != '\0')
	{
		while (node->map[y][x] == ' ' || node->map[y][x] == ',')
			reduce(node, x++, y, flag);
		if (flag == 3)
			return (error_found("More than 3 input data"));
		if (ft_isnum(node->map[y][x]))
		{
			depend_on_color(flag, node, x, y);
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

int				go_pars_r(t_all *node, int y, int x)
{
	int flag;

	flag = 0;
	if (node->h->r == 1)
		error_found("Dobule keys are forbidden");
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
			depend_on_color1(flag, node, x, y);
			while (ft_isnum(node->map[y][x]))
				x++;
			flag++;
		}
		else if (ft_isnum(node->map[y][x]) == 0)
			return (error_found("Wrong resolution input"));
	}
	return (1);
}
