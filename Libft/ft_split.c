/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:36:32 by sylabbe           #+#    #+#             */
/*   Updated: 2023/12/03 15:51:26 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static	char	**create_tab(const char *s, char c, char **tab)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (s[i] != c && s[i] != '\0')
		count++;
	while (s[i] != '\0')
	{
		if (s[i] == c && (s[i + 1] != c && s[i + 1] != '\0'))
			count++;
		i++;
	}
	tab = malloc((count + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	return (tab);
}


static	char	*create_str(const char *s, int start, int end)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc((end - start + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	while (start < end)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

static	char	**errfree(char **tab, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free (tab[i]);
		i++;
	}
	free (tab);
	return (NULL);
}

static	char	**fill_tab(const char *s, char c, char **res)
{
	int	i;
	int	count;
	int	start;

	i = 0;
	start = 0;
	count = -1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			start = i + 1;
		else if (s[i + 1] == c || s[i + 1] == '\0')
		{
			count++;
			res[count] = create_str(s, start, i + 1);
			if (res[count] == NULL)
				return (errfree(res, count));
		}
		i++;
	}
	res[count + 1] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	res = NULL;
	if (s == NULL)
		return (NULL);
	res = create_tab(s, c, res);
	if (res == NULL)
		return (NULL);
	fill_tab(s, c, res);
	return (res);
}
