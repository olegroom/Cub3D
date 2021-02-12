/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:03:52 by rosfryd           #+#    #+#             */
/*   Updated: 2020/11/02 15:32:07 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	int				i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char*)dest;
	while (i < (int)n)
	{
		s[i] = (unsigned char)c;
		i++;
	}
	return (dest);
}
