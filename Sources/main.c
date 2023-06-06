/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:41:08 by khabbout          #+#    #+#             */
/*   Updated: 2023/06/06 12:41:08 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int check_extension_map_file(char *map_file_name)
{
    size_t len;

    len = ft_strlen(map_file_name);
    if (((len > 4) && map_file_name[len - 4] == '.' && map_file_name[len - 3] == 'b' && map_file_name[len - 2] == 'e' && map_file_name[len - 1] == 'r'))
        return (0);
    else
        return (-1);
}

int main(int ac, char **av)
{
    t_map data;

    if (ac != 2)
        ft_printf(RED "Invalid number of args\n" WHITE);
    if (ac == 2)
    {
        if (check_extension_map_file(av[1]) == -1)
            exit(ft_printf(RED "Format file is not .ber\n" WHITE));
        initialize_map(&data);
        parsing(av[1], &data);
        initialize_player(&data);
        render(&data);
        mlx_terminate(data.mlx);
        free_all(data.map);
    }
    return (0);
}