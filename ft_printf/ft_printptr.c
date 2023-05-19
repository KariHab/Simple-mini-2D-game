/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:47:03 by khabbout          #+#    #+#             */
/*   Updated: 2023/01/31 12:47:03 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_size(uintptr_t n)
{
	int	size;

	size = 0;
	while (n)
	{
		size++;
		n /= 16;
	}
	return (size);
}

void	ft_convertptr(uintptr_t nbr)
{
	if (nbr >= 16)
	{
		ft_convertptr(nbr / 16);
		ft_convertptr(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar_fd((nbr + 48), 1);
		else
			ft_putchar_fd((nbr - 10 + 'a'), 1);
	}
}

int	ft_printptr(uintptr_t ptr)
{
	int	len;

	if (ptr == 0)
		return (write(1, "0x0", 3));
	len = ft_putstr_fd("0x", 1);
	ft_convertptr(ptr);
	len += get_size(ptr);
	return (len);
}
