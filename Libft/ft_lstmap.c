/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:32:53 by sylabbe           #+#    #+#             */
/*   Updated: 2024/02/10 20:35:42 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*beacon;

	new_list = ft_lstnew((*f)(lst->content));
	beacon = lst->next;
	while (lst->next != NULL)
	{
		new_list->next = ft_lstnew((*f)(lst->content));
		if (new_list == NULL)
			(*del)(new_list);
	}
}
