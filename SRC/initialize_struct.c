#include "so_long.h"
/*
t_game *initialize_data (char *map)
{
	t_game	*data;
	char	*map_as_one_line;
	char 	**map_as_arr; 

	map_as_one_line = read_map(map);

}	*/

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