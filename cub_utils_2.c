/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 00:46:34 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/21 20:01:46 by rosfryd          ###   ########.fr       */
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
