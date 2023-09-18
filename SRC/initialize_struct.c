#include "so_long.h"

t_game *initialize_data (char *map)
{
	t_game	*data;
	char	*map_as_one_line;
	char 	**map_as_arr; 

	map_as_one_line = read_map(map);
	map_as_arr = map_as_array(map_as_one_line);

	check_map_empty(map_as_one_line);
	check_map_content(map_as_one_line);
	check_rectangular_map(map_as_arr);

	data = initialize_game_struct(map_as_arr);
	check_walls_map(data);

	free(map_as_one_line);

	return (data);
}

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

t_img	*initalize_img_struct (mlx_t *mlx)
{
	t_img	*img_assets;

	img_assets = (t_img *)ft_calloc(1, sizeof(t_img));
	
	if (!img_assets)
		ft_printf ("Error allocating memory for images asssets");

	img_assets = load_sky_texture(mlx, img_assets);
	img_assets = load_tree_texture(mlx, img_assets);
	img_assets = load_collectible_texture(mlx, img_assets);
	img_assets = load_main_character_texture(mlx, img_assets);
	img_assets = load_exit_close_texture(mlx, img_assets);
	img_assets = load_exit_open_texture(mlx, img_assets);

	return img_assets;
}