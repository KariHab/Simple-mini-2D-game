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

// void	flood(map *data)
// {
// 	if (data->valid == 0)
// 	{
// 		ft_flood_cpy(data);
// 		flood_fill(data->y_pos_player, data->x_pos_player, data);
// 		if (data->number_of_teddy != data->flood.collect)
// 			exit (ft_printf("Error\nSome collectibles can't be reached.\n"));
// 		if (ms->flood.exit != ms->e)
// 			exit (ft_printf("Error\nThe exit can't be reached.\n"));
// 	}
// 	free_all(ms->flood.map);
// }

// void	ft_flood_cpy(t_map *ms)
// {
// 	int	i;

// 	i = 0;
// 	ms->flood.map = ft_calloc(ms->row + 1, sizeof(char *));
// 	while (ms->map[i])
// 	{
// 		ms->flood.map[i] = ft_calloc(ms->column + 1, sizeof(char));
// 		ft_memcpy(ms->flood.map[i], ms->map[i], ms->column + 1);
// 		i++;
// 	}
// }
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
