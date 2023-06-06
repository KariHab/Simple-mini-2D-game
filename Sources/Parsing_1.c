/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:40:48 by khabbout          #+#    #+#             */
/*   Updated: 2023/06/06 12:40:48 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int validate_if_map_is_playable(t_map *data)
{
	if (data->number_of_exit != 1)
		exit(ft_printf(RED "ERROR.\nThe map should have an exit\n" WHITE));
	if (data->number_of_player != 1)
		exit(ft_printf(RED "ERROR.\nThis is a solo game\n" WHITE));
	if (data->rectangle == 1)
		exit(ft_printf(RED "ERROR.\nThe map should be a clean rectangle\n" WHITE));
	if (data->wall == 1)
		exit(ft_printf(RED "ERROR.\nThis is not an open world map\n" WHITE));
	if (data->number_of_teddy < 1)
		exit(ft_printf(RED "ERROR.\nYou should have one teddy in your room!\n" WHITE));
	if (data->wrong_char > 0)
		exit(ft_printf(RED "ERROR.\nYou put a wrong char in the map\n" WHITE));
	return (0);
}

void flood(t_map *data)
{
	printf("Real: %d Flood: %d\n", data->number_of_exit, data->flood.exit);
	map_copy(data);
	path_checker(data, data->player.x_pos_player, data->player.y_pos_player);
	if (data->number_of_teddy != data->flood.teddy_to_collect)
		exit(ft_printf(RED "Error\nSome teddy cannot be collected.\n" WHITE));
	if (data->number_of_exit != data->flood.exit)
		exit(ft_printf(RED "Error.\nThe exit cannot be reached.\n" WHITE));
	free_all(data->flood.map_copy);
}

void path_checker(t_map *data, int x, int y)
{

	if (y < 0 || x < 0 || x > data->column - 1 || y > data->row - 1)
		return;
	if ((data->flood.map_copy[y][x] == '1' || data->flood.map_copy[y][x] == 'x'))
		return;
	if (data->flood.map_copy[y][x] == 'C')
		data->flood.teddy_to_collect++;
	else if (data->flood.map_copy[y][x] == 'E')
		data->flood.exit++;
	data->flood.map_copy[y][x] = 'x';
	path_checker(data, x, y + 1);
	path_checker(data, x, y - 1);
	path_checker(data, x + 1, y);
	path_checker(data, x - 1, y);
	return;
}

void map_copy(t_map *data)
{
	int index;

	index = 0;
	data->flood.map_copy = ft_calloc((data->row + 1), sizeof(char *));
	if (!data->flood.map_copy)
		exit(1);
	while (data->map[index])
	{
		data->flood.map_copy[index] = ft_calloc((data->column + 1), sizeof(char));
		if (!data->flood.map_copy[index])
		{
			free_all(data->flood.map_copy);
			exit(1);
		}
		ft_memcpy(data->flood.map_copy[index], data->map[index], data->column + 1);
		index++;
	}
}

void parsing(char *path, t_map *data)
{
	create_map(path, data);
	count_chars_in_map(data);
	data->column = ft_strlen(data->map[0]);
	check_is_map_rectangle(data);
	check_the_wall_around_map(data);
	validate_if_map_is_playable(data);
	flood(data);
}