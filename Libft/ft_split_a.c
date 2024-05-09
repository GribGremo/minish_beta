/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:16:19 by sylabbe           #+#    #+#             */
/*   Updated: 2024/05/01 14:30:40 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**create_tab(t_alloc **lst_alloc, const char *s, char c, char **tab)
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
	if (add_alloc(lst_alloc, NULL, (void **)tab))
		return (NULL);
	return (tab);
}

char	*create_str_a(t_alloc **lst_alloc, const char *s, int start, int end)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc((end - start + 1) * sizeof(char));
	if (add_alloc(lst_alloc, str, NULL))
		return (NULL);
	while (start < end)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	**errfree_a(t_alloc **lst_alloc)
{
	rm_lst_alloc(*lst_alloc, NULL);
	return (NULL);
}

static char	**fill_tab(t_alloc **lst_alloc, const char *s, char c, char **res)
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
			res[count] = create_str_a(lst_alloc, s, start, i + 1);
			if (res[count] == NULL)
				return (errfree_a(lst_alloc));
		}
		i++;
	}
	res[count + 1] = NULL;
	return (res);
}

char	**ft_split_a(t_alloc **lst_alloc, char const *s, char c)
{
	char	**res;

	res = NULL;
	if (s == NULL)
		return (NULL);
	res = create_tab(lst_alloc, s, c, res);
	if (res == NULL)
		return (NULL);
	fill_tab(lst_alloc, s, c, res);
	return (res);
}
