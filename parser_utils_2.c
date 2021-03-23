/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:46:30 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/23 23:24:18 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		check_next_x(t_all *node, int curr_x, int next_x, int y)
{
	next_x -= 2;
	while (++next_x <= curr_x)
		if (node->map[y][next_x] == '0')
			error_found("Invalid map");
}

void		check_curr_x(t_all *node, int curr_x, int next_x, int y)
{
	curr_x -= 2;
	while (++curr_x <= next_x)
		if (node->map[y + 1][curr_x] == '0')
			error_found("Invalid map");
}

int			ft_isnum(int ch)
{
	if (ch <= '9' && ch >= '0')
		return (1);
	else
		return (0);
}

int			check_color_range(t_all *node, int flag)
{
	if (flag == 0)
	{
		if (node->floor->r > 255 || node->floor->r < 0 ||\
	node->floor->g > 255 || node->floor->g < 0 ||\
	node->floor->b > 255 || node->floor->b < 0)
			return (1);
	}
	else if (flag == 1)
	{
		if (node->ceiling->r > 255 || node->ceiling->r < 0 ||\
	node->ceiling->g > 255 || node->ceiling->g < 0 ||\
	node->ceiling->b > 255 || node->ceiling->b < 0)
			return (1);
	}
	return (0);
}

int			go_pars_east(t_all *node, int y, int x)
{
	int		count_let;
	int		i;

	i = 0;
	count_let = 0;
	while (node->map[y][x] == ' ')
		x++;
	if (node->map[y][x] == '.' && node->map[y][x + 1] == '/')
		x += 2;
	else
		return (error_found("You need to start path with \"./\""));
	while (ft_isalnum(node->map[y][x]) || node->map[y][x] == '/'\
	|| node->map[y][x] == '.' || node->map[y][x] == '_')
	{
		count_let++;
		x++;
	}
	x -= count_let;
	node->ea = malloc(sizeof(char) * count_let + 1);
	while (ft_isalnum(node->map[y][x]) || node->map[y][x] == '/'\
	|| node->map[y][x] == '.' || node->map[y][x] == '_')
		node->ea[i++] = node->map[y][x++];
	node->ea[i] = '\0';
	return (1);
}
