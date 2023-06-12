/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:43:59 by khabbout          #+#    #+#             */
/*   Updated: 2023/01/12 14:43:59 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	newstr = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (newstr == NULL)
		return (NULL);
	else
	{
		i = 0;
		j = 0;
		while (s1[j])
		{
			newstr[i++] = s1[j++];
		}
		j = 0;
		while (s2[j])
		{
			newstr[i++] = s2[j++];
		}
		newstr[i] = '\0';
	}
	return (newstr);
}
