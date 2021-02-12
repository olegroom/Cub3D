/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:43:38 by rosfryd           #+#    #+#             */
/*   Updated: 2020/11/03 16:02:56 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = malloc(ft_strlen((char*)str) + 1);
	if (tmp)
	{
		while (i < ft_strlen((char*)str))
		{
			tmp[i] = str[i];
			i++;
		}
		tmp[i] = '\0';
		return (tmp);
	}
	else
		return (NULL);
}
