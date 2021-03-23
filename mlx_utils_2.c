/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:16:15 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/23 23:28:48 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		endx(t_all *node)
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
