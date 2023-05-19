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
        initialize_map(&data);
        parsing(av[1], &data);
        initialize_player(&data);
        render(&data);
        mlx_terminate(data.mlx);
        ft_freeall(data.map);
    }
    return (0);
}