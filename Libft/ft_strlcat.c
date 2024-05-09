/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:46:12 by sylabbe           #+#    #+#             */
/*   Updated: 2023/12/03 15:55:31 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dest;
	size_t	len_src;

	if ((dest == NULL && size == 0) || (src == NULL && size == 0))
		return (0);
	len_src = ft_strlen((char *)src);
	len_dest = ft_strlen((char *)dest);
	i = 0;
	if (dest[0] == '\0' && size == 0)
		return (len_src);
	if (size < len_dest)
		return (len_src + size);
	while ((len_dest + i) < size - 1 && src[i] != '\0')
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	if (len_dest + i < size)
		dest[len_dest + i] = '\0';
	return (len_src + len_dest);
}
