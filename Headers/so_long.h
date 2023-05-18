
#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../MLX42/include/MLX42/MLX42.h"

#define PLAYER "./Assets_map/1_Sprites/Player.png"
#define EXIT "./Assets_map/1_Sprites/Bed_Exit.png"
#define WALL "./Assets_map/1_Sprites/Wall.png"
#define FLOOR "./Assets_map/1_Sprites/Floor.png"
#define TEDDY "./Assets_map/1_Sprites/Teddy.png"

#define WIDTH 520
#define HEIGHT 520

typedef struct window
{
    int index_x;
    int index_y;
    int window_width;
    int window_height;
} window;

typedef struct texture{
    mlx_texture_t *wall;
    mlx_texture_t *teddy;
    mlx_texture_t *floor;
    mlx_texture_t *player;
    mlx_texture_t *exit;

} t_texture;

typedef struct map
{
    mlx_t *mlx;
    mlx_image_t *img;
    char **map;
    int width;
    int height;
    int lines_count;
    size_t line_length;
    int number_of_player;
    int number_of_teddy;
    int number_of_exit;
    int number_of_teddy_collected;
    int x;
    int y;
    int steps_count;
    int x_position_player;
    int y_position_player;
    t_texture texture;

} map;


/*map parsing*/
int check_extension_map_file(char *map_file_name);
int check_chars_in_map(map *data);
int check_is_map_rectangle(map *data);
void   initialize_map(map *data);
void    initialize_player(map *data);

#endif