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

void flood(map *data)
{
    if (data->valid == 0)
    {
        ft_flood_cpy(data);
        // printf("%d %d\n", data->flood.collect, data->number_of_teddy);
        printf("exit mesured%d exit real%d\n", data->flood.exit, data->number_of_exit);
        flood_fill(data->y_pos_player, data->x_pos_player, data);
        // printf("after%d %d\n", data->flood.collect, data->number_of_teddy);
        printf("after exit mesured %d exit real%d\n", data->flood.exit, data->number_of_exit);
        if (data->number_of_teddy != data->flood.collect)
            exit(ft_printf("Error\nSome collectibles can't be reached.\n"));
        if (data->flood.exit != data->number_of_exit)
            exit(ft_printf("Error\nThe exit can't be reached.\n"));
    }
    free_all(data->flood.map);
}

void ft_flood_cpy(map *data)
{
    int i;

    i = 0;
    data->flood.map = ft_calloc(data->row + 1, sizeof(char *));
    while (data->map[i])
    {
        data->flood.map[i] = ft_calloc(data->column + 1, sizeof(char));
        ft_memcpy(data->flood.map[i], data->map[i], data->column + 1);
        i++;
    }
}

void flood_fill(int x, int y, map *data)
{
    if (x < 0 || x > data->column - 1 || y < 0 || y > data->row - 1)
        return;
    if (data->flood.map[y][x] == 'Z' || data->flood.map[y][x] == '1')
		return ;
    if (data->flood.map[y][x] == 'C')
        data->flood.collect++;
    if (data->flood.map[y][x] == 'E')
        data->exit++;
    data->flood.map[y][x] = 'Z';
    flood_fill(x + 1, y, data);
    flood_fill(x - 1, y, data);
    flood_fill(x, y + 1, data);
    flood_fill(x, y - 1, data);
}

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
