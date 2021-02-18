/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 21:59:54 by rosfryd           #+#    #+#             */
/*   Updated: 2021/02/18 04:02:41 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_fill(t_all *node)
{
	while (node->mapa->x < node->lst_size)
	{
		node->mapa->y = 0;
		while (node->map[node->mapa->x][node->mapa->y] != '\0')
		{
			if (ft_strchr(PERS, node->map[node->mapa->x][node->mapa->y]))
			{
				if (node->map[node->mapa->x][node->mapa->y] == 'S')
					node->player->dir = M_PI_2;
				else if (node->map[node->mapa->x][node->mapa->y] == 'W')
					node->player->dir = M_PI;
				else if (node->map[node->mapa->x][node->mapa->y] == 'N')
					node->player->dir = M_PI * 1.5;
				else if (node->map[node->mapa->x][node->mapa->y] == 'E')
					node->player->dir = 0;
				node->player->x = node->mapa->y + 1;
				node->player->y = node->mapa->x + 1;
			}
			
			node->mapa->y++;
			if (node->help->max_y < node->mapa->y)
				node->help->max_y = node->mapa->y;
		}
		node->mapa->x++;
	}
	revert_x_y(node);
	node->mapa->x_max = node->mapa->x;
	// printf("Player's position:\nx = %f\ny = %f\n", node->player->x, node->player->y);
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
}

int	main(int argc, char **argv)
{
	int fd;
	char *line = NULL;
	t_list *head = NULL;
	fd = open(argv[1], O_RDONLY);
	while(get_next_line(fd, &line))
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	close(fd);
	make_array_map(&head, ft_lstsize(head));
	return (0);
}