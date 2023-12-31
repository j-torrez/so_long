/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorrez- <jtorrez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:04:16 by jtorrez-          #+#    #+#             */
/*   Updated: 2023/10/08 18:35:06 by jtorrez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*initialize_data(char *map)
{
	t_game	*data;
	char	*map_as_one_line;
	char	**map_as_arr; 

	map_as_one_line = read_map(map);
	map_as_arr = map_as_array(map_as_one_line);
	check_map_empty(map_as_one_line);
	check_map_content(map_as_one_line);
	check_rectangular_map(map_as_arr);
	data = initialize_game_struct(map_as_arr);
	check_walls_map(data);
	flood_fill(data);
	free(map_as_one_line);
	return (data);
}

t_game	*initialize_game_struct(char **grid)
{
	t_game	*game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		ft_printf("Error allocating memory for the game struct");
	game->width = width_map(grid);
	game->height = height_map(grid);
	game->grid = grid;
	game->steps = 0;
	game->collectibles = 0;
	game->chara_pos_x = get_character_pos(game, 'x');
	game->chara_pos_y = get_character_pos(game, 'y');
	game->exit_pos_x = get_exit_pos(game, 'x');
	game->exit_pos_y = get_exit_pos(game, 'y');
	game->coins = count_collectibles(game);
	return (game);
}

t_img	*initalize_img_struct(mlx_t *mlx)
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
	img_assets = load_character_up(mlx, img_assets);
	img_assets = load_character_left(mlx, img_assets);
	img_assets = load_character_down(mlx, img_assets);
	img_assets = load_character_right(mlx, img_assets);
	return (img_assets);
}
