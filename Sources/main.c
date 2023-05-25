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
        ft_printf("Invalid number of args\n");
    if (ac == 2)
    {

        if (check_extension_map_file(av[1]) == -1)
            ft_printf("Format file is not .ber\n");
        initialize_map(&data);
        parsing(av[1], &data);
        initialize_player(&data);
        ft_printf("Teddy  to collect %d\n", data.number_of_teddy);
        ft_printf("Teddy collected %d\n", data.number_of_teddy_collected);
        render(&data);
        mlx_terminate(data.mlx);
        free_all(data.map);
    }
    return (0);
}