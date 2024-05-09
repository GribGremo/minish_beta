/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:47:45 by sylabbe           #+#    #+#             */
/*   Updated: 2024/03/05 14:27:57 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (del)(void *))
{
	t_list	*beacon;
	t_list	*temp;

	beacon = *lst;
	while (beacon->next != NULL)
	{
		temp = beacon->next;
		ft_lstdelone(beacon, (del));
		beacon = temp;
	}
	ft_lstdelone(beacon, (*del));
}
