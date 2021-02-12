/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 22:08:21 by rosfryd           #+#    #+#             */
/*   Updated: 2021/02/06 14:11:08 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				freesh(char *buffer)
{
	free(buffer);
	buffer = NULL;
}

static char			*ft_join(char *s1, char *s2)
{
	char			*sum;
	char			*ptr;
	int				i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	i = ft_strlen(s1);
	if (!(sum = (char *)malloc(sizeof(char) * (ft_strlen(s1)
	+ ft_strlen(s2) + 1))))
		return (NULL);
	ptr = sum;
	while (*s1)
		*sum++ = *s1++;
	freesh(s1 - i);
	while (*s2)
		*sum++ = *s2++;
	*sum = '\0';
	return (ptr);
}

static int			n_found(char **line, char **archive, char *ptrn)
{
	char *temp;

	temp = *archive;
	*ptrn = '\0';
	*line = ft_strdup(*archive);
	ptrn++;
	*archive = ft_strdup(ptrn);
	freesh(temp);
	return (1);
}

static int			n_not_found(char **line, char **archive, int i)
{
	char	*ptrn;

	if (i == -1)
		return (-1);
	if (*archive && (ptrn = ft_strchr(*archive, '\n')))
		return (n_found(line, archive, ptrn));
	if (*archive)
	{
		*line = *archive;
		*archive = NULL;
	}
	else
		*line = ft_strdup("");
	return (0);
}

int					get_next_line(int fd, char **line)
{
	char			*ptrn;
	static char		*archive;
	char			*buf;
	int				i;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || !(buf = (char*)malloc
(sizeof(char) * (BUFFER_SIZE + 1))) || read(fd, buf, 0) != 0)
		return (-1);
	while ((i = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[i] = '\0';
		archive = ft_join(archive, buf);
		if ((ptrn = ft_strchr(archive, '\n')))
		{
			free(buf);
			return (n_found(line, &archive, ptrn));
		}
	}
	free(buf);
	return (n_not_found(line, &archive, i));
}
