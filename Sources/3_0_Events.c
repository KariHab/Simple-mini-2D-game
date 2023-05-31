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

	// faire une ft pour check la tile suivante et couper les lines
int check_tile(char c)
{
	if (c == '0' || c == 'C' || c == 'E')
		return(0);
	return(1);
}

void key_hook_handler(mlx_key_data_t keydata, void *param)
{
	map *data;

	data = param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP))
			if (check_tile(data->map[data->y_pos_player - 1][data->x_pos_player]) == 0)
			// if (data->map[data->y_pos_player - 1][data->x_pos_player] == '0' || data->map[data->y_pos_player - 1][data->x_pos_player] == 'C' || data->map[data->y_pos_player - 1][data->x_pos_player] == 'E')
				move_player(data, 'w');
		if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN))
			if (check_tile(data->map[data->y_pos_player + 1][data->x_pos_player]) == 0)
			// if (data->map[data->y_pos_player + 1][data->x_pos_player] == '0' || data->map[data->y_pos_player + 1][data->x_pos_player] == 'C' || data->map[data->y_pos_player + 1][data->x_pos_player] == 'E')
				move_player(data, 's');
		if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT))
			if (check_tile(data->map[data->y_pos_player][data->x_pos_player + 1]) == 0)
			// if (data->map[data->y_pos_player][data->x_pos_player + 1] == '0' || data->map[data->y_pos_player][data->x_pos_player + 1] == 'C' || data->map[data->y_pos_player][data->x_pos_player + 1] == 'E')
				move_player(data, 'd');
		if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT))
			if (check_tile(data->map[data->y_pos_player][data->x_pos_player - 1]) == 0)
			// if (data->map[data->y_pos_player][data->x_pos_player - 1] == '0' || data->map[data->y_pos_player][data->x_pos_player - 1] == 'C' || data->map[data->y_pos_player][data->x_pos_player - 1] == 'E')
				move_player(data, 'a');
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(data->mlx);
	}
}

void move_player(map *data, char direction)
{
	//faire une ft pour si c'est un teddy augmenter le collected
	data->steps_count++;
	if (direction == 'w')
	{
		// data->map[data->y_pos_player - 1][data->x_pos_player] = 'P';
		data->map[data->y_pos_player][data->x_pos_player] = '0';
		data->y_pos_player--;
	}
	if (direction == 's')
	{
		// data->map[data->y_pos_player + 1][data->x_pos_player] = 'P';
		data->map[data->y_pos_player][data->x_pos_player] = '0';
		data->y_pos_player++;
	}
	if (direction == 'a')
	{
		// data->map[data->y_pos_player][data->x_pos_player - 1] = 'P';
		data->map[data->y_pos_player][data->x_pos_player] = '0';
		data->x_pos_player--;
	}
	if (direction == 'd')
	{
		// data->map[data->y_pos_player][data->x_pos_player + 1] = 'P';
		data->map[data->y_pos_player][data->x_pos_player] = '0';
		data->x_pos_player++;
	}
	data->map[data->y_pos_player][data->x_pos_player] = 'P';
	ft_printf("Moves: %d\n", data->steps_count);
}

// int check_teddy_and_bed(map *data, char c)
// {
// 	if (c == 'C')
// 	{
// 		printf("entered\n");
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

// void move_player_y_axis(map *data, char direction)
// {
// 	if (direction == 'w')
// 	{
// 		if (data->map[data->y_pos_player - 1][data->x_pos_player] == '0'
// 		|| data->map[data->y_pos_player - 1][data->x_pos_player] == 'C'
// 		|| data->map[data->y_pos_player - 1][data->x_pos_player] == 'E')
// 		{
// 			data->steps_count++;
// 			data->map[data->y_pos_player - 1][data->x_pos_player] = 'P';
// 			data->map[data->y_pos_player][data->x_pos_player] = '0';
// 			data->y_pos_player--;
// 		}
// 	}
// 	if (direction == 's')
// 	{
// 		if (data->map[data->y_pos_player + 1][data->x_pos_player] == '0'
// 		|| data->map[data->y_pos_player + 1][data->x_pos_player] == 'C'
// 		|| data->map[data->y_pos_player + 1][data->x_pos_player] == 'E')
// 		{
// 			data->steps_count++;
// 			if (check_teddy_and_bed(data, data->map[data->y_pos_player + 1][data->x_pos_player] == 1))
// 				return;
// 			data->map[data->y_pos_player + 1][data->x_pos_player] = 'P';
// 			data->map[data->y_pos_player][data->x_pos_player] = '0';
// 			data->y_pos_player++;
// 		}
// 	}
// 	ft_printf("Moves: %d\n", data->steps_count);
// }

// void move_player_x_axis(map *data, char direction)
// {
// 	if (direction == 'a')
// 	{
// 		if (data->map[data->y_pos_player][data->x_pos_player - 1] == '0'
// 		|| data->map[data->y_pos_player][data->x_pos_player - 1] == 'C'
// 		|| data->map[data->y_pos_player][data->x_pos_player - 1] == 'E')
// 		{
// 			data->steps_count++;
// 			if (check_teddy_and_bed(data, data->map[data->y_pos_player][data->x_pos_player - 1] == 1))
// 				return;
// 			data->map[data->y_pos_player][data->x_pos_player - 1] = 'P';
// 			data->map[data->y_pos_player][data->x_pos_player] = '0';
// 			data->x_pos_player--;
// 		}
// 	}

// 	if (direction == 'd')
// 	{
// 		if (data->map[data->y_pos_player][data->x_pos_player + 1] == '0'
// 		|| data->map[data->y_pos_player][data->x_pos_player + 1] == 'C'
// 		|| data->map[data->y_pos_player][data->x_pos_player + 1] == 'E')
// 		{
// 			data->steps_count++;
// 			if (check_teddy_and_bed(data, data->map[data->y_pos_player][data->x_pos_player + 1] == 1))
// 				return;
// 			data->map[data->y_pos_player][data->x_pos_player + 1] = 'P';
// 			data->map[data->y_pos_player][data->x_pos_player] = '0';
// 			data->x_pos_player++;
// 		}
// 	}
// 	ft_printf("Moves: %d\n", data->steps_count);
// }

