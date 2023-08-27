#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../../MLX42/include/MLX42/MLX42.h"
# include "../Libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>


typedef struct s_map
{
	int width;
	int height;
	char **grid;
} t_map;

char *read_map(char *map);

#endif