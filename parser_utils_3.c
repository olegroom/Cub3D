/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 23:25:22 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/23 23:25:40 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		reduce(t_all *node, int x, int y, int flag)
{
	x++;
	if (node->map[y][x] == '\0' && flag == 3)
		return ;
	else if (node->map[y][x] == '\0')
		error_found("not found data");
}
