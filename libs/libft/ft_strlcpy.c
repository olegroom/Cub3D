/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:00:33 by rosfryd           #+#    #+#             */
/*   Updated: 2020/11/14 03:51:57 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	char	*tmp_src;

	if (dest == NULL)
		return (0);
	tmp_src = (char *)src;
	i = 0;
	while (tmp_src[i] && i + 1 < n)
	{
		dest[i] = tmp_src[i];
		i++;
	}
	if (n > 1)
		dest[i] = '\0';
	return (ft_strlen(tmp_src));
}
