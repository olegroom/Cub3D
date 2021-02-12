/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 08:39:58 by rosfryd           #+#    #+#             */
/*   Updated: 2020/11/14 17:31:02 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *current_new;
	t_list *cur_old;
	t_list *first_new;
	t_list *first_old;

	if (lst == NULL)
		return (NULL);
	first_old = lst;
	cur_old = first_old->next;
	first_new = ft_lstnew(f(first_old->content));
	current_new = first_new;
	while (cur_old != NULL)
	{
		current_new->next = ft_lstnew(f(cur_old->content));
		if (current_new->next == NULL)
			ft_lstclear(&lst, del);
		cur_old = cur_old->next;
		current_new = current_new->next;
	}
	return (first_new);
}
