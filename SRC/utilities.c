#include "so_long.h"

int height_map(char **map_as_array)
{
	int i; 

	i = 0;
	while (map_as_array[i])
	{
		i++;
	}
	return i;
}

int width_map(char **map_as_array)
{
	return (ft_strlen(map_as_array[0]));
}

int	count_collectibles(t_game *game)
{
	int y; 
	int x;
	int i;

	y = 0;
	i = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->grid[y][x] == 'C')
			{
				i++;
			}
			x++;
		}
		y++;
	}
	return i;
}

void error_msg(char *msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(msg, 2);
	exit(-1);
}