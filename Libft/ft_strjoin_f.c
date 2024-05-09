/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:24:36 by sylabbe           #+#    #+#             */
/*   Updated: 2024/02/27 16:38:21 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_entries(char *s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
	{
		free ((char *)s1);
		free ((char *)s2);
		return (1);
	}
	return (0);
}

char	*ft_strjoin_f(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (check_entries(s1, s2))
		return (NULL);
	str = malloc((ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1) * sizeof(char));
	if (str == NULL)
	{
		free ((char *)s1);
		free((char *)s2);
		return (NULL);
	}
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[++j] != '\0')
		str[i + j] = s2[j];
	str[i + j] = '\0';
	free ((char *)s1);
	free ((char *)s2);
	return (str);
}
