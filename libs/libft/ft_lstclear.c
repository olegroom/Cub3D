/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 07:48:01 by rosfryd           #+#    #+#             */
/*   Updated: 2020/11/14 06:57:15 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;
	t_list *sec_tmp;

	tmp = *lst;
	while (tmp != NULL)
	{
		sec_tmp = tmp;
		tmp = tmp->next;
		del(sec_tmp->content);
		free(sec_tmp);
	}
	*lst = NULL;
}
