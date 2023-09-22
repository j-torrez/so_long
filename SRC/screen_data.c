/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorrez- <jtorrez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:05:25 by jtorrez-          #+#    #+#             */
/*   Updated: 2023/09/22 10:06:13 by jtorrez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	string_to_screen(t_game *game)
{
	game->img->moves_print = mlx_put_string(game->mlx, "MOVES: ", 16, game->height * 64 - 44 );
	if (mlx_image_to_window(game->mlx, game->img->honey, 140, game->height * 64 - 50) < 0)
		error_msg("Error printing MOVE string in the window");
	mlx_put_string (game->mlx, ":", 165, game->height * 64 -44);
}

void	print_moves(t_game *game)
{
	char *str;
	str = ft_itoa(game->steps + 1);
	mlx_delete_image(game->mlx, game->img->moves_nbr);
	game->img->moves_nbr = mlx_put_string(game->mlx, str, 80, game->height * 64 - 44);
	ft_printf("Steps: %s\n", str);
	free(str);
}

void	print_collectibles(t_game *game)
{
	char *str;
	str = ft_itoa(game->collectibles + 1);
	mlx_delete_image(game->mlx, game->img->collectibles_nbr);
	game->img->collectibles_nbr = mlx_put_string(game->mlx, str, 175, game->height * 64 - 44);
	free(str);
}