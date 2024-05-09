/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:14:56 by sylabbe           #+#    #+#             */
/*   Updated: 2024/02/25 14:03:52 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *source)
{
	int		i;
	char	*ptr;

	i = 0;
	while (source[i] != '\0')
		i++;
	ptr = malloc ((i + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (source[i] != '\0')
	{
		ptr[i] = source[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
