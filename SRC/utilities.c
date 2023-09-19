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

/*
mlx_img_t (Review Documentation) 
 * @param instances An instance carrying the X, Y and Z location data.
 * @param count The element count of the instances array.
 * @param enabled If true the image is drawn onto the screen, else it's not.
 * Check generate_map.c, function to generate collectible, remember Collectibles pixels are different
 * that's why we add an offset of 16P */

void	remove_collectible(t_game *game, int y, int x)
{
	size_t collectible_i;

	collectible_i = 0;
	x = x * PIXELS + 16;
	y = y * PIXELS + 16;

	while (collectible_i < game->img->honey->count)
	{
		if (game->img->honey->instances[collectible_i].x == x && game->img->honey->instances[collectible_i].y == y)
		{
			game->img->honey->instances[collectible_i].enabled = false;
		}
		collectible_i++;
	}
	
}
void error_msg(char *msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(msg, 2);
	exit(-1);
}