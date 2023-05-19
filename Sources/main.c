/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:00:19 by khabbout          #+#    #+#             */
/*   Updated: 2023/05/15 21:00:19 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/so_long.h"

int main(int ac, char **av)
{
    map data;

    if (ac != 2)
        printf("Invalid number of args\n");
    if (ac == 2)
    {
        if (check_extension_map_file(av[1]) == -1)
            printf("Format file is not .ber\n");
        // data = malloc(sizeof(*data));
        // if (!data)
        //     return (0);

        // create_map(av[1], &data);
        // printf("map created\n");
        // check_chars_in_map(&data);
        // printf("check char ok\n");
        // check_is_map_rectangle(&data);
        // printf("rect checked\n");
        // check_the_wall_around_map(&data);
        // printf("wall checked\n");
        // validate_if_map_is_playable(&data);
        // printf("validate ok\n");
        initialize_map(&data);
        printf("map init ok\n");
        parsing(av[1], &data);
        printf("ok parsing\n");
        initialize_player(&data);
        printf("player init ok\n");

        /*OK TILL HERE!!!*/
        // data.mlx = mlx_init(500, 500, "truc", true);
        // printf("mlx connected\n");
        render(&data);
        printf("\nok render\n");
        // mlx_terminate(data.mlx);
        // ft_freeall(data.map);
        // free_data(&data);
    }
    return (0);
}