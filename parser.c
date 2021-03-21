/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 21:59:54 by rosfryd           #+#    #+#             */
/*   Updated: 2021/03/21 18:32:19 by rosfryd          ###   ########.fr       */
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
				if (node->player->x != 0 && node->player->y != 0)
					error_found("More than 1 character");
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
	t_help	help;

	node.lst_size = size;
	temp = *head;
	node.map = calloc(size + 1, sizeof(char*));
	i = -1;
	while (temp)
	{
		node.map[++i] = temp->content;
		temp = temp->next;
	}
	mlx_get_screen_size(node.mlx, &help.x, &help.y);
	pars_data(&node);
	if (node.res_x > help.x)
		node.res_x = help.x;
	if (node.res_y > help.y)
		node.res_y = help.y;
	node_init(&node);
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
	if (argc == 1)
		return(error_found("Need to put .cub file as a second argument"));
	if (check_extension(argv) == 0)
		return (0);
	if ((fd = open(argv[1], O_RDONLY)) == 0)
		return (error_found("File wasn't opened"));
	while (get_next_line(fd, &line))
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	close(fd);
	if (argc == 2)
		make_array_map(&head, ft_lstsize(head));
	else if (argc == 3 && ft_strcmp(argv[2], "--save"))
		make_bmp(&head, ft_lstsize(head));
}

int		error_found(char *s1)
{
	int i;
	int j;

	i = ft_strlen(s1);
	j = 0;
	printf("Error\n");
	while (j < i)
		write(1, &s1[j++], 1);
	write(1, "\n", 1);
	exit(0);
	return (0);
}

int		check_extension(char **argv)
{
	int i;

	i = ft_strlen(argv[1]) - 1;
	if (argv[1][i] == 'b' && argv[1][i - 1] == 'u' && argv[1][i - 2] == 'c' && argv[1][i - 3] == '.')
		return (1);
	else
		return (error_found("Wrong extension. Need to be .cub"));
}
