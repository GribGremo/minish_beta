/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:40:11 by sylabbe           #+#    #+#             */
/*   Updated: 2023/11/24 12:18:16 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *string, int searchedChar)
{
	int			i;
	const char	*ptr;

	i = 0;
	while (string[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (string[i] == (unsigned char)searchedChar)
		{
			ptr = &string[i];
			return ((char *) ptr);
		}
		i--;
	}
	return (0);
}
