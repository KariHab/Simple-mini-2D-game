/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:22:22 by khabbout          #+#    #+#             */
/*   Updated: 2023/05/15 20:22:22 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../Headers/so_long.h"

// static void error(void)
// {
// 	puts(mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

// int32_t main(void)
// {
// 	// Start mlx
// 	mlx_t *mlx = mlx_init(WIDTH, HEIGHT, "Grab your teddy and go to sleep!", true);
// 	if (!mlx)
// 		error();

// 	// Try to load the file
// 	mlx_texture_t *floor = mlx_load_png("./Assets_map/1_Sprites/Floor.png");
// 	if (!floor)
// 		error();

// 	// mlx_texture_t *texture2 = mlx_load_png("./Assets_map/1_Sprites/Teddy.png");
// 	// if (!texture2)
// 	// 	error();

// 	// Convert texture to a displayable image
// 	mlx_image_t *img1 = mlx_texture_to_image(mlx, floor);
// 	if (!img1)
// 		error();

// 	// mlx_image_t *img2 = mlx_texture_to_image(mlx, texture2);
// 	// if (!img2)
// 	// 	error();

// 	// Display the image
// 	if (mlx_image_to_window(mlx, img1, 0, 0) < 0)
// 		error();
// 	// if (mlx_image_to_window(mlx, img2, 0, 0) < 0)
// 	// 	error();
// 	mlx_loop(mlx);

// 	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
// 	mlx_delete_image(mlx, img1);
// 	mlx_delete_texture(floor);
// 	// mlx_delete_image(mlx, img2);
// 	// mlx_delete_texture(texture2);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }
