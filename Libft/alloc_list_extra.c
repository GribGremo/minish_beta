/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_list_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:05:54 by sylabbe           #+#    #+#             */
/*   Updated: 2024/04/03 18:06:12 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_list_alloc(t_alloc *lst_alloc)
{
	t_alloc	*node;

	node = lst_alloc;
	if (node == NULL)
		ft_printf("Allocation list empty\n");
	while (node != NULL)
	{
		ft_printf("NODE__________________\n");
		ft_printf("node : %p\n", node);
		ft_printf("node->alloc : %p\n", node->alloc);
		ft_printf("node->ptr_alloc : %p\n", node->ptr_alloc);
		ft_printf("node->next : %p\n", node->next);
		node = node->next;
	}
	ft_printf("\nNombre d'allocs  : %d\n", ft_lstsize_a(lst_alloc));
	ft_printf("\n");
}
