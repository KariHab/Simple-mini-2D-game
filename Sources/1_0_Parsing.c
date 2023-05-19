

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
// int check_chars_in_map(map *data)
// {
//     printf("in check char %d %d %ld\n", data->column, data->row, data->line_length);
//     while (data->map[data->row])
//     {
//         printf("Entered\n");
//         while (data->map[data->row][data->column])
//         {
//             printf("entered 2nd loop\n");
//             if (data->map[data->row][data->column] == 'P')
//                 data->number_of_player++;
//             else if (data->map[data->row][data->column] == 'C')
//                 data->number_of_teddy++;
//             else if (data->map[data->row][data->column] == 'E')
//                 data->number_of_exit++;
//             // if(!(data->map[data->row][data->column] == 'C' || data->map[data->row][data->column] == 'P' ||data->map[data->row][data->column] == 'E'))
//             //     return(-1);
//             data->column++;
//         }
//         data->column = 0;
//         data->row++;
//     }
//     if (!data->number_of_exit|| !data->number_of_player|| !data->number_of_teddy)
//         return (-1);
//     else
//         return (0);
// }

void ft_count(map *data, int x, int y)
{
    if (data->map[y][x] == 'P')
    {
        data->number_of_player++;
        data->x_position_player = x;
        data->y_position_player = y;
    }
    else if (data->map[y][x] == 'E')
        data->number_of_exit++;
    else if (data->map[y][x] == 'C')
        data->number_of_teddy++;
    // else if (data->map[y][x] == '1' || data->map[y][x] == '0')
    // 	;
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
            ft_count(data, x, y);
            x++;
        }
        y++;
    }
}

/*we need to check if we have wall all around the map*/
void check_the_wall_around_map(map *data)
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
                data->wall = 1;
            x++;
        }
        y++;
    }
}
/*we need to make sure the map is rectangle*/
void check_is_map_rectangle(map *data)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (data->map[y])
    {
        x = 0;
        while (data->map[y][x])
            x++;
        if (x != data->column)
            data->rectangle = 1;
        y++;
    }
    // 
}

/*check the whole map to validate it*/
int validate_if_map_is_playable(map *data)
{
    // if (check_chars_in_map(data) == -1)
    //     printf("ERROR.Check the chars of your map\n");
    if (data->number_of_exit != 1)
        printf("ERROR.The map should have an exit\n");
    if (data->number_of_player != 1)
        printf("ERROR.This is a solo game\n");
    if (data->rectangle == 1)
        printf("ERROR.The map should be rectangle\n");
    if (data->wall == 1)
        printf("ERROR.This is not an open world map\n");
    return (0);
}
// so if all the previous ft are returning 0 return ok