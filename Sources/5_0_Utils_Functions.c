/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_0_Utils_Functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:34:50 by khabbout          #+#    #+#             */
/*   Updated: 2023/05/25 11:34:50 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../Headers/so_long.h"

void	free_all(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return ;
}

void	print_moves(map *data)
{
	if (data->steps_count == 1)
		ft_printf("%d move\n", data->steps_count);
	else
		ft_printf("%d moves\n", data->steps_count);
}

void	print_teddy(map *data)
{
		ft_printf("You have %d teddy-bears left to collect\n", (data->number_of_teddy - data->collected));
}