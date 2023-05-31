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
		exit(ft_printf("ERROR.\nThe map should have an exit\n"));
	if (data->number_of_player != 1)
		exit(ft_printf("ERROR.\nThis is a solo game\n"));
	if (data->rectangle == 1)
		exit(ft_printf("ERROR.\nThe map should be rectangle\n"));
	if (data->wall == 1)
		exit(ft_printf("ERROR.\nThis is not an open world map\n"));
	if (data->number_of_teddy < 1)
		exit(ft_printf("ERROR.\nYou should have one teddy in your room!\n"));
	if (data->wrong_char > 1)
		exit(ft_printf("ERROR.\nYou put a wrong char in the map\n"));
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
	int fd;

	i = 0;
	fd = 0;
	get_map_lines(path, data);
	data->map = ft_calloc(sizeof(char *), data->row + 1);
	if (!data->map)
		return;
	fd = open(path, O_RDONLY);
	while (fd > 2)
	{
		data->map[i] = get_next_line(fd);
		if (data->map[i] == NULL)
			break;
		if (data->map[i][0] == '\n')
			data->rectangle = 1;
		if (data->map[i][ft_strlen(data->map[i]) - 1] == '\n')
			data->map[i][ft_strlen(data->map[i]) - 1] = '\0';
		i++;
	}
	close(fd);
}

void parsing(char *path, map *data)
{
	create_map(path, data);
	// ft_printf("Rect: %d\n", data->rectangle);
	count_objects(data);
	data->column = ft_strlen(data->map[0]);
	// ft_printf("column row %d %d\n", data->column, data->row);
	printf("exit is%d\n", data->number_of_exit);
	check_is_map_rectangle(data);
	// ft_printf("Rect: %d\n", data->rectangle);
	check_the_wall_around_map(data);
	validate_if_map_is_playable(data);
	// ft_printf("%d", data->wrong_char);
	flood(data);
}