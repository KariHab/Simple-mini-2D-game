/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:35:02 by khabbout          #+#    #+#             */
/*   Updated: 2023/05/25 11:35:02 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "Sources/libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

/*sprites*/
#define PLAYER "./Assets_map/Sprites/Player.png"
#define EXIT "./Assets_map/Sprites/Bed_Exit.png"
#define WALL "./Assets_map/Sprites/Wall.png"
#define FLOOR "./Assets_map/Sprites/Floor.png"
#define TEDDY "./Assets_map/Sprites/Teddy.png"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 150
#endif

/*colors*/
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define WHITE "\033[0;37m"
#define CYAN "\033[0;36m"
#define PURPLE "\033[0;35m"

typedef struct texture
{
    mlx_texture_t *wall;
    mlx_texture_t *teddy;
    mlx_texture_t *floor;
    mlx_texture_t *player;
    mlx_texture_t *exit;

} t_texture;

typedef struct image
{
    mlx_image_t *wall;
    mlx_image_t *floor;
    mlx_image_t *player;
    mlx_image_t *exit;
    mlx_image_t *teddy;

} t_image;

typedef struct player
{
    int steps_count;
    int x_pos_player;
    int y_pos_player;
} t_player;

typedef struct flood
{
    int teddy_to_collect;
    int exit;
    char **map_copy;
} t_flood;

typedef struct map
{
    mlx_t *mlx;
    mlx_image_t *img;
    char **map;
    int number_of_player;
    int number_of_teddy;
    int number_of_exit;
    int row;
    int column;
    int rectangle;
    int wall;
    int exit;
    int collected;
    int can_exit;
    int wrong_char;
    int valid;
    t_texture texture;
    t_image image;
    t_image old_version;
    t_player player;
    t_flood flood;

} t_map;

/*initialization*/
void initialize_map(t_map *data);
void initialize_player(t_map *data);

/*map parsing*/
int check_extension_map_file(char *map_file_name);
void count_chars_in_map(t_map *data);
void check_the_wall_around_map(t_map *data);
void check_is_map_rectangle(t_map *data);
int validate_if_map_is_playable(t_map *data);
t_map *get_map_lines(char *path, t_map *dataa);
void create_map(char *path, t_map *data);
void parsing(char *path, t_map *data);
void path_checker(t_map *data, int x, int y);
void map_copy(t_map *data);
void flood(t_map *data);

/*rendering*/
mlx_image_t *load_image(char c, t_map *data);
void create_image(t_map *data);
void remove_image(t_map *data);
void remove_texture(t_map *data);
void load_texture(t_map *data);
void create_the_map_render(void *param);
void render(t_map *data);

/*event handle*/
void key_hook_handler(mlx_key_data_t keydata, void *param);
void move_player(t_map *data, char direction);
int check_tile_not_wall(char c);
int check_next_tile(t_map *data, char direction, char tile);
void end_of_game(t_map *data);
void print_moves(t_map *data);
void print_teddy(t_map *data);
void free_all(char **tab);

#endif