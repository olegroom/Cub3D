/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 22:57:34 by rosfryd           #+#    #+#             */
/*   Updated: 2020/11/12 06:19:55 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*src;
	char	*substr;

	i = 0;
	if (!s)
		return (NULL);
	src = (char *)s;
	substr = malloc((sizeof(char) * (len + 1)));
	if (substr == NULL)
		return (NULL);
	if ((int)start > ft_strlen(src))
		len = 0;
	while (i < len)
	{
		substr[i] = src[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
