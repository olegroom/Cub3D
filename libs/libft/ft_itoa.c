/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:21:45 by rosfryd           #+#    #+#             */
/*   Updated: 2020/11/16 16:35:13 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(int n)
{
	int		i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		l;
	char	*dest;

	l = len(n) - 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (!(dest = (char *)malloc(sizeof(char) * len(n) + 1)))
		return (NULL);
	if (n < 0)
	{
		n = n * -1;
		dest[0] = '-';
	}
	dest[l + 1] = '\0';
	while (n)
	{
		dest[l] = (n % 10) + 48;
		n = n / 10;
		l--;
	}
	return (dest);
}
