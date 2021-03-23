/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:16:15 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/24 00:55:18 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		endx(void)
{
	exit(0);
	return (0);
}

void	rot_protection(t_all *node)
{
	if (node->player->dir >= 2 * M_PI)
		node->player->dir -= 2 * M_PI;
	else if (node->player->dir <= -2 * M_PI)
		node->player->dir += 2 * M_PI;
}
