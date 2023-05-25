/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:08:58 by khabbout          #+#    #+#             */
/*   Updated: 2023/01/10 09:08:58 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*append a desired len of src at the end of dest*/
size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(dst);
	i = 0;
	if (dst == NULL || src == NULL)
		return (0);
	if (dstsize <= j)
		return (ft_strlen(src) + dstsize);
	while (src[i] && j + i < (dstsize - 1))
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	return (j + ft_strlen(src));
}
