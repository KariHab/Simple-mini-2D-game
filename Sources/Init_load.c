/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Init_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:41:01 by khabbout          #+#    #+#             */
/*   Updated: 2023/06/06 12:41:01 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void initialize_map(t_map *data)
{
    data->row = 0;
    data->column = 0;
    data->number_of_exit = 0;
    data->number_of_player = 0;
    data->number_of_teddy = 0;
    data->player.steps_count = 0;
    data->map = NULL;
    data->player.x_pos_player = 0;
    data->player.y_pos_player = 0;
    data->wall = 0;
    data->rectangle = 0;
    data->exit = 0;
    data->wrong_char = 0;
    data->collected = 0;
    data->can_exit = 0;
    data->flood.exit = 0;
    data->flood.teddy_to_collect = 0;
    data->flood.map_copy = NULL;
}

void initialize_player(t_map *data)
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
                data->player.y_pos_player = i;
                data->player.x_pos_player = j;
            }
            j++;
        }
        j = 0;
        i++;
    }
}
