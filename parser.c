/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 21:59:54 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/06 05:57:21 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_fill(t_all *node)
{
	int i;
	
	i = 0;
	while (node->mapa->x < node->lst_size)
	{
		node->mapa->y = 0;
		while (node->map[node->mapa->x][node->mapa->y] != '\0')
		{
			if (ft_strchr(PERS, node->map[node->mapa->x][node->mapa->y]))
			{
				if (node->map[node->mapa->x][node->mapa->y] == 'S')
					node->player->dir = M_PI * 1.5;
				else if (node->map[node->mapa->x][node->mapa->y] == 'W')
					node->player->dir = M_PI;
				else if (node->map[node->mapa->x][node->mapa->y] == 'N')
					node->player->dir = M_PI_2;
				else if (node->map[node->mapa->x][node->mapa->y] == 'E')
					node->player->dir = 0;
				node->player->x = node->mapa->y + 0.5;
				node->player->y = node->mapa->x + 0.5;
			}
			node->mapa->y++;
		}
		node->mapa->x++;
	}
	revert_x_y(node);
}

void	make_array_map(t_list **head, int size)
{
	t_all	node;
	t_list	*temp;
	int		i;

	temp = *head;
	node.map = calloc(size + 1, sizeof(char*));
	i = -1;
	while (temp)
	{
		node.map[++i] = temp->content;
		temp = temp->next;
	}
	node_init(&node, size);
	ft_fill(&node);
	draw_map_2d(&node, size);
	// node.image->img = mlx_new_image(node.mlx, RES_X, RES_Y);
	// node.image->addr = mlx_get_data_addr(node.image->img, &node.image->bpp, &node.image->size_line, &node.image->endian);
	// draw_vector(&node);
	// mlx_put_image_to_window(node.mlx, node.win, node.image->img, 0, 0);
	// ft_bmp(&node);
	// mlx_destroy_image(node.mlx, node.image->img);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_list	*head;
	t_all	node;

	head = NULL;
	line = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line))
			ft_lstadd_back(&head, ft_lstnew(line));
		ft_lstadd_back(&head, ft_lstnew(line));
		make_array_map(&head, ft_lstsize(head));
	}
}
