/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_0_Parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:34:20 by khabbout          #+#    #+#             */
/*   Updated: 2023/05/25 11:34:20 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/so_long.h"

int check_extension_map_file(char *map_file_name)
{
	size_t len;

	len = ft_strlen(map_file_name);
	if (((len > 4) && map_file_name[len - 4] == '.' 
			&& map_file_name[len - 3] == 'b' 
			&& map_file_name[len - 2] == 'e' 
			&& map_file_name[len - 1] == 'r'))
		return (0);
	else
		return (-1);
}

/*get the number of 0 1 P E and C*/
void count_chars(map *data, int x, int y)
{
	if (data->map[y][x] == 'P')
	{
		data->number_of_player++;
		data->x_pos_player = x;
		data->y_pos_player = y;
	}
	else if (data->map[y][x] == 'E')
		data->number_of_exit++;
	else if (data->map[y][x] == 'C')
		data->number_of_teddy++;
	else if (data->map[y][x] == '0' || data->map[y][x] == '1')
		return ;
	else
		data->wrong_char++;
}

void count_objects(map *data)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			count_chars(data, x, y);
			x++;
		}
		y++;
	}
}

void check_the_wall_around_map(map *data)
{
	int x;
	int y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y] && data->map[x][y] != '\n')
		{
			if (data->map[0][y] != '1' || data->map[x][0] != '1' ||
				data->map[data->row - 1][y] != '1' ||
				data->map[x][data->column - 1] != '1')
				data->wall = 1;
			y++;
		}
		x++;
	}
}

void check_is_map_rectangle(map *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (data->map[x])
	{
		while (data->map[x][y] && data->map[x][y] != '\n')
			y++;
		if (y != data->column)
			data->rectangle = 1;
		y = 0;
		x++;
	}
}
