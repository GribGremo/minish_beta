/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:16:51 by sylabbe           #+#    #+#             */
/*   Updated: 2023/12/03 14:35:32 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t size)
{
	unsigned char	*s2;
	size_t			i;

	i = 0;
	s2 = (unsigned char *)s;
	while (i < size)
	{
		if (s2[i] == (unsigned char)c)
		{
			return ((void *) &s2[i]);
		}
		i++;
	}
	return (0);
}
