/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_1_Parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:34:27 by khabbout          #+#    #+#             */
/*   Updated: 2023/05/25 11:34:27 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int validate_if_map_is_playable(map *data)
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
	else
		data->is_valid = 0;
	return (0);
}

map *get_map_lines(char *path, map *data)
{
	char *str;
	int fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit(ft_printf(RED "ERROR.\nOpen failed. Check the map you want to open\n" WHITE));
	else
	{
		str = get_next_line(fd);
		while (str != NULL)
		{
			data->row++;
			free(str);
			str = get_next_line(fd);
		}
	}
	close(fd);
	return (data);
}

void create_map(char *path, map *data)
{
	int i;
	int fd;

	i = 0;
	get_map_lines(path, data);
	data->map = ft_calloc(sizeof(char *), (data->row + 1));
	if (!data->map)
		return;
	fd = open(path, O_RDONLY);
	while (fd > 0)
	{
		data->map[i] = get_next_line(fd);
		if (!data->map[i])
			break;
		if (data->map[i][0] == '\n')
			data->rectangle = 1;
		if (data->map[i][ft_strlen(data->map[i]) - 1] == '\n')
			data->map[i][ft_strlen(data->map[i]) - 1] = '\0';
		i++;
	}
	if (fd < 0)
		exit(ft_printf(RED "ERROR.\nOpen failed. Check the map you want to open\n" WHITE));
	close(fd);
}

void parsing(char *path, map *data)
{
	create_map(path, data);
	count_chars_in_map(data);
	data->column = ft_strlen(data->map[0]);
	check_is_map_rectangle(data);
	check_the_wall_around_map(data);
	validate_if_map_is_playable(data);
	flood(data);
}