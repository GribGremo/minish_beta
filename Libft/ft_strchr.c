/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:38:02 by sylabbe           #+#    #+#             */
/*   Updated: 2024/03/29 12:04:47 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int searchedChar)
{
	int			i;
	const char	*ptr;

	i = 0;
	if (string == NULL)
		return (NULL);
	while (string[i] != '\0')
	{
		if (string[i] == (unsigned char)searchedChar)
		{
			ptr = &string[i];
			return ((char *) ptr);
		}
		i++;
	}
	if (searchedChar == '\0')
	{
		ptr = &string[i];
		return ((char *) ptr);
	}
	return (NULL);
}
