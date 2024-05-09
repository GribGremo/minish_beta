/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:46:27 by sylabbe           #+#    #+#             */
/*   Updated: 2024/03/05 14:26:59 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (del)(void *))
{
	if (lst == NULL || (del) == NULL)
		return ;
	(del)(lst->content);
	free(lst);
	lst = NULL;
}
