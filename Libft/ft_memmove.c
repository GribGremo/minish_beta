/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:40:14 by sylabbe           #+#    #+#             */
/*   Updated: 2023/12/03 14:34:31 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t size)
{
	unsigned int	i;
	unsigned char	*dest2;
	unsigned char	*src2;

	src2 = (unsigned char *) source;
	dest2 = (unsigned char *) dest;
	if (src2 == NULL && dest2 == NULL)
		return (0);
	if (dest2 > src2)
	{
		i = size;
		while (i--)
			dest2[i] = src2[i];
	}
	else
	{
		i = 0;
		while (i < size)
		{
			dest2[i] = src2[i];
			i++;
		}
	}
	return (dest2);
}
