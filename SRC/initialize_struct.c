#include "so_long.h"

t_game *initialize_game_struct (char **grid)
{
	t_game *game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));

	if (!game)
		ft_printf("Error allocating memory for the game struct");
	
	game->width = width_map(grid);
	game->height = height_map(grid);
	game->grid = grid;

	return (game);
}