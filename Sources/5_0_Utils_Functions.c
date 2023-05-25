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

void	ft_freeall(char **tab)
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

void  print_collected_and_moves(map *data)
{
	mlx_delete_image(data->mlx, data->image.move);
	data->image.move = mlx_put_string(data->mlx, "Moves:", 3, data->row * 32 + 25);
	data->image.teddy = mlx_put_string(data->mlx, "Teddy left to collect:", 3, data->row *32 + 25);
}

void	print_moves(map *data)
{
	char	*move_count;

	move_count = ft_itoa(data->steps_count);
	mlx_delete_image(data->mlx, data->image.move_nbr);
	data->image.move_nbr = mlx_put_string(data->mlx, move_count, 70, data->row * 32 + 5);
	free(move_count);
}

void	print_teddy_collected(map *data)
{
	char	*teddy_collected;

	teddy_collected = ft_itoa(data->number_of_teddy_collected);
	mlx_delete_image(data->mlx, data->image.collected_nbr);
	data->image.collected_nbr = mlx_put_string(data->mlx, teddy_collected, 202, data->row * 32 + 25);
	if (data->number_of_teddy == 0)
	{
		data->image.collected_nbr = mlx_put_string(data->mlx, " to collect...You can go home now!", 212, data->row * 32 + 25);
	}
	free(teddy_collected);
}