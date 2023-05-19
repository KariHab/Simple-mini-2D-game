/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:46:59 by khabbout          #+#    #+#             */
/*   Updated: 2023/01/31 12:46:59 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_size(unsigned int n)
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

void	ft_converthex(unsigned int nb, const char specifier)
{
	if (nb >= 16)
	{
		ft_converthex(nb / 16, specifier);
		ft_converthex(nb % 16, specifier);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + 48), 1);
		else
		{
			if (specifier == 'x')
				ft_putchar_fd((nb - 10 + 'a'), 1);
			if (specifier == 'X')
				ft_putchar_fd((nb - 10 + 'A'), 1);
		}
	}
}

int	ft_printhex(unsigned int nbr, const char specifier)
{
	if (nbr == 0)
		return (ft_putchar_fd('0', 1));
	ft_converthex(nbr, specifier);
	return (get_size(nbr));
}
