/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:49:30 by sylabbe           #+#    #+#             */
/*   Updated: 2024/03/07 18:51:17 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(int c, int cnt)
{
	int	count;

	count = 0;
	count += write(1, &c, cnt);
	return (count);
}

int	print_string(char *s, int count)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		count += write(1, "(null)", 6);
		return (count);
	}
	while (s[i] != '\0')
	{
		count += write(1, &s[i], 1);
		i++;
	}
	return (count);
}

// char	*ft_strchr(const char *string, int searchedChar)
// {
// 	int			i;
// 	const char	*ptr;

// 	i = 0;
// 	while (string[i] != '\0')
// 	{
// 		if (string[i] == (unsigned char)searchedChar)
// 		{
// 			ptr = &string[i];
// 			return ((char *) ptr);
// 		}
// 		i++;
// 	}
// 	if (searchedChar == '\0')
// 	{
// 		ptr = &string[i];
// 		return ((char *) ptr);
// 	}
// 	return (NULL);
// }
