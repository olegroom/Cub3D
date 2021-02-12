/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:00:45 by rosfryd           #+#    #+#             */
/*   Updated: 2020/11/16 15:25:38 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char *)haystack);
	i = ft_strlen((char*)needle);
	while (ft_strncmp(&haystack[j], needle, i) != 0)
	{
		if (!haystack[j] || j >= (len - i))
			return (NULL);
		++j;
	}
	if (i > len)
		return (NULL);
	return ((char *)(&haystack[j]));
}
