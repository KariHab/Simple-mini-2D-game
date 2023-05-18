

#include "../Headers/so_long.h"

// /*we need to check if we have C E P 0 1 in the map*/
int check_chars_in_map(map *data)
{
    while(data->map[data->x])
    {
        while(data->map[data->x][data->y])
        {
            if(data->map[data->x][data->y] == 'P')
                data->number_of_player++;
            else if(data->map[data->x][data->y] == 'C')
                data->number_of_teddy++;
            else if(data->map[data->x][data->y] == 'E')
                data->number_of_exit++;
            data->y++;
        }
        data->y = 0;
        data->x++;
    }
    if(data->number_of_exit == 0 || data->number_of_player == 0 || data->number_of_teddy == 0)
        return(-1);
    else 
        return(0);
}
/*we need to check if we have wall all around the map*/

/*we need to make sure the map is rectangle*/
int check_is_map_rectangle(map *data)
{
    int x; 
    size_t y; 

    x = 0;
    y = 0;
    data->line_length = strlen(data->map[x]) - 1;
    while(data->map[x])
    {
        while(data->map[x][y] && data->map[x][y] != '\n')
            y++;
        if(y != data->line_length)
            return(-1);
        y = 0;
        x++;
    }
    return(0);
}

/*check the whole map to validate it*/
//so if all the previous ft are returning 0 return ok