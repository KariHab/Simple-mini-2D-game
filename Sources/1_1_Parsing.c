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

#include "../Headers/so_long.h"

int validate_if_map_is_playable(map *data)
{
	if (data->number_of_exit != 1)
	{
		ft_printf("ERROR.The map should have an exit\n");
		return (1);
	}
	if (data->number_of_player != 1)
	{
		ft_printf("ERROR.This is a solo game\n");
		return (1);
	}
	if (data->rectangle == 1)
	{
		ft_printf("ERROR.The map should be rectangle\n");
		return (1);
	}
	if (data->wall == 1)
	{
		ft_printf("ERROR.This is not an open world map\n");
		return (1);
	}
	if (data->wrong_char == 1)
	{
		ft_printf("ERROR.You put a wrong char in the map\n");
		return (1);
	}

	return (0);
}

map *get_map_lines(char *path, map *data)
{
	char *str;
	int fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_printf("ERROR: open failed\n");
	else
	{
		str = get_next_line(fd);
		while (str != NULL)
		{
			free(str);
			str = get_next_line(fd);
			data->row++;
		}
		close(fd);
	}
	return (data);
}

void create_map(char *path, map *data)
{
	int i;

	i = 0;
	get_map_lines(path, data);
	data->map = ft_calloc(data->row + 1, sizeof(char *));
	if (!data->map)
		return;
	data->fd = open(path, O_RDONLY);
	while (data->fd > 2)
	{
		data->map[i] = get_next_line(data->fd);
		if (data->map[i] == NULL)
			break;
		if (data->map[i][0] == '\n')
			data->rectangle = 1;
		if (data->map[i][ft_strlen(data->map[i]) - 1] == '\n')
			data->map[i][ft_strlen(data->map[i]) - 1] = '\0';
		i++;
	}
	close(data->fd);
}

void parsing(char *path, map *data)
{
	create_map(path, data);
	count_objects(data);
	data->column = ft_strlen(data->map[0]);
	check_is_map_rectangle(data);
	check_the_wall_around_map(data);
	validate_if_map_is_playable(data);
	// {
	// 	free_all(data->map);
	// 	return;
	// }

	// flood(data);
}