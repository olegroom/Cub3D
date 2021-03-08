/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 21:59:54 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/08 17:08:17 by rosfryd          ###   ########.fr       */
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
	t_list	*temp;
	t_all	node;
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

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_list	*head;

	head = NULL;
	line = NULL;
	if ((fd = open(argv[1], O_RDONLY)) != 0)
		return (error_found("File wasn't opened", 19));
	while (get_next_line(fd, &line))
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	close(fd);
	if (argc == 2)
		make_array_map(&head, ft_lstsize(head));
	else if (argc == 3 && ft_strcmp(argv[2], "--save"))
		make_bmp(&head, ft_lstsize(head));
}

int		error_found(char *s1, int i)
{
	int j;
	
	j = 0;
	while (j < i)
		write(1, &s1[j++], 1);
	write(1, "\n", 1);
	return (1);
}
