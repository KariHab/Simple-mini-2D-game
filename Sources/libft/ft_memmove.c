/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:08:44 by khabbout          #+#    #+#             */
/*   Updated: 2023/01/10 09:08:44 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*move n bytes from src to dest*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;
	size_t	i;

	s = (char *)src;
	d = (char *)dst;
	i = 0;
	if (src == NULL || dst == NULL)
		return (NULL);
	if (d > s)
		while (len-- > 0)
			d[len] = s[len];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
