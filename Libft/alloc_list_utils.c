/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_list_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:03:10 by sylabbe           #+#    #+#             */
/*   Updated: 2024/05/04 10:51:12 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// free/supprime toutes les allocs de la liste et affiche message d'erreur
int	rm_lst_alloc(t_alloc *lst, char *str)
{
	t_alloc	*node;

	node = lst;
	while (node != NULL)
	{
		node = lst->next;
		free(lst->alloc);
		lst->alloc = NULL;
		free(lst->ptr_alloc);
		lst->ptr_alloc = NULL;
		free(lst);
		lst = node;
	}
	if (str != NULL)
		ft_putendl_fd(str, 2);
	return (0);
}

t_alloc	*ft_lstnew_a(void *alloc, void **ptr_alloc)
{
	t_alloc	*node;

	node = malloc(sizeof(t_alloc));
	if (node == NULL)
		return (NULL);
	if (alloc != NULL)
	{
		node->alloc = alloc;
		node->ptr_alloc = NULL;
	}
	else if (ptr_alloc != NULL)
	{
		node->alloc = NULL;
		node->ptr_alloc = ptr_alloc;
	}
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back_a(t_alloc *lst, t_alloc *node)
{
	t_alloc	*beacon;

	if (lst == NULL || node == NULL)
		return ;
	beacon = ft_lstlast_a(lst);
	beacon->next = node;
}

t_alloc	*ft_lstlast_a(t_alloc *lst)
{
	t_alloc	*beacon;

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

int	ft_lstsize_a(t_alloc *lst)
{
	int		i;
	t_alloc	*beacon;

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
