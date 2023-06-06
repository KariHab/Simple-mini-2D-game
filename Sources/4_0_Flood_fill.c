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

#include "../so_long.h"

void flood(map *data)
{
    ft_flood_cpy(data);
    flood_fill(data->y_pos_player, data->x_pos_player, data);
    if (data->flood.exit != data->number_of_exit)
        exit(ft_printf(RED "ERROR.\nThe exit can't be reached.\n" WHITE));
    if (data->number_of_teddy != data->flood.collect)
        exit(ft_printf(RED "ERROR.\nSome teddys can't be reached.\n" WHITE));
    free_all(data->flood.map);
}

void ft_flood_cpy(map *data)
{
    int i;

    i = 0;
    data->flood.map = ft_calloc((data->row + 1), sizeof(char *));
    if (!data->flood.map)
        exit(1);
    while (data->map[i])
    {
        data->flood.map[i] = ft_calloc((data->column + 1), sizeof(char));
        if (!data->flood.map[i])
        {
            free_all(data->flood.map);
            exit(1);
        }
        ft_memcpy(data->flood.map[i], data->map[i], data->column + 1);
        i++;
    }
}

void flood_fill(int y, int x, map *data)
{
    if (x < 0 || x > data->column - 1 || y < 0 || y > data->row - 1)
        return;
    if (data->flood.map[y][x] == 'Z' || data->flood.map[y][x] == '1')
        return;
    if (data->flood.map[y][x] == 'C')
        data->flood.collect++;
    if (data->flood.map[y][x] == 'E')
        data->flood.exit++;
    data->flood.map[y][x] = 'Z';
    flood_fill(y + 1, x, data);
    flood_fill(y - 1, x, data);
    flood_fill(y, x - 1, data);
    flood_fill(y, x + 1, data);
    printf("%c", data->flood.map[y][x]);
}
