/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <marvin@43.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:57:46 by sylabbe           #+#    #+#             */
/*   Updated: 2023/12/03 14:42:58 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	char	*res;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (0);
	while (s1[i] != '\0' && ft_strchr((char *)set, s1[i]) != 0)
		i++;
	start = i;
	i = ft_strlen(s1);
	while (i - 1 > start && ft_strchr(set, s1[i - 1]) != 0)
		i--;
	i -= start;
	res = ft_substr(s1, start, i);
	return (res);
}
