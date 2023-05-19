

#include "../Headers/so_long.h"

/*we need to check the file extension is .ber*/
int check_extension_map_file(char *map_file_name)
{
    size_t name_file_len;

    name_file_len = ft_strlen(map_file_name);
    if ((map_file_name[name_file_len - 4] != '.' && map_file_name[name_file_len - 3] != 'b' && map_file_name[name_file_len - 2] != 'e' && map_file_name[name_file_len - 1] != 'r'))
        return (-1);
    else
        return (0);
}

/*we need to check if we have C E P 0 1 in the map*/
// ft_count
int check_chars_in_map(map *data)
{
    while (data->map[data->row])
    {
        printf("Entered\n");
        while (data->map[data->row][data->column])
        {
            printf("entered 2nd loop\n");
            if (data->map[data->row][data->column] == 'P')
                data->number_of_player++;
            else if (data->map[data->row][data->column] == 'C')
                data->number_of_teddy++;
            else if (data->map[data->row][data->column] == 'E')
                data->number_of_exit++;
            // if(!(data->map[data->row][data->column] == 'C' || data->map[data->row][data->column] == 'P' ||data->map[data->row][data->column] == 'E'))
            //     return(-1);
            data->column++;
        }
        data->column = 0;
        data->row++;
    }
    if (data->number_of_exit == 0 || data->number_of_player == 0 || data->number_of_teddy == 0)
        return (-1);
    else
        return (0);
}
/*we need to check if we have wall all around the map*/
int check_the_wall_around_map(map *data)
{
    int x;
    int y;

    y = 0;
    while (data->map[y])
    {
        x = 0;
        while (data->map[y][x])
        {
            if (data->map[0][x] != '1' || data->map[y][0] != '1' || data->map[data->row - 1][x] != '1' || data->map[y][data->column - 1] != '1')
                return(-1);
            x++;
        }
        y++;
    }
    return(0);
}
/*we need to make sure the map is rectangle*/
int check_is_map_rectangle(map *data)
{
    int x;
    size_t y;

    x = 0;
    y = 0;
    data->line_length = ft_strlen(data->map[x]) - 1;
    while (data->map[x])
    {
        while (data->map[x][y] && data->map[x][y] != '\n')
            y++;
        if (y != data->line_length)
            return (-1);
        y = 0;
        x++;
    }
    return (0);
}

/*check the whole map to validate it*/
int validate_if_map_is_playable(map *data)
{
    // if (check_chars_in_map(data) == -1)
    //     printf("ERROR\nMan, did you understand the rules of this game?\nCheck the chars of your map\n");
    if (check_is_map_rectangle(data) == -1)
        printf("ERROR\nThe map should be rectangle\n");
    if (check_the_wall_around_map(data) == -1)
        printf("ERROR\nThis is not an open world map\n");
    return(0);
}
// so if all the previous ft are returning 0 return ok