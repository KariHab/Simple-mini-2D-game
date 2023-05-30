/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_0_Events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:34:38 by khabbout          #+#    #+#             */
/*   Updated: 2023/05/25 11:34:38 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/so_long.h"

void	key_hook_handler(mlx_key_data_t keydata, void *param)
{
	map	*data;

	data = param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP))
			if (data->map[data->y_pos_player - 1][data->x_pos_player] == '0')
				move_player_y_axis(data, 'w');
		if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN))
			if (data->map[data->y_pos_player + 1][data->x_pos_player] == '0')
				move_player_y_axis(data, 's');
		if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT))
			if (data->map[data->y_pos_player][data->x_pos_player + 1] == '0')
				move_player_x_axis(data, 'd');
		if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT))
			if (data->map[data->y_pos_player][data->x_pos_player - 1] == '0')
				move_player_x_axis(data, 'a');
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(data->mlx);
	}
}

void	move_player_y_axis(map *data, char direction)
{
	if (direction == 'w')
	{
		data->map[data->y_pos_player - 1][data->x_pos_player] = 'P';
		data->map[data->y_pos_player][data->x_pos_player] = '0';
		data->y_pos_player--;
		data->steps_count++;
	}
	if (direction == 's')
	{
		data->map[data->y_pos_player + 1][data->x_pos_player] = 'P';
		data->map[data->y_pos_player][data->x_pos_player] = '0';
		data->y_pos_player++;
		data->steps_count++;
	}
	ft_printf("Moves: %d\n", data->steps_count);
}

void	move_player_x_axis(map *data, char direction)
{
	if (direction == 'a')
	{
			data->map[data->y_pos_player][data->x_pos_player - 1] = 'P';
			data->map[data->y_pos_player][data->x_pos_player] = '0';
			data->x_pos_player--;
			data->steps_count++;
	}
	if (direction == 'd')
	{
		data->map[data->y_pos_player][data->x_pos_player + 1] = 'P';
		data->map[data->y_pos_player][data->x_pos_player] = '0';
		data->x_pos_player++;
		data->steps_count++;
	}
	ft_printf("Moves: %d\n", data->steps_count);
}

// int check_teddy_and_bed(map *data, char c)
// {
// 	if (c == 'C')
// 	{
// 		data->number_of_teddy--;
// 		print_teddy_collected(data);
// 		if (data->number_of_teddy == 0)
// 			printf("You can go to sleep now!\n");
// 	}
// 	else if (c == 'E' && data->number_of_teddy != 0)
// 	{
// 		printf("I still see some of your teddy lying around little girl!\n");
// 		return (1);
// 	}
// 	else if (c == 'E' && data->number_of_teddy == 0)
// 	{
// 		mlx_close_window(data->mlx);
// 		printf("You made it in %d moves!\n", data->steps_count);
// 		remove_image(data);
// 	}
// 	return (0);
// }

// void handle_collectible(map *data)
// {
// 	if (data->map[data->y_pos_player][data->x_pos_player] == 'C')
// 	{
// 		data->number_of_teddy--;
// 		data->map[data->y_pos_player][data->x_pos_player] = '0';
// 	}

// }