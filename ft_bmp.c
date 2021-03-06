/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 02:55:41 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/06 04:35:31 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_header(t_all *node, t_bmp *bmp)
{
	int i;

	i = -1;
	while (++i < 14)
		bmp->header[i] = 0;
	bmp->header[0] = 'B';
	bmp->header[1] = 'M';
	bmp->header[10] = 54;
	i = -1;
	while (++i < 40)
		bmp->info[i] = 0;
	bmp->info[0] = 40;
	bmp->info[12] = 1;
	bmp->info[14] = 24;
	
}

void		ft_bmp(t_all *node)
{
	t_bmp	bmp;
	int		img_size;

	img_size = RES_X * RES_Y * 3;
	bmp.size = img_size + 54;
	bmp.img = malloc(sizeof(char) * img_size);
	ft_memset(bmp.img, 0, img_size);
	bmp.fd = open("img.bmp", O_CREAT | O_WRONLY, S_IRWXU);
	ft_header(node, &bmp);
}