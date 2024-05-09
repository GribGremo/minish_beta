/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:56:14 by sylabbe           #+#    #+#             */
/*   Updated: 2023/11/03 16:32:19 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *ptr, int val, size_t count)
{
	size_t	i;
	char	*ptr2;

	ptr2 = ptr;
	i = 0;
	while (i != count)
	{
		ptr2[i] = val;
		i++;
	}
	return (ptr2);
}
