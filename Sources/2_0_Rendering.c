

#include "../Headers/so_long.h"

void remove_texture(map *data)
{
	mlx_delete_texture(data->texture.wall);
	mlx_delete_texture(data->texture.floor);
	mlx_delete_texture(data->texture.exit);
	mlx_delete_texture(data->texture.player);
	mlx_delete_texture(data->texture.teddy);
}

void load_texture(map *data)
{
	data->texture.wall = mlx_load_png(WALL);
	data->texture.teddy = mlx_load_png(TEDDY);
	data->texture.player = mlx_load_png(PLAYER);
	data->texture.floor = mlx_load_png(FLOOR);
	data->texture.exit = mlx_load_png(EXIT);
}

void create_the_map_render(void *param)
{
	int x;
	int y;
	map *data;

	data = param;
	y = 0;
	remove_image(data);
	data->old_version = data->image;
	create_image(data);
	// ft_print_moves_and_collect(ms);
	while (y < data->row)
	{
		x = 0;
		while (x < data->column)
		{
			data->img = load_image(data->map[y][x], data);
			mlx_image_to_window(data->mlx, data->img, (x * 32), (y * 32));
			x++;
		}
		y++;
	}
}

void render(map *data)
{
	data->mlx = mlx_init(data->column * 32, data->row * 32, "Grab your teddy and go to sleep!", false);
	if (!data->mlx)
		exit(EXIT_FAILURE);
	load_texture(data);
	// printf("%d %d\n", data->x_position_player, data->y_position_player);
	create_the_map_render(data);
	mlx_loop_hook(data->mlx, &create_the_map_render, data);
	mlx_key_hook(data->mlx, &key_hook_handler, data);
	// printf("%d %d\n", data->x_position_player, data->y_position_player);
	mlx_loop(data->mlx);
	remove_texture(data);
}