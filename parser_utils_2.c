/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:46:30 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/23 22:47:26 by rosfryd          ###   ########.fr       */
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