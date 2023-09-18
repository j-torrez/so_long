#include "so_long.h"

void	string_to_screen(t_game *game)
{
	game->img->moves_print = mlx_put_string(game->mlx, "MOVES: ", 16, game->height * 64 - 44 );
	mlx_image_to_window(game->mlx, game->img->honey, 140, game->height * 64 - 50);
	mlx_put_string (game->mlx, ":", 165, game->height * 64 -44);
}

void	print_moves(t_game *game)
{
	char *str;
	str = ft_itoa(game->steps);

	mlx_delete_image(game->mlx, game->img->moves_nbr);
	game->img->moves_nbr = mlx_put_string(game->mlx, str, 80, game->height * 64 - 44);
	free(str);
}

void	print_collectibles(t_game *game)
{
	char *str;
	str = ft_itoa(game->collectibles);
	mlx_delete_image(game->mlx, game->img->collectibles_nbr);
	game->img->collectibles_nbr = mlx_put_string(game->mlx, str, 175, game->height * 64 - 44);
	free(str);
}