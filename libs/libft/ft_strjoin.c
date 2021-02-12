/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:08:38 by rosfryd           #+#    #+#             */
/*   Updated: 2021/02/06 14:20:49 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	if (!(dest = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 2)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\n')
	{
		dest[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2[j] != '\n')
	{
		dest[i] = s2[j];
		j++;
		i++;
	}
	free(s2);
	// dest[i] = '\n';
	dest[++i] = '\0';
	return (dest);
}
