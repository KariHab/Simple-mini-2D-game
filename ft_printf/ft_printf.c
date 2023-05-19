/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:09:25 by khabbout          #+#    #+#             */
/*   Updated: 2023/01/18 19:09:25 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_specifier(va_list args, char specifier)
{
	int	len_printed;

	len_printed = 0;
	if (specifier == 'c')
		len_printed += ft_putchar_fd(va_arg(args, int), 1);
	else if (specifier == 's')
		len_printed += ft_putstr_fd(va_arg(args, char *), 1);
	else if (specifier == 'd' || specifier == 'i')
		len_printed += ft_putnbr_fd(va_arg(args, int), 1);
	else if (specifier == 'u')
		return (ft_printu(va_arg(args, unsigned int)));
	else if (specifier == 'p')
		return (ft_printptr(va_arg(args, unsigned long long)));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_printhex(va_arg(args, unsigned int), specifier));
	else if (specifier == '%')
		return (ft_putchar_fd('%', 1));
	return (len_printed);
}

int	ft_printf(const char *s, ...)
{
	int		index;
	int		len_printed;
	va_list	args;

	index = 0;
	len_printed = 0;
	va_start(args, s);
	if (!s)
		return (0);
	while (s[index])
	{
		if (s[index] != '%')
			len_printed += ft_putchar_fd(s[index], 1);
		else if (s[index] == '%')
		{
			index++;
			len_printed += ft_specifier(args, s[index]);
		}
		index++;
	}
	va_end(args);
	return (len_printed);
}
