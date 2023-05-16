
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

typedef struct window{
    int index_x;
    int index_y;
    int window_width;
    int window_height;
} window;

typedef struct image{
    void *mlx_img;
    int width;
    int height;
    char *wall;
    char *teddy;
    char *ground;
    char *player;
    char *exit;
}image;

typedef struct map{
    int lines_count;
    size_t line_length;
    int number_of_player;
    int number_of_teddy;
    int number_of_exit;
    int number_of_teddy_collected;
    int index_1;
    int index_2;
} map;


/*map parsing*/
int check_extension_map_file(char *map_file_name);

#endif