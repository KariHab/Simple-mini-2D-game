/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:41:13 by khabbout          #+#    #+#             */
/*   Updated: 2023/06/06 12:41:13 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_map	*get_map_lines(char *path, t_map *data)
{
	char	*str;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit(ft_printf(RED "ERROR.\nOpen failed.\n" WHITE));
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
	close (fd);
	return (data);
}

void	create_map(char *path, t_map *data)
{
	int	i;
	int	fd;

	i = 0;
	get_map_lines(path, data);
	data->map = ft_calloc(sizeof(char *), (data->row + 1));
	if (!data->map)
		return ;
	fd = open(path, O_RDONLY);
	while (fd > 0)
	{
		data->map[i] = get_next_line(fd);
		if (!data->map[i])
			break ;
		if (data->map[i][0] == '\n')
			data->rectangle = 1;
		if (data->map[i][ft_strlen(data->map[i]) - 1] == '\n')
			data->map[i][ft_strlen(data->map[i]) - 1] = '\0';
		i++;
	}
	if (fd < 0)
		exit(ft_printf(RED "ERROR.\nOpen failed.\n" WHITE));
	close (fd);
}

void	count_chars_in_map(t_map *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
				data->number_of_player++;
			else if (data->map[i][j] == 'C')
				data->number_of_teddy++;
			else if (data->map[i][j] == 'E')
				data->number_of_exit++;
			else if (!(data->map[i][j] == '0' || data->map[i][j] == '1'
				|| data->map[i][j] == 'P' || data->map[i][j] == 'C'
				|| data->map[i][j] == 'E'))
				data->wrong_char++;
			j++;
		}
		j = 0;
		i++;
	}
}

void	check_is_map_rectangle(t_map *data)
{
	int	x;
	int	y;

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

void	check_the_wall_around_map(t_map *data)
{
	int	x;
	int	y;

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
