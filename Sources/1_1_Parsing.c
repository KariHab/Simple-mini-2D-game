

#include "../Headers/so_long.h"

map *get_map_lines(char *path, map *data)
{
	char *str;
	int fd;
	// int line_count;

	// line_count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		printf("ERROR: open failed\n");
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
// void	put_input_in_map(int row, int column, int i, map *data)
// {
// 	char	*line;

// 	line = get_next_line(data->fd);
// 	while (line != NULL)
// 	{
// 		data->map[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
// 		if (!data->map[row])
// 			return (ft_freeall(data->map));
// 		while (line[i] != '\0')
// 			data->map[row][column++] = line[i++];
// 		data->map[row++][column] = '\0';
// 		column = 0;
// 		i = 0;
// 		free(line);
// 		line = get_next_line(data->fd);
// 	}
// 	data->map[row] = NULL;
// }

void create_map(char *path, map *data)
{

	int i;
	// int fd;

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
	// check_chars_in_map(data);
	data->column = ft_strlen(data->map[0]);
	check_is_map_rectangle(data);
	check_the_wall_around_map(data);
	validate_if_map_is_playable(data);
	// ft_flood(ms);
}