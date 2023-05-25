/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:43:48 by khabbout          #+#    #+#             */
/*   Updated: 2023/01/12 14:43:48 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*copy a substring of a str into another memory block*/
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start < ft_strlen(s))
		while (s[i + start] && len > i)
			i++;
	str = ft_calloc(i * sizeof(char) + 1, 1);
	if (str == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (str);
	ft_strlcpy(str, s + start, i + 1);
	return (str);
}
