/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:33:00 by sylabbe           #+#    #+#             */
/*   Updated: 2023/11/03 16:02:03 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	j = 0;
	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		while (big[i + j] == little [j] && (i + j) < len)
		{
			j++;
			if (little[j] == '\0')
			{
				ptr = (char *) &big[i];
				return ((char *)ptr);
			}
		}
		j = 0;
		i++;
	}
	return (0);
}
