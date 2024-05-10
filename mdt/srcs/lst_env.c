/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:29:54 by sylabbe           #+#    #+#             */
/*   Updated: 2024/05/10 15:54:49 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_lstnew_env(t_alloc **lst_alloc)
{
	t_env	*node;

	node = malloc(sizeof(t_env));
	if (add_alloc((lst_alloc), node, NULL))
		return (NULL);
	node->var = NULL;
	node->value = NULL;
	node->origin = 0;
	node->next=NULL;
	return (node);
}

void	ft_lstadd_back_env(t_env **lst, t_env *new)
{
	t_env	*beacon;

	if (lst == NULL || new == NULL)
		return ;
	beacon = ft_lstlast_env(*lst);
	beacon->next = new;
}

t_env	*ft_lstlast_env(t_env *lst)
{
	t_env	*beacon;

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

int	ft_lstsize_env(t_env *lst)
{
	int		i;
	t_env	*beacon;

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