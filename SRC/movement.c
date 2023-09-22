/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorrez- <jtorrez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:05:06 by jtorrez-          #+#    #+#             */
/*   Updated: 2023/09/22 13:34:26 by jtorrez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*move_up(t_game *game)
{
	if (game->grid[game->chara_pos_y - 1][game->chara_pos_x] != '1' 
		&& game->grid[game->chara_pos_y - 1][game->chara_pos_x] != 'E')
	{
		if (game->grid[game->chara_pos_y - 1][game->chara_pos_x] == 'C')
		{
			remove_collectible(game, game->chara_pos_y - 1, game->chara_pos_x);
			print_collectibles(game);
			game->grid[game->chara_pos_y - 1][game->chara_pos_x] = '0';
			game->collectibles += 1;
		}
		game->chara_pos_y -= 1;
		game->img->character->instances[0].y -= 1 * PIXELS;
		game->img->character->instances[0].enabled = false;
		print_moves(game);
		game->steps += 1;
		check_game_status(game);
	}
	return (game);
}

t_game	*move_down(t_game *game)
{
	if (game->grid[game->chara_pos_y + 1][game->chara_pos_x] != '1' 
	&& game->grid[game->chara_pos_y + 1][game->chara_pos_x] != 'E')
	{
		if (game->grid[game->chara_pos_y + 1][game->chara_pos_x] == 'C')
		{
			remove_collectible(game, game->chara_pos_y + 1, game->chara_pos_x);
			print_collectibles(game);
			game->grid[game->chara_pos_y + 1][game->chara_pos_x] = '0';
			game->collectibles += 1;
		}
		game->chara_pos_y += 1;
		game->img->character->instances[0].y += 1 * PIXELS;
		game->img->character->instances[0].enabled = false;
		print_moves(game);
		game->steps += 1;
		check_game_status(game);
	}
	return (game);
}

t_game	*move_right(t_game *game)
{
	if (game->grid[game->chara_pos_y][game->chara_pos_x + 1] != '1'
		&& game->grid[game->chara_pos_y][game->chara_pos_x + 1] != 'E')
	{
		if (game->grid[game->chara_pos_y][game->chara_pos_x + 1] == 'C')
		{
			remove_collectible(game, game->chara_pos_y, game->chara_pos_x + 1);
			print_collectibles(game);
			game->grid[game->chara_pos_y][game->chara_pos_x + 1] = '0';
			game->collectibles += 1;
		}
		game->chara_pos_x += 1;
		game->img->character->instances[0].x += 1 * PIXELS;
		game->img->character->instances[0].enabled = false;
		print_moves(game);
		game->steps += 1;
		check_game_status(game);
	}
	return (game);
}

t_game	*move_left(t_game *game)
{
	if (game->grid[game->chara_pos_y][game->chara_pos_x - 1] != '1'
		&& game->grid[game->chara_pos_y][game->chara_pos_x - 1] != 'E')
	{
		if (game->grid[game->chara_pos_y][game->chara_pos_x - 1] == 'C')
		{
			remove_collectible(game, game->chara_pos_y, game->chara_pos_x - 1);
			print_collectibles(game);
			game->grid[game->chara_pos_y][game->chara_pos_x - 1] = '0';
			game->collectibles += 1;
		}
		game->chara_pos_x -= 1;
		game->img->character->instances[0].x -= 1 * PIXELS;
		game->img->character->instances[0].enabled = false;
		print_moves(game);
		game->steps += 1;
		check_game_status(game);
	}
	return (game);
}

void	load_chara(t_game *game, char dir)
{
	load_character_move_up(game, dir);
	load_character_move_down(game, dir);
	load_character_move_left(game, dir);
	load_character_move_right(game, dir);
}
