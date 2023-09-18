#include "so_long.h"

void	string_to_screen(t_game *game)
{
	game->img->moves_print = mlx_put_string(game->mlx, "MOVES: ", 16, game->height * 64 - 44 );
	mlx_image_to_window(game->mlx, game->img->honey, 140, game->height * 64 - 50);
	mlx_put_string (game->mlx, ":", 165, game->height * 64 -44);
}