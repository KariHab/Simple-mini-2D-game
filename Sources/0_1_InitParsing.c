/*read the map
init map
init player*/
#include "../Headers/so_long.h"


void   initialize_map(map *data)
{
    data->x = 0;
    data->y = 0;
    data->number_of_exit = 0;
    data->number_of_player = 0;
    data->number_of_teddy = 0;
    data->number_of_teddy_collected = 0;
    data->steps_count = 0;
}

void    initialize_player(map *data)
{
    int x; 
    int y;

    x = 0;
    y = 0;
    while(data->map[x])
    {
        while(data->map[x][y])
        {
            if (data->map[x][y]== 'P')
            {
                data->x_position_player = x;
                data->y_position_player = y;
            }
            y++;
        }
        y = 0;
        x++;
    }
}

/*we need to check the file extension is .ber*/
int check_extension_map_file(char *map_file_name)
{
    size_t name_file_len;

    name_file_len = strlen(map_file_name);
    if((map_file_name[name_file_len - 4] != '.' && map_file_name[name_file_len - 3] != 'b' && map_file_name[name_file_len -2] != 'e' && map_file_name[name_file_len - 1] != 'r'))
        return (-1);
    else
        return (0);
}