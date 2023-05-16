
#ifndef SO_LONG_H
#define SO_LONG_H


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../MLX42/include/MLX42/MLX42.h"


#define WIDTH 520
#define HEIGHT 520

typedef struct window{
    int index_x;
    int index_y;
    int width;
    int height;
} window;

typedef struct image{
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
} map;


/*map parsing*/
int check_extension_map_file(char *map_file_name);

#endif