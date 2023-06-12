/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:07:21 by khabbout          #+#    #+#             */
/*   Updated: 2023/01/12 15:07:21 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int n)
{
	int	size;

	size = 1;
	while (n > 9 || n < -9)
	{
		n = n / 10;
		size++;
	}
	if (n < 0)
		size++;
	return (size);
}

/*convert an int to a char*/
char	*ft_itoa(int nbr)
{
	char		*tmp;
	int			size;
	long int	nb;

	size = get_size(nbr);
	tmp = ft_calloc(size + 1, (sizeof(char)));
	if (!tmp)
		return (NULL);
	tmp[size] = '\0';
	nb = nbr;
	if (nb == 0)
		tmp[0] = '0';
	if (nb < 0)
	{
		tmp[0] = '-';
		nb = nb / -1;
	}
	while (nb)
	{
		tmp[size - 1] = nb % 10 + '0';
		nb = (nb / 10);
		size--;
	}
	return (tmp);
}
