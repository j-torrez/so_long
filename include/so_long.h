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
	int32_t		position_x;
	int32_t		position_y;
	mlx_t		*mlx;
	struct s_img *img;
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
	mlx_image_t *exit_close;
	mlx_image_t *exit_open;
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
#endif