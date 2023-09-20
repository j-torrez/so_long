#include "so_long.h"

t_game	*move_up(t_game *game)
{
	if(game->grid[game->chara_pos_y - 1][game->chara_pos_x] != '1' && game->grid[game->chara_pos_y - 1][game->chara_pos_x] != 'E')
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
	

	
		print_moves(game);
		game->steps += 1;
		
	}
	return (game);
}

t_game	*move_down(t_game *game)
{
	if(game->grid[game->chara_pos_y + 1][game->chara_pos_x] != '1' && game->grid[game->chara_pos_y + 1][game->chara_pos_x] != 'E')
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
		print_moves(game);
		game->steps += 1;
		
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
		print_moves(game);
		game->steps += 1;
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
		print_moves(game);
		game->steps += 1;
	}
	return (game);
}

void	load_chara(t_game *game, char dir)
{
	int i;
	i = 0;

	if (dir == 'u')
	{
		mlx_image_to_window(game->mlx, game->img->character_up, game->chara_pos_x * PIXELS, game->chara_pos_y * PIXELS);
		while (game->img->character_up->count > 1)
		{
			game->img->character_up->instances[i].enabled = false;
			game->img->character_up->count--;
			i++;
		}
	}


	if (dir == 'd')
		mlx_put_pixel(game->img->character, 0, 0, 0);
	if (dir == 'r')
		mlx_put_pixel(game->img->character, 0, 0, 0);
	if (dir == 'l')
		mlx_put_pixel(game->img->character, 0, 0, 0);

	
		
}

void	move_select(t_game *game, char line, char dir)
{
	if (line == 'y')
	{
		if (dir == 'u')
			move_up(game);
		else
			move_down(game);
	}
	if (line == 'x')
	{
		if (dir == 'r')
			move_right(game);
		else
			move_left(game);
	}
}

void	move_player(t_game *game, char line, char dir)
{
	move_select(game, line, dir);
	load_chara(game, dir);
}

void	move_hook(mlx_key_data_t keydata, void *data)
{
	t_game	*game;

	game = (t_game *) data;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_player(game, 'y', 'u');
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_player(game, 'x', 'r');
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_player(game, 'y', 'd');
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_player(game, 'x', 'l');
}
