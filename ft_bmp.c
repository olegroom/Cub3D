/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 02:55:41 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/06 05:50:24 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		set_header(char *header, int num, int i, int bit)
{
	while (++i < 4 && bit <= 32)
	{
		header[i] = (num >> bit);
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
		bmp->meta[i] = 0;
	bmp->meta[0] = 40;
	bmp->meta[12] = 1;
	bmp->meta[14] = 24;
	i = -1;
	while (++i < 3)
		bmp->padding[i] = 0;
	set_header(&bmp->header[2], bmp->size, -1, 0);
	set_header(&bmp->meta[4], RES_X, -1, 0);
	set_header(&bmp->meta[8], RES_Y, -1, 0);
	write(bmp->fd, bmp->header, 14);	
	write(bmp->fd, bmp->meta, 40);	
}

void		imgbmp(t_all *node, t_bmp *bmp)
{
	int i;
	int j;
	int y;

	j = -1;
	while (++j < RES_Y)
	{
		i = -1;
		while (++i < RES_X)
		{
			y = RES_Y - 1 - j;
			bmp->color = *(int*)(node->image->addr + (RES_X * y + i) * 4);
			write(bmp->fd, &bmp->color, 3);
		}
		i = -1;
		while (++i < (4 - (RES_X * 3) % 4) % 4)
			write(bmp->fd, &bmp->padding, 1);
	}
}

void		ft_bmp(t_all *node)
{
	t_bmp	bmp;
	int		size_image;

	size_image = RES_X * RES_Y * 3;
	bmp.size = size_image + 54;
	bmp.img = malloc(sizeof(char) * size_image);
	ft_memset(bmp.img, 0, size_image);
	bmp.fd = open("img.bmp", O_CREAT | O_WRONLY, S_IRWXU);
	ft_header(node, &bmp);
	imgbmp(node, &bmp);
	free(bmp.img);
	close(bmp.fd);
}