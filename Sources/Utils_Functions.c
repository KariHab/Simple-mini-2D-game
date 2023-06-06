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

#include "../so_long.h"

void free_all(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return;
}

void print_moves(t_map *data)
{
	if (data->player.steps_count == 1)
		ft_printf(PURPLE "%d move\n" WHITE, data->player.steps_count);
	else
		ft_printf(PURPLE "%d moves\n" WHITE, data->player.steps_count);
}

void print_teddy(t_map *data)
{
	if (data->number_of_teddy == data->collected)
		ft_printf(GREEN "Good girl! You're done collecting now go to sleep!\n" WHITE);
	else
		ft_printf(CYAN "Collected: %d. Left to collect %d\n" WHITE, data->collected, (data->number_of_teddy - data->collected));
}

void end_of_game(t_map *data)
{
	if (data->can_exit == 1)
	{
		mlx_close_window(data->mlx);
		ft_printf(GREEN "You did: %d moves\nGood night!\n" WHITE, data->player.steps_count);
		remove_image(data);
	}
}