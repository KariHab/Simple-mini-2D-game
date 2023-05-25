/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_1_Rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:34:33 by khabbout          #+#    #+#             */
/*   Updated: 2023/05/25 11:34:33 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "../Headers/so_long.h"

mlx_image_t *load_image(char c, map *data)
{
    if (c == '1')
        return (data->image.wall);
    if (c == '0')
        return (data->image.floor);
    if (c == 'P')
        return (data->image.player);
    if (c == 'E')
        return (data->image.exit);
    if (c == 'C')
        return (data->image.teddy);
    return (0);
}

void create_image(map *data)
{
    data->image.wall = mlx_texture_to_image(data->mlx, data->texture.wall);
    data->image.floor = mlx_texture_to_image(data->mlx, data->texture.floor);
    data->image.player = mlx_texture_to_image(data->mlx, data->texture.player);
    data->image.exit = mlx_texture_to_image(data->mlx, data->texture.exit);
    data->image.teddy = mlx_texture_to_image(data->mlx, data->texture.teddy);
}

void remove_image(map *data)
{
    mlx_delete_image(data->mlx, data->old_version.wall);
    mlx_delete_image(data->mlx, data->old_version.player);
    mlx_delete_image(data->mlx, data->old_version.exit);
    mlx_delete_image(data->mlx, data->old_version.teddy);
    mlx_delete_image(data->mlx, data->old_version.floor);
}