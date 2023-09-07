#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../../MLX42/include/MLX42/MLX42.h"
# include "../Libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>


typedef struct s_game
{
	char 	**grid;
	int 	width;
	int 	height;
} t_game;

typedef struct s_map_content
{
	int exit;
	int collectible;
	int position;

} t_map_content;


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
#endif