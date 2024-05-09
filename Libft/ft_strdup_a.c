/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:23:50 by sylabbe           #+#    #+#             */
/*   Updated: 2024/04/03 18:07:31 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_a(t_alloc **lst_alloc, const char *source)
{
	int		i;
	char	*ptr;

	i = 0;
	while (source[i] != '\0')
		i++;
	ptr = malloc ((i + 1) * sizeof(char));
	if (add_alloc(lst_alloc, ptr, NULL))
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
