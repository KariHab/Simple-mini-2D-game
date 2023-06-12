/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:44:11 by khabbout          #+#    #+#             */
/*   Updated: 2023/01/12 14:44:11 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/*trim a set of char from start and end of a str*/
char	*ft_strtrim(char *s1, char *set)
{
	size_t	i;
	size_t	beg;
	size_t	end;
	char	*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	beg = 0;
	while (s1[beg] && is_in_set(s1[beg], set))
		beg++;
	end = ft_strlen(s1);
	while (end > beg && is_in_set(s1[end - 1], set))
		end--;
	str = malloc(sizeof(char) * (end - beg + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (beg < end)
		str[i++] = s1[beg++];
	str[i] = '\0';
	return (str);
}
