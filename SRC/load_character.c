/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorrez- <jtorrez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:19:10 by jtorrez-          #+#    #+#             */
/*   Updated: 2023/09/22 12:47:29 by jtorrez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_character_move_up(t_game *game, char dir)
{
	int	i;

	i = 0;
	if (dir == 'u')
	{
		mlx_image_to_window(game->mlx, game->img->character_up, 
			game->chara_pos_x * PIXELS, game->chara_pos_y * PIXELS);
		while (game->img->character_up->count > 1)
		{
			game->img->character_up->instances[i].enabled = false;
			game->img->character_up->count--;
			i++;
		}
	}
	if ((dir == 'd' || dir == 'r' || dir == 'l') 
		&& (game->img->character_up->count == 1))
	{
		game->img->character_up->instances[i].enabled = false;
		game->img->character_up->instances[i + 1].enabled = false;
	}
}

void	load_character_move_down(t_game *game, char dir)
{
	int	d;

	d = 0;
	if (dir == 'd')
	{
		mlx_image_to_window(game->mlx, game->img->character_down, 
			game->chara_pos_x * PIXELS, game->chara_pos_y * PIXELS);
		while (game->img->character_down->count > 1)
		{
			game->img->character_down->instances[d].enabled = false;
			game->img->character_down->count--;
			d++;
		}
	}
	if ((dir == 'u' || dir == 'r' || dir == 'l') 
		&& (game->img->character_down->count == 1))
	{
		game->img->character_down->instances[d].enabled = false;
		game->img->character_down->instances[d + 1].enabled = false;
	}
}

void	load_character_move_right(t_game *game, char dir)
{
	int	r;

	r = 0;
	if (dir == 'r')
	{
		mlx_image_to_window(game->mlx, game->img->character_right, 
			game->chara_pos_x * PIXELS, game->chara_pos_y * PIXELS);
		while (game->img->character_right->count > 1)
		{
			game->img->character_right->instances[r].enabled = false;
			game->img->character_right->count--;
			r++;
		}
	}
	if ((dir == 'u' || dir == 'd' || dir == 'l') 
		&& (game->img->character_right->count == 1))
	{
		game->img->character_right->instances[r].enabled = false;
		game->img->character_right->instances[r + 1].enabled = false;
	}
}

void	load_character_move_left(t_game *game, char dir)
{
	int	l;

	l = 0;
	if (dir == 'l')
	{
		mlx_image_to_window(game->mlx, game->img->character_left, 
			game->chara_pos_x * PIXELS, game->chara_pos_y * PIXELS);
		while (game->img->character_left->count > 1)
		{
			game->img->character_left->instances[l].enabled = false;
			game->img->character_left->count--;
			l++;
		}
	}
	if ((dir == 'd' || dir == 'r' || dir == 'u') 
		&& (game->img->character_left->count == 1))
	{
		game->img->character_left->instances[l].enabled = false;
		game->img->character_left->instances[l + 1].enabled = false;
	}
}
