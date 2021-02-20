/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:19:31 by rosfryd           #+#    #+#             */
/*   Updated: 2021/02/20 19:24:13 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int 	main(void)
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, RES_X, RES_Y, "title");
	mlx_loop(mlx);
	
	return (0);
}