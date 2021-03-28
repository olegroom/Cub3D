/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 02:55:41 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/28 10:53:38 by rosfryd          ###   ########.fr       */
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
	set_header(&bmp->meta[4], node->res_x, -1, 0);
	set_header(&bmp->meta[8], node->res_y, -1, 0);
	write(bmp->fd, bmp->header, 14);
	write(bmp->fd, bmp->meta, 40);
}

void		imgbmp(t_all *node, t_bmp *bmp)
{
	int i;
	int j;
	int y;

	j = -1;
	while (++j < node->res_y)
	{
		i = -1;
		while (++i < node->res_x)
		{
			y = node->res_y - 1 - j;
			bmp->color = *(int*)(node->image->addr + (node->res_x * y + i) * 4);
			write(bmp->fd, &bmp->color, 3);
		}
		i = -1;
		while (++i < (4 - (node->res_x * 3) % 4) % 4)
			write(bmp->fd, &bmp->padding, 1);
	}
}

void		ft_bmp(t_all *node)
{
	t_bmp	bmp;
	int		size_image;

	size_image = node->res_x * node->res_y * 3;
	bmp.size = size_image + 54;
	if (!(bmp.img = malloc(sizeof(char) * size_image)))
		error_found("Malloc error");
	ft_memset(bmp.img, 0, size_image);
	bmp.fd = open("img.bmp", O_CREAT | O_WRONLY, S_IRWXU);
	ft_header(node, &bmp);
	imgbmp(node, &bmp);
	free(bmp.img);
	close(bmp.fd);
}

void		make_bmp(t_list **head, int size, int i)
{
	t_list	*temp;
	t_all	node;
	t_help	help;

	node.lst_size = size;
	temp = *head;
	node.map = calloc(size + 1, sizeof(char*));
	while (temp)
	{
		node.map[++i] = temp->content;
		temp = temp->next;
	}
	mlx_get_screen_size(node.mlx, &help.x, &help.y);
	pars_data(&node);
	check_resol(&node, &help);
	node_init(&node);
	ft_fill(&node);
	node.image->img = mlx_new_image(node.mlx, node.res_x, node.res_y);
	node.image->addr = mlx_get_data_addr(node.image->img, \
	&node.image->bpp, &node.image->size_line, &node.image->endian);
	draw_vector(&node);
	mlx_put_image_to_window(node.mlx, node.win, node.image->img, 0, 0);
	ft_bmp(&node);
	mlx_destroy_image(node.mlx, node.image->img);
}
