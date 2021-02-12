/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:06:24 by rosfryd           #+#    #+#             */
/*   Updated: 2020/11/05 03:29:14 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strrchr(const char *str, int ch)
{
	unsigned int	i;

	i = ft_strlen((char *)str);
	if ((char)ch == '\0')
		return ((char *)str + i);
	while (i--)
	{
		if ((char)str[i] == (char)ch)
			return ((char *)&str[i]);
	}
	return (NULL);
}
