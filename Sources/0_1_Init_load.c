
#include "../Headers/so_long.h"

void initialize_map(map *data)
{
    data->row = 0;
    data->column = 0;
    data->number_of_exit = 0;
    data->number_of_player = 0;
    data->number_of_teddy = 0;
    data->number_of_teddy_collected = 0;
    data->steps_count = 0;
    data->line_length = 0;
    data->map = NULL;
    data->x_position_player = 0;
    data->y_position_player = 0;
}

void initialize_player(map *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (data->map[i])
    {
        while (data->map[i][j])
        {
            if (data->map[i][j] == 'P')
            {
                data->x_position_player = i;
                data->y_position_player = j;
            }
            j++;
        }
        j = 0;
        i++;
    }
}
