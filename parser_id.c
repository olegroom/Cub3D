/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 20:27:33 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/28 19:50:16 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			go_pars_west(t_all *node, int y, int x)
{
	t_count count;

	pars_init(&count);
	if (node->h->we == 1)
		error_found("Dobule keys are forbidden");
	while (node->map[y][x] == ' ')
		x++;
	if (node->map[y][x] == '.' && node->map[y][x + 1] == '/')
		x += 2;
	else
		return (error_found("You need to start path with \"./\""));
	while (ft_isalnum(node->map[y][x]) || node->map[y][x] == '/'\
	|| node->map[y][x] == '.' || node->map[y][x] == '_')
	{
		count.count_let++;
		x++;
	}
	x -= count.count_let;
	if (!(node->we = malloc(sizeof(char) * count.count_let + 1)))
		return (error_found("Malloc error"));
	while (ft_isalnum(node->map[y][x]) || node->map[y][x] == '/'\
	|| node->map[y][x] == '.' || node->map[y][x] == '_')
		node->we[count.i++] = node->map[y][x++];
	node->we[count.i] = '\0';
	return (check_png(node->we));
}

int			go_pars_north(t_all *node, int y, int x)
{
	t_count count;

	pars_init(&count);
	if (node->h->no == 1)
		error_found("Dobule keys are forbidden");
	while (node->map[y][x] == ' ')
		x++;
	if (node->map[y][x] == '.' && node->map[y][x + 1] == '/')
		x += 2;
	else
		return (error_found("You need to start path with \"./\""));
	while (ft_isalnum(node->map[y][x]) || node->map[y][x] == '/'\
	|| node->map[y][x] == '.' || node->map[y][x] == '_')
	{
		count.count_let++;
		x++;
	}
	x -= count.count_let;
	node->no = malloc(sizeof(char) * count.count_let + 1);
	while (ft_isalnum(node->map[y][x]) || node->map[y][x] == '/'\
	|| node->map[y][x] == '.' || node->map[y][x] == '_')
		node->no[count.i++] = node->map[y][x++];
	node->no[count.i] = '\0';
	return (check_png(node->no));
}

int			go_pars_south(t_all *node, int y, int x)
{
	t_count count;

	pars_init(&count);
	if (node->h->so == 1)
		error_found("Dobule keys are forbidden");
	while (node->map[y][x] == ' ')
		x++;
	if (node->map[y][x] == '.' && node->map[y][x + 1] == '/')
		x += 2;
	else
		return (error_found("You need to start path with \"./\""));
	while (ft_isalnum(node->map[y][x]) || node->map[y][x] == '/'\
	|| node->map[y][x] == '.' || node->map[y][x] == '_')
	{
		count.count_let++;
		x++;
	}
	x -= count.count_let;
	node->so = malloc(sizeof(char) * count.count_let + 1);
	while (ft_isalnum(node->map[y][x]) || node->map[y][x] == '/'\
	|| node->map[y][x] == '.' || node->map[y][x] == '_')
		node->so[count.i++] = node->map[y][x++];
	node->so[count.i] = '\0';
	return (check_png(node->so));
}

int			go_pars_spr(t_all *node, int y, int x)
{
	t_count count;

	pars_init(&count);
	if (node->h->spr == 1)
		error_found("Dobule keys are forbidden");
	while (node->map[y][x] == ' ')
		x++;
	if (node->map[y][x] == '.' && node->map[y][x + 1] == '/')
		x += 2;
	else
		return (error_found("You need to start path with \"./\""));
	while (ft_isalnum(node->map[y][x]) || node->map[y][x] == '/'\
	|| node->map[y][x] == '.' || node->map[y][x] == '_')
	{
		count.count_let++;
		x++;
	}
	x -= count.count_let;
	if (!(node->spr = malloc(sizeof(char) * count.count_let + 1)))
		return (error_found("Malloc error"));
	while (ft_isalnum(node->map[y][x]) || node->map[y][x] == '/'\
	|| node->map[y][x] == '.' || node->map[y][x] == '_')
		node->spr[count.i++] = node->map[y][x++];
	return (check_png(node->spr));
}

int			go_pars_c(t_all *node, int y, int x, int flag)
{
	if (node->h->c == 1)
		error_found("Dobule keys are forbidden");
	while (node->map[y][x] != '\0')
	{
		while (node->map[y][x] == ' ' || node->map[y][x] == ',')
			reduce(node, x++, y, flag);
		if (flag == 3)
			return (error_found("More than 3 input data"));
		if (ft_isnum(node->map[y][x]))
		{
			depend_on_color_ceil(flag, node, x, y);
			while (ft_isnum(node->map[y][x]))
				x++;
			flag++;
		}
		else if (ft_isnum(node->map[y][x]) == 0)
			return (error_found("Wrong ceiling color input"));
	}
	if (check_color_range(node, 1))
		return (error_found("Too big color value in ceiling [0 - 255]"));
	return (1);
}
