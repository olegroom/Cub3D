/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 20:27:33 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/21 19:13:15 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
	{
		node->ea[i] = node->map[y][x];
		x++;
		i++;
	}
	node->ea[i] = '\0';
	return (1);
}

int			go_pars_west(t_all *node, int y, int x)
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
	node->we = malloc(sizeof(char) * count_let + 1);
	while (ft_isalnum(node->map[y][x]) || node->map[y][x] == '/'\
	|| node->map[y][x] == '.' || node->map[y][x] == '_')
	{
		node->we[i] = node->map[y][x];
		x++;
		i++;
	}
	node->we[i] = '\0';
	return (1);
}

int			go_pars_north(t_all *node, int y, int x)
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
	node->no = malloc(sizeof(char) * count_let + 1);
	while (ft_isalnum(node->map[y][x]) || node->map[y][x] == '/'\
	|| node->map[y][x] == '.' || node->map[y][x] == '_')
	{
		node->no[i] = node->map[y][x];
		x++;
		i++;
	}
	node->no[i] = '\0';
	return (1);
}

int			go_pars_south(t_all *node, int y, int x)
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
	node->so = malloc(sizeof(char) * count_let + 1);
	while (ft_isalnum(node->map[y][x]) || node->map[y][x] == '/'\
	|| node->map[y][x] == '.' || node->map[y][x] == '_')
	{
		node->so[i] = node->map[y][x];
		x++;
		i++;
	}
	node->so[i] = '\0';
	return (1);
}

int			go_pars_spr(t_all *node, int y, int x)
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
	node->spr = malloc(sizeof(char) * count_let + 1);
	while (ft_isalnum(node->map[y][x]) || node->map[y][x] == '/'\
	|| node->map[y][x] == '.' || node->map[y][x] == '_')
	{
		node->spr[i] = node->map[y][x];
		x++;
		i++;
	}
	return (1);
}

int			go_pars_c(t_all *node, int y, int x)
{
	int flag;

	flag = 0;
	node->ceiling = malloc(sizeof(t_color));
	while (node->map[y][x] != '\0')
	{
		while (node->map[y][x] == ' ' || node->map[y][x] == ',')
		{
			x++;
			if (node->map[y][x] == '\0' && flag == 3)
				return (1);
			else if (node->map[y][x] == '\0')
				return(error_found("not found ceiling data"));
		}
		if (flag == 3)
			return(error_found("More than 3 input data"));
		if (ft_isnum(node->map[y][x]))
		{
			if (flag == 0)
				node->ceiling->r = ft_atoi(&node->map[y][x]);
			else if (flag == 1)
				node->ceiling->g = ft_atoi(&node->map[y][x]);
			else if (flag == 2)
				node->ceiling->b = ft_atoi(&node->map[y][x]);	
			while (ft_isnum(node->map[y][x]))
				x++;
			flag++;
		}
		else if (ft_isnum(node->map[y][x]) == 0)
			return(error_found("Wrong ceiling color input"));
	}
	if (check_color_range(node, 1))
		return (error_found("Too big color value in ceiling [0 - 255]"));
	return (1);
}

int			go_pars_f(t_all *node, int y, int x)
{
	int flag;

	flag = 0;
	node->floor = malloc(sizeof(t_color));

	while (node->map[y][x] != '\0')
	{
		while (node->map[y][x] == ' ' || node->map[y][x] == ',')
		{
			x++;
			if (node->map[y][x] == '\0')
				return (1);
		}
		if (flag == 3)
			return(error_found("More than 3 input data"));
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
			return(error_found("Wrong floor color input"));
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
		{
			x++;
			if (node->map[y][x] == '\0')
				return (1);
		}
		if (flag == 2)
			return(error_found("More than 2 input data"));
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
			return(error_found("Wrong resolution input"));
	}
	return (1);
}