/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorrez- <jtorrez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:04:55 by jtorrez-          #+#    #+#             */
/*   Updated: 2023/09/24 12:25:41 by jtorrez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Check if the word in long enough
Compare the last character of the word with .ber
*/
#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	*game;
	t_img	*image;

	if (argc != 2)
	{
		ft_printf("Usage: %s <map.ber>\n", argv[0]);
		return (1); 
	}
	check_extension(argv[1]);
	game = initialize_data(argv[1]);
	test_case(game);
	game->mlx = mlx_init(game->width * PIXELS, game->height * PIXELS, 
			"so_long", true);
	if (!game->mlx)
	{
		return (EXIT_FAILURE);
	}
	image = initalize_img_struct(game->mlx);
	game->img = image;
	background_image(game);
	locate_images(game);
	string_to_screen(game);
	mlx_key_hook(game->mlx, move_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free (game);
}
