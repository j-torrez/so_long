#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../MLX42/include/MLX42/MLX42.h"
# include "../Libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>

# define PIXELS 64

typedef struct s_game
{
	char 		**grid;
	int 		width;
	int 		height;
	int			steps;
	int			collectibles;
	int32_t		position_x;
	int32_t		position_y;
	mlx_t		*mlx;
	int			chara_pos_x;
	int			chara_pos_y;
	int			exit_pos_x;
	int			exit_pos_y;
	struct s_img *img;
	mlx_image_t *character;
} t_game;

typedef struct s_map_content
{
	int exit;
	int collectible;
	int position;

} t_map_content;

typedef struct s_img
{
	mlx_image_t *sky;
	mlx_image_t *tree;
	mlx_image_t *honey;
	mlx_image_t *character;
	mlx_image_t *character_up;
	mlx_image_t *character_down;
	mlx_image_t *character_left;
	mlx_image_t *exit_close;
	mlx_image_t *exit_open;
	mlx_image_t *moves_print;
	mlx_image_t *moves_nbr;
	mlx_image_t *collectibles_nbr;

} t_img;


char *read_map(char *map);
char **map_as_array(char *map_one_line);
void check_map_content(char *map_as_one_line);
void check_map_empty (char *map_as_one_line);
void validate_map_content (int i);
void check_rectangular_map(char **map_as_arr);
int width_map(char **map_as_array);
int height_map(char **map_as_array);
t_game *initialize_game_struct (char **grid);
void check_walls_map(t_game *game);
void error_msg(char *msg);
t_game *initialize_data (char *map);
void check_extension (char *word);
t_img	*load_sky_texture(mlx_t *mlx, t_img *img);
t_img	*initalize_img_struct (mlx_t *mlx);
void	background_image(t_game *data);
t_img	*load_tree_texture(mlx_t *mlx, t_img *img);
void render_map(t_game *data, int y, int x);
void locate_images(t_game *data);
t_img	*load_collectible_texture(mlx_t *mlx, t_img *img);
t_img	*load_main_character_texture(mlx_t *mlx, t_img *img);
t_img *load_exit_close_texture(mlx_t *mlx, t_img *img);
t_img *load_exit_open_texture(mlx_t *mlx, t_img *img);
int	get_character_pos(t_game *game, char c);
int	get_exit_pos(t_game *game, char c );
void	string_to_screen(t_game *game);
void	print_moves(t_game *game);
int	count_collectibles(t_game *game);
void	print_collectibles(t_game *game);
void	remove_collectible(t_game *game, int y, int x);
t_game	*move_up(t_game *game);
t_game	*move_down(t_game *game);
t_game	*move_right(t_game *game);
t_game	*move_left(t_game *game);
void	load_chara(t_game *game, char dir);
void	move_select(t_game *game, char line, char dir);
void	move_player(t_game *game, char line, char dir);
void	move_hook(mlx_key_data_t keydata, void *data);
t_img	*load_character_up(mlx_t *mlx, t_img *img);
t_img	*load_character_left(mlx_t *mlx, t_img *img);
#endif