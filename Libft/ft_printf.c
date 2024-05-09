/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:13:42 by sylabbe           #+#    #+#             */
/*   Updated: 2024/02/13 15:40:26 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_int(long int nb, int count)
{
	if (nb == -2147483648)
	{
		count += write(1, "-2147483648", 11);
		return (count);
	}
	if (nb < 0)
	{
		count += write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
	{
		count = print_int(nb / 10, count);
		count = print_int(nb % 10, count);
	}
	if (nb >= 0 && nb < 10)
	{
		nb = nb + 48;
		count += write(1, &nb, 1);
	}
	return (count);
}

int	print_ptr(unsigned long nb, int count, char c)
{
	if ((unsigned long *)nb == NULL)
		return (count += write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	count = print_hexa(nb, count, c);
	return (count);
}

int	print_hexa(unsigned long nb, int count, char c)
{
	int				maj;
	unsigned long	base;

	base = 10;
	if (c == 'x' || c == 'X' || c == 'p')
		base = 16;
	maj = 87;
	if (c == 'X')
		maj = 55;
	if (nb >= base)
	{
		count = print_hexa(nb / base, count, c);
		count = print_hexa(nb % base, count, c);
	}
	if (nb >= 10 && nb < 16 && base == 16)
	{
		nb = nb + maj;
		count += write(1, &nb, 1);
	}
	if (nb < 10)
	{
		nb = nb + 48;
		count += write(1, &nb, 1);
	}
	return (count);
}

int	print_arg(int count, char c, va_list prmt, int *cpt)
{
	if (c == 'c')
		count += ft_putchar((int)va_arg(prmt, int), 1);
	if (c == 's')
		count = print_string(va_arg(prmt, char *), count);
	if (c == 'p')
		count = print_ptr((unsigned long)va_arg(prmt, void *), count, c);
	if (c == 'd' || c == 'i')
		count = print_int((int)va_arg(prmt, int), count);
	if (c == 'u' || c == 'x' || c == 'X')
		count = print_hexa(va_arg(prmt, unsigned int), count, c);
	if (c == '%')
		count += ft_putchar('%', 1);
	if (!ft_strchr("cspdiuxX%", c) && c != '\0')
	{
		*cpt = 1;
		count += ft_putchar('%', 1);
	}
	if (c == '\0' && *cpt == 0)
		count = -1;
	if (c == '\0' && *cpt == 1)
		count += ft_putchar('%', 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	prmt;
	int		i;
	int		count;
	int		cpt;

	va_start (prmt, str);
	count = 0;
	i = 0;
	cpt = 0;
	if (str == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			count += ft_putchar(str[i], 1);
		else
		{
			count = print_arg(count, str[i + 1], prmt, &cpt);
			if (ft_strchr("cspdiuxX%", str[i + 1]) && str[i + 1] != '\0')
				i++;
		}
		i++;
	}
	va_end (prmt);
	return (count);
}
