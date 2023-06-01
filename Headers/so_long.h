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
#include "../Sources/libft/libft.h"
#include "../MLX42/include/MLX42/MLX42.h"

#define PLAYER "./Assets_map/1_Sprites/Player.png"
#define EXIT "./Assets_map/1_Sprites/Bed_Exit.png"
#define WALL "./Assets_map/1_Sprites/Wall.png"
#define FLOOR "./Assets_map/1_Sprites/Floor.png"
#define TEDDY "./Assets_map/1_Sprites/Teddy.png"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 128
#endif

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
    mlx_image_t *move_nbr;
    mlx_image_t *collected_nbr;
    mlx_image_t *move;

} t_image;

typedef struct flood
{
    char **map;
    int collect;
    int exit;
} t_flood;

typedef struct map
{
    mlx_t *mlx;
    mlx_image_t *img;
    char **map;
    size_t line_length;
    int fd;
    int number_of_player;
    int number_of_teddy;
    int number_of_exit;
    int row;
    int column;
    int rectangle;
    int wall;
    int steps_count;
    int x_pos_player;
    int y_pos_player;
    int exit;
    int collected;
    int can_exit;
    int wrong_char;
    t_texture texture;
    t_image image;
    t_image old_version;
    t_flood flood;

} map;

/*map parsing*/
int check_extension_map_file(char *map_file_name);
int check_chars_in_map(map *data);
void check_is_map_rectangle(map *data);
void initialize_map(map *data);
void initialize_player(map *data);
void check_the_wall_around_map(map *data);
int validate_if_map_is_playable(map *data);
mlx_image_t *load_image(char c, map *data);
void create_image(map *data);
void remove_image(map *data);
void remove_texture(map *data);
void load_texture(map *data);
void create_the_map_render(void *param);
void render(map *data);
void parsing(char *path, map *data);
void create_map(char *path, map *data);
map *get_map_lines(char *path, map *data);
void free_all(char **tab);
void count_chars(map *data, int x, int y);
void count_objects(map *data);
void key_hook_handler(mlx_key_data_t keydata, void *param);
void move_player(map *data, char direction);
void print_collected_and_moves(map *data);
void print_moves(map *data);
void print_teddy_collected(map *data);
void flood(map *data);
void flood_fill(int x, int y, map *data);
void ft_flood_cpy(map *data);
int check_tile(char c);
void end_of_game(map *data);

#endif