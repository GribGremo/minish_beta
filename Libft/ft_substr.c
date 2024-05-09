/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:40:11 by sylabbe           #+#    #+#             */
/*   Updated: 2023/12/03 14:41:16 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	if (s == NULL)
		return (0);
	if ((int)start + (int)len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	if ((int)start > ft_strlen(s))
		len = 0;
	str = malloc(len + 1 * sizeof(char));
	if (str == NULL)
		return (0);
	while (i < (int)len && s[start + i] != '\0')
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
