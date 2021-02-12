/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:37:33 by rosfryd           #+#    #+#             */
/*   Updated: 2020/11/04 17:47:25 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*tmp_d;
	char			*tmp_s;

	tmp_d = (char*)dest;
	tmp_s = (char*)src;
	if (!tmp_d && !tmp_s)
		return (dest);
	if (tmp_d < tmp_s)
		while (n--)
			*tmp_d++ = *tmp_s++;
	else
		while (n--)
			tmp_d[n] = tmp_s[n];
	return (dest);
}
