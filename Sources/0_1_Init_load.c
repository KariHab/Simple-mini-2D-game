/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_1_Init_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:34:11 by khabbout          #+#    #+#             */
/*   Updated: 2023/05/25 11:34:11 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void initialize_map(map *data)
{
    data->row = 0;
    data->column = 0;
    data->number_of_exit = 0;
    data->number_of_player = 0;
    data->number_of_teddy = 0;
    data->steps_count = 0;
    data->line_length = 0;
    data->map = NULL;
    data->x_pos_player = 0;
    data->y_pos_player = 0;
    data->wall = 0;
    data->rectangle = 0;
    data->exit = 0;
    data->wrong_char = 0;
    data->image.collected_nbr = 0;
    data->image.move_nbr = 0;
    data->image.move = 0;
    data->collected = 0;
    data->can_exit = 0;
    data->flood.collect = 0;
    data->flood.exit = 0;
    data->flood.map = NULL;
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
                data->y_pos_player = i;
                data->x_pos_player = j;
            }
            j++;
        }
        j = 0;
        i++;
    }
}
