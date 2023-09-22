/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorrez- <jtorrez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:03:49 by jtorrez-          #+#    #+#             */
/*   Updated: 2023/09/22 10:51:33 by jtorrez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_game_status(t_game *game)
{
	int	total;

	total = count_collectibles(game);
	if (total == 0)
	{
		game->img->exit_close->enabled = false;
		mlx_image_to_window(game->mlx, game->img->exit_open, 
			game->exit_pos_x * PIXELS, game->exit_pos_y * PIXELS);
		game->grid[game->exit_pos_y][game->exit_pos_x] = '0';
		if (game->chara_pos_x == game->exit_pos_x 
			&& game->chara_pos_y == game->exit_pos_y)
		{
			game->img->congrats_msg = mlx_put_string(game->mlx, "CONGRATS ", 
					game->width * 32, game->height * 32);
			sleep(1);
			mlx_close_window(game->mlx);
			ft_printf("CONGRATULATION!!\n YOU WON!!!!\n");
		}
	}
}
