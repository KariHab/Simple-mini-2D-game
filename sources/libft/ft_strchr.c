/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:08:52 by khabbout          #+#    #+#             */
/*   Updated: 2023/01/10 09:08:52 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*find the first occurence of a char in a str*/
char	*ft_strchr(char *s, int c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	while (i <= len)
	{
		if (((char *)s)[i] == (char)c)
			return (((char *)s) + i);
		i++;
	}
	return (NULL);
}
