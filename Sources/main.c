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

#include "../so_long.h"

int main(int ac, char **av)
{
    map data;

    if (ac != 2)
        ft_printf(RED"Invalid number of args\n"WHITE);
    if (ac == 2)
    {
        if (check_extension_map_file(av[1]) == -1)
            exit(ft_printf(RED"Format file is not .ber\n"WHITE));
        initialize_map(&data);
        parsing(av[1], &data);
        initialize_player(&data);
        render(&data);
        mlx_terminate(data.mlx);
        free_all(data.map);
    }
    return (0);
}