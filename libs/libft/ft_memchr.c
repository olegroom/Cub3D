/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:44:44 by rosfryd           #+#    #+#             */
/*   Updated: 2020/11/04 17:47:05 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *arr, int c, size_t n)
{
	char	*tmp_arr;
	char	s;
	size_t	i;

	s = (char)c;
	tmp_arr = (char *)arr;
	i = 0;
	while (n--)
	{
		if (tmp_arr[i] == c)
			return (tmp_arr + i);
		i++;
	}
	return (NULL);
}
