

#include "../Headers/so_long.h"
/*handlers
moves*/

void	key_hook_handler(mlx_key_data_t keydata, void *param)
{
	map *data;
//need to check tiles here
	data = param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP))
			data->y_position_player--;
		if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN))
			data->y_position_player++;
		if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT))
			data->x_position_player++;
		if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT))
			data->x_position_player--;
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(data->mlx);
	}
}
