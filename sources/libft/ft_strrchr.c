/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:09:23 by khabbout          #+#    #+#             */
/*   Updated: 2023/01/10 09:09:23 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*find the last occurence of a char in a str*/
char	*ft_strrchr(char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	while (i >= 0)
	{
		if (((char *)s)[i] == (char)c)
			return (((char *)s) + i);
		i--;
	}
	return (NULL);
}
