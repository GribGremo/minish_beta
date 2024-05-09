/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:49:00 by sylabbe           #+#    #+#             */
/*   Updated: 2024/04/26 15:29:56 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// ajoute une alloc a la liste
int	add_alloc(t_alloc **lst_alloc, void *alloc, void **ptr_alloc)
{
	if (alloc == NULL && ptr_alloc == NULL)
	{
		rm_lst_alloc(*lst_alloc, "Error: Memory allocation issue");
		return (1);
	}
	if (alloc != NULL)
	{
		if (add_s_alloc(lst_alloc, alloc))
			return (1);
	}
	else if (ptr_alloc != NULL)
	{
		if (add_d_alloc(lst_alloc, ptr_alloc))
			return (1);
	}
	return (0);
}

int	add_s_alloc(t_alloc **lst_alloc, void *alloc)
{
	t_alloc	*temp;

	temp = NULL;
	if (*lst_alloc == NULL)
	{
		*lst_alloc = ft_lstnew_a(alloc, NULL);
		if (lst_alloc == NULL)
		{
			rm_lst_alloc(*lst_alloc, "Error: Memory allocation issue");
			return (1);
		}
	}
	else
	{
		temp = ft_lstnew_a(alloc, NULL);
		if (temp == NULL)
		{
			rm_lst_alloc(*lst_alloc, "Error: Memory allocation issue");
			return (1);
		}
		ft_lstadd_back_a(*lst_alloc, temp);
	}
	return (0);
}

int	add_d_alloc(t_alloc **lst_alloc, void **ptr_alloc)
{
	t_alloc	*temp;

	temp = NULL;
	if (*lst_alloc == NULL)
	{
		*lst_alloc = ft_lstnew_a(NULL, ptr_alloc);
		if (lst_alloc == NULL)
		{
			rm_lst_alloc(*lst_alloc, "Error: Memory allocation issue");
			return (1);
		}
	}
	else
	{
		temp = ft_lstnew_a(NULL, ptr_alloc);
		if (temp == NULL)
		{
			rm_lst_alloc(*lst_alloc, "Error: Memory allocation issue");
			return (1);
		}
		ft_lstadd_back_a(*lst_alloc, temp);
	}
	return (0);
}

// Recuper la node correspondant a l'alloc en parametre de rm_alloc
t_alloc	*get_node(t_alloc *lst_alloc, void *alloc, void **ptr_alloc)
{
	t_alloc	*node;

	node = lst_alloc;
	if (alloc != NULL)
	{
		while (node != NULL)
		{
			if (node->alloc == alloc)
				return (node);
			node = node->next;
		}
	}
	else if (ptr_alloc != NULL)
	{
		while (node != NULL)
		{
			if (node->ptr_alloc == ptr_alloc)
				return (node);
			node = node->next;
		}
	}
	return (NULL);
}

// free/supprime une alloc de la liste
int	rm_alloc(t_alloc *lst_alloc, void *alloc, void **ptr_alloc)
{
	t_alloc	*node;
	t_alloc	*beacon;

	if (alloc == NULL && ptr_alloc == NULL)
		return (1);
	node = get_node(lst_alloc, alloc, ptr_alloc);
	beacon = lst_alloc;
	if (node == beacon)
		lst_alloc = lst_alloc->next;
	else
	{
		while (beacon->next != node)
			beacon = beacon->next;
		beacon->next = node->next;
	}
	free(node->alloc);
	free(node->ptr_alloc);
	free(node);
	return (0);
}
