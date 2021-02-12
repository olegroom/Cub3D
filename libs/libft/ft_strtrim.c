/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 04:07:33 by rosfryd           #+#    #+#             */
/*   Updated: 2020/11/16 13:06:20 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	int		size;
	char	*newstring;

	if ((!s1 && !set) || !s1)
		return (NULL);
	else if (!(ft_strncmp(s1, "", 1)))
		return ("");
	while ((char *)s1 && ft_strchr(set, *s1))
	{
		if (*s1 == '\0')
			return (ft_strdup(""));
		s1++;
	}
	size = ft_strlen((char *)s1);
	while ((char *)s1 && ft_strchr(set, s1[size]))
		size--;
	newstring = ft_substr(s1, 0, size + 1);
	return (newstring);
}
