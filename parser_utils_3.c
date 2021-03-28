/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 23:25:22 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/28 19:27:31 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			reduce(t_all *node, int x, int y, int flag)
{
	x++;
	if (node->map[y][x] == '\0' && flag == 3)
		return ;
	else if (node->map[y][x] == '\0')
		error_found("not found data");
}

int				check_png(char *str)
{
	if (ft_strcmp(&str[ft_strlen(str) - 4], ".xpm") == 0)
		error_found("Wrong texture file. Need .xpm");
	return (1);
}

int				ftlen(long int num)
{
	int i;

	i = 0;
	while (num > 9)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int				my_ft_atoi(const char *str)
{
	int				i;
	long long int	num;
	int				sign;

	sign = 1;
	num = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] <= '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
		if (num > 50000)
			return (50000);
	}
	if (ftlen(num) > 10 || num > 2147483648)
		return (-1);
	return (sign * num);
}

void			pars_init(t_count *count)
{
	count->i = 0;
	count->count_let = 0;
}
