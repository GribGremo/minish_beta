/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:56:25 by sylabbe           #+#    #+#             */
/*   Updated: 2023/12/03 14:37:41 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	size_t	i;

	i = 0;
	if (length == 0)
		return (0);
	while (i < length && (int)i <= ft_strlen(first)
		&& (int)i <= ft_strlen(second))
	{
		if (first[i] != second[i])
			return ((unsigned char)first[i] - (unsigned char) second[i]);
		i++;
	}
	return (0);
}
