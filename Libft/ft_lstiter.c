/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:34:45 by sylabbe           #+#    #+#             */
/*   Updated: 2024/03/05 14:28:25 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (f)(void *))
{
	t_list	*beacon;

	beacon = lst;
	while (beacon->next != NULL)
	{
		(*f)(beacon->content);
		beacon = beacon->next;
	}
	(*f)(beacon->content);
}
