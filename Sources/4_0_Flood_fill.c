/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_0_Flood_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:34:45 by khabbout          #+#    #+#             */
/*   Updated: 2023/05/25 11:34:45 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../Headers/so_long.h"

// void flood_fill(int x, int y, map *data)
// {
//     if (x < 0 || x > data->column - 1 || y < 0 || y > data->row - 1)
//         return;
//     if (data->map[y][x] == '1')
//         return;
//     if (data->map[y][x] == 'C')
//         data->collect++;
//     if (data->map[y][x] == 'E')
//         data->exit++;
//     data->map[y][x] == 'Z';
//     flood_fill(x + 1, y, data);
//     flood_fill(x - 1, y, data);
//     flood_fill(x, y + 1, data);
//     flood_fill(x, y - 1, data);
// }

// int check_tile(map *data, char direction, char tile)

// {
//     if ((direction == 'w' && data->map[data->y_position_player - 1][data->x_position_player] == tile) 
//     || (direction == 's' && data->map[data->y_position_player + 1][data->x_position_player] == tile) 
//     || (direction == 'a' && data->map[data->y_position_player][data->x_position_player - 1] == tile) 
//     || (direction == 'd' && data->map[data->y_position_player][data->x_position_player + 1] == tile))
//         return (0);
//     else
//         return (-1);
// }
