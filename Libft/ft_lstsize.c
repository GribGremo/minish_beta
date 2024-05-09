/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:20:38 by sylabbe           #+#    #+#             */
/*   Updated: 2024/02/10 20:48:49 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*beacon;

	i = 1;
	if (lst == NULL)
		return (0);
	beacon = lst;
	while (beacon->next != NULL)
	{
		beacon = beacon->next;
		i++;
	}
	return (i);
}
