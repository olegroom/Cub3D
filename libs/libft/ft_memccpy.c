/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:22:24 by rosfryd           #+#    #+#             */
/*   Updated: 2020/11/04 17:48:15 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*tmp2;
	size_t			i;

	tmp = (unsigned char*)dest;
	tmp2 = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		tmp[i] = tmp2[i];
		if (tmp[i] == (unsigned char)c)
			return (&tmp[i + 1]);
		i++;
	}
	return (NULL);
}
