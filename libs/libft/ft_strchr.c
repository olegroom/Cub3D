/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:47:43 by rosfryd           #+#    #+#             */
/*   Updated: 2020/11/04 17:50:33 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *str, int ch)
{
	char	*tmp;
	int		i;

	tmp = (char *)str;
	i = 0;
	while (tmp[i] != ch)
	{
		if (tmp[i] == '\0')
			return (NULL);
		i++;
	}
	return (&tmp[i]);
}
