/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 02:55:41 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/06 05:28:27 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		set_header(char *header, int param, int i, int bit)
{
	while (++i < 4)
	{
		header[i] = (unsigned char)(param >> bit);
		bit += 8;
	}
}

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
	i = -1;
	while (++i < 3)
		bmp->pad[i] = 0;
	set_header(&bmp->header[2], bmp->size, -1, 0);
	set_header(&bmp->info[4], RES_X, -1, 0);
	set_header(&bmp->info[8], RES_Y, -1, 0);
	write(bmp->fd, bmp->header, 14);	
	write(bmp->fd, bmp->info, 40);	
}

void		imgbmp(t_all *node, t_bmp *bmp)
{
	int i;
	int j;
	int x;
	int y;

	j = -1;
	while (++j < RES_Y)
	{
		i = -1;
		while (++i < RES_X)
		{
			x = i;
			y = RES_Y - 1 - j;
			bmp->color = *(int*)(node->image->addr + (RES_X * y + x) * node->image->bpp / 8);
			write(bmp->fd, &bmp->color, 3);
		}
		i = -1;
		while (++i < (4 - (RES_X * 3) % 4) % 4)
			write(bmp->fd, &bmp->pad, 1);
	}
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
	imgbmp(node, &bmp);
	free(bmp.img);
	close(bmp.fd);
}