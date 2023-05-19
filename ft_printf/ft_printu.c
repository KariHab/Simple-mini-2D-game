/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:47:08 by khabbout          #+#    #+#             */
/*   Updated: 2023/01/31 12:47:08 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_size(unsigned long long n)
{
	int	size;

	size = 0;
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}

/*modified itoa for unsigned*/
char	*ft_convert_nbr(unsigned long long nbr)
{
	char	*tmp;
	int		size;

	size = get_size(nbr);
	tmp = ft_calloc(size + 1, (sizeof(char)));
	if (!tmp)
		return (NULL);
	while (nbr)
	{
		tmp[size - 1] = nbr % 10 + '0';
		nbr = (nbr / 10);
		size--;
	}
	return (tmp);
}

int	ft_printu(unsigned int nb)
{
	char	*number;
	int		len;

	if (nb == 0)
		return (ft_putchar_fd('0', 1));
	number = ft_convert_nbr(nb);
	len = ft_putstr_fd(number, 1);
	free (number);
	return (len);
}
