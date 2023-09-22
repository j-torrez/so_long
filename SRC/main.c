/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorrez- <jtorrez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:04:55 by jtorrez-          #+#    #+#             */
/*   Updated: 2023/09/22 10:06:22 by jtorrez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
Check if the word in long enough
Compare the last character of the word with .ber
*/

 int main (int argc, char *argv[])
{	
	char *arg1 = argv[0];
	char *arg2 = argv[1];
	t_game	*game;
	t_img	*image;

	if (argc != 2)
	{
		ft_printf("Usage: %s <map.ber>\n", arg1);
		return 1; 
	}
	check_extension(arg2);
	game = initialize_data(arg2);

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

	free(game);	
}
