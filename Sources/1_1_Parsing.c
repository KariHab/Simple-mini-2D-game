

#include "../Headers/so_long.h"

int get_map_lines(char *path, map *data)
{
    char *str;
    int fd;
	int line_count;

	line_count = 0;
    fd= open(path, O_RDONLY);
	if (fd < 0)
		printf("ERROR: open failed\n");
    else
    {
        str = get_next_line(fd);
        while(str != NULL)
		{
			line_count++;
			free(str);
			str = get_next_line(fd);
			data->row++;
		}
		close(fd);
    }
    return(line_count);
}
void	put_input_in_map(int row, int column, int i, map *data)
{
	char	*line;

	line = get_next_line(data->fd);
	while (line != NULL)
	{
		data->map[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!data->map[row])
			return (ft_freeall(data->map));
		while (line[i] != '\0')
			data->map[row][column++] = line[i++];
		data->map[row++][column] = '\0';
		column = 0;
		i = 0;
		free(line);
		line = get_next_line(data->fd);
	}
	data->map[row] = NULL;
}

void create_map(char *path, map *data)
{
	int		row;
	int		i;
	size_t	column;
	int fd;

	i = 0;
	row = 0;
	column = 0;
	data->line_count =get_map_lines(path, data);
	data->map = ft_calloc(data->row + 1, sizeof(char *));
	if (!data->map)
		return ;
	data->fd = open (path, O_RDONLY);
	while (fd > 2)
	{
		put_input_in_map(row,column, i, data);
		close(data->fd);
	}
	// if (fd < 3)
	// 	exit (printf("ERROR\nWrong file.\n"));
}

void	parsing(char *path, map *data)
{
	create_map(path, data);
	check_chars_in_map(data);
	data->column = ft_strlen(data->map[0]);
	printf("%d %d", data->column, data->row);
	check_is_map_rectangle(data);
	check_the_wall_around_map(data);
	validate_if_map_is_playable(data);
	// ft_flood(ms);
}