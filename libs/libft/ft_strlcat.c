/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:08:43 by rosfryd           #+#    #+#             */
/*   Updated: 2020/11/04 17:48:53 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;

	d_len = ft_strlen((char *)dst);
	s_len = ft_strlen((char *)src);
	if (size == 0 || d_len >= size)
		return (s_len + size);
	if (s_len + 1 <= size - d_len - 1)
		ft_strlcpy(&dst[d_len], src, s_len + 1);
	else
		ft_strlcpy(&dst[d_len], src, size);
	dst[size - 1] = '\0';
	return (s_len + d_len);
}
