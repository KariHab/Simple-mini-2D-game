/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rendering_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:41:20 by khabbout          #+#    #+#             */
/*   Updated: 2023/06/06 12:41:20 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	remove_texture(t_map *data)
{
	mlx_delete_texture(data->texture.wall);
	mlx_delete_texture(data->texture.floor);
	mlx_delete_texture(data->texture.exit);
	mlx_delete_texture(data->texture.player);
	mlx_delete_texture(data->texture.teddy);
}

void	load_texture(t_map *data)
{
	data->texture.wall = mlx_load_png(WALL);
	data->texture.teddy = mlx_load_png(TEDDY);
	data->texture.player = mlx_load_png(PLAYER);
	data->texture.floor = mlx_load_png(FLOOR);
	data->texture.exit = mlx_load_png(EXIT);
}

void	create_image(t_map *data)
{
	data->image.wall = mlx_texture_to_image(data->mlx, data->texture.wall);
	data->image.floor = mlx_texture_to_image(data->mlx, data->texture.floor);
	data->image.player = mlx_texture_to_image(data->mlx, data->texture.player);
	data->image.exit = mlx_texture_to_image(data->mlx, data->texture.exit);
	data->image.teddy = mlx_texture_to_image(data->mlx, data->texture.teddy);
}

void	remove_image(t_map *data)
{
	mlx_delete_image(data->mlx, data->old_version.wall);
	mlx_delete_image(data->mlx, data->old_version.player);
	mlx_delete_image(data->mlx, data->old_version.exit);
	mlx_delete_image(data->mlx, data->old_version.teddy);
	mlx_delete_image(data->mlx, data->old_version.floor);
}
