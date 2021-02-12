/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:38:46 by rosfryd           #+#    #+#             */
/*   Updated: 2020/11/03 15:12:00 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	int				i;

	tmp1 = (unsigned char*)arr1;
	tmp2 = (unsigned char*)arr2;
	i = 0;
	while (i < (int)n)
	{
		if (tmp1[i] == tmp2[i])
			i++;
		else if (tmp1[i] > tmp2[i])
			return (tmp1[i] - tmp2[i]);
		else if (tmp1[i] < tmp2[i])
			return (tmp1[i] - tmp2[i]);
	}
	return (0);
}
