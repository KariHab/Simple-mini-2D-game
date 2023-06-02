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

#include "../so_long.h"

int	check_tile_not_wall(char c)
{
	if (c == '0' || c == 'C' || c == 'E')
		return (0);
	return (1);
}

int	check_next_tile(map *data, char direction, char tile)
{
	if ((direction == 'd' && data->map[data->y_pos_player][data->x_pos_player + 1] == tile)
		|| (direction == 'a' && data->map[data->y_pos_player][data->x_pos_player - 1] == tile)
		|| (direction == 's' && data->map[data->y_pos_player + 1][data->x_pos_player] == tile)
		|| (direction == 'w' && data->map[data->y_pos_player - 1][data->x_pos_player] == tile))
		return (0);
	else
		return (1);
}

void	key_hook_handler(mlx_key_data_t keydata, void *param)
{
	map	*data;

	data = param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP))
			if (check_tile_not_wall(data->map[data->y_pos_player - 1]
					[data->x_pos_player]) == 0)
				move_player(data, 'w');
		if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN))
			if (check_tile_not_wall(data->map[data->y_pos_player + 1]
					[data->x_pos_player]) == 0)
				move_player(data, 's');
		if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT))
			if (check_tile_not_wall(data->map[data->y_pos_player]
					[data->x_pos_player + 1]) == 0)
				move_player(data, 'd');
		if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT))
			if (check_tile_not_wall(data->map[data->y_pos_player]
					[data->x_pos_player - 1]) == 0)
				move_player(data, 'a');
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(data->mlx);
	}
}

void collect_teddy(map *data, char direction)
{
	if ((direction == 'd' && data->map[data->y_pos_player][data->x_pos_player + 1] == 'C')
			|| (direction == 'a' && data->map[data->y_pos_player][data->x_pos_player - 1] == 'C')
			|| (direction == 'w' && data->map[data->y_pos_player - 1][data->x_pos_player] == 'C')
			|| (direction == 's' && data->map[data->y_pos_player + 1][data->x_pos_player] == 'C'))
			{
				data->collected++;
				print_teddy(data);
			}
}

void	move_player(map *data, char direction)
{
	if ((data->can_exit == 0 && check_next_tile(data, direction, 'E') == 0))
			return;
	data->steps_count++;
	collect_teddy(data, direction);
	if(data->collected == data->number_of_teddy)
		data->can_exit = 1;
	data->map[data->y_pos_player][data->x_pos_player] = '0';
	if (direction == 'w')
		data->y_pos_player--;
	if (direction == 's')
		data->y_pos_player++;
	if (direction == 'a')
		data->x_pos_player--;
	if (direction == 'd')
		data->x_pos_player++;
	print_moves(data);
	if (data->can_exit == 1 && data->map[data->y_pos_player][data->x_pos_player] == 'E')
		end_of_game(data);
	data->map[data->y_pos_player][data->x_pos_player] = 'P';
}
