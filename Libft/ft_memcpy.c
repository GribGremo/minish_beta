/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:30:41 by sylabbe           #+#    #+#             */
/*   Updated: 2023/12/03 14:31:14 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t			i;
	unsigned char	*dest2;
	unsigned char	*src2;

	i = 0;
	src2 = (unsigned char *) src;
	dest2 = (unsigned char *) dest;
	if (src2 == NULL && dest2 == NULL)
		return (0);
	while (i < size)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest2);
}
