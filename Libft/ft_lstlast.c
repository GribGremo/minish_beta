/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:48:49 by sylabbe           #+#    #+#             */
/*   Updated: 2024/02/10 20:49:25 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*beacon;

	if (lst == NULL)
		return (NULL);
	beacon = lst;
	while (beacon != NULL)
	{
		if (beacon->next == NULL)
			return (beacon);
		beacon = beacon->next;
	}
	return (beacon);
}
