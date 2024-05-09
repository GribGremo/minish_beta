/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:14:35 by sylabbe           #+#    #+#             */
/*   Updated: 2023/11/06 17:18:05 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static char	*create_str(char *s1, char *s2)
{
	int		i;
	int		totalmem;
	char	*str;

	i = 0;
	totalmem = 0;
	while (s2[i] != '\0')
		i++;
	totalmem += i;
	i = 0;
	while (s1[i] != '\0')
		i++;
	totalmem += i + 1;
	str = malloc(totalmem * sizeof(char));
	if (str == NULL)
		return (0);
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	str = create_str((char *)s1, (char *)s2);
	if (str == NULL)
		return (0);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
