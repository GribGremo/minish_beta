/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:51:08 by sylabbe           #+#    #+#             */
/*   Updated: 2024/04/03 17:57:38 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*create_str(t_alloc **lst_alloc, char *s1, char *s2)
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
	if (add_alloc(lst_alloc, str, NULL))
		return (NULL);
	return (str);
}

char	*ft_strjoin_a(t_alloc **lst_alloc, char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	str = create_str(lst_alloc, (char *)s1, (char *)s2);
	if (str == NULL)
		return (NULL);
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
