/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:58:07 by sylabbe           #+#    #+#             */
/*   Updated: 2023/12/03 15:53:25 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static int	get_size(long int n)
{
	int	size;

	size = 0;
	if (n == 0)
		size = 1;
	if (n < 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			size;
	long int	ln;

	ln = n;
	size = get_size(ln);
	res = malloc(size + 1 * sizeof(char));
	if (res == NULL)
		return (0);
	if (ln == 0)
		res[0] = '0';
	res[size] = '\0';
	if (ln < 0)
	{
		ln = ln * -1;
		res[0] = '-';
	}
	while (ln > 0)
	{
		res[size - 1] = (ln % 10) + 48;
		ln = ln / 10;
		size--;
	}
	return (res);
}
