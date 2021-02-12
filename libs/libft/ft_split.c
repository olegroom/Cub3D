/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 04:52:01 by rosfryd           #+#    #+#             */
/*   Updated: 2021/02/04 04:16:46 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_free(char **strfree, int count)
{
	int			i;

	i = 0;
	while (i < count)
	{
		free(strfree[i]);
		i++;
	}
	free(strfree);
	return (NULL);
}

static char		**ft_fill(char **final_str, char const *s, char c, size_t i)
{
	int			count;
	size_t		j;

	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		j = 0;
		while (s[i + j] != c && s[i + j] != '\0')
			j++;
		if (!(final_str[count] = malloc(sizeof(char) * (j + 1))))
			return (ft_free(final_str, count));
		j = 0;
		while (s[i + j] != c && s[i + j] != '\0')
		{
			final_str[count][j] = s[i + j];
			j++;
		}
		final_str[count++][j] = '\0';
		i += j;
	}
	return (final_str);
}

static char		**ft_allocation(char const *s, char c, int count)
{
	char		**str;
	size_t		i;

	i = 0;
	if (!(str = (char **)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	str[count] = NULL;
	return (ft_fill(str, s, c, i));
}

char			**ft_split(char const *s, char c)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (ft_allocation(s, c, count));
}
