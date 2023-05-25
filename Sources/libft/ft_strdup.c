/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:31:37 by khabbout          #+#    #+#             */
/*   Updated: 2023/01/20 18:20:24 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*duplicate a str in another memory block*/
char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*copy;

	if (s1 == NULL)
		return (NULL);
	len = 0;
	while (s1[len])
		len++;
	copy = malloc(len + 1);
	if (copy != NULL)
	{
		i = 0;
		while (s1[i])
		{
			copy[i] = s1[i];
			i++;
		}
		copy[i] = '\0';
	}
	return (copy);
}
