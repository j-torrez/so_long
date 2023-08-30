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

char *read_map(char *map);
char **map_as_array(char *map_one_line);

#endif