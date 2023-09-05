#include "so_long.h"

void	check_rectangular_map(char **map_as_arr)
{
	size_t first_row;
	size_t i;

	first_row = ft_strlen(*map_as_arr);
	i = 0;
	while (map_as_arr[i] != NULL)
	{
		if (first_row != ft_strlen(map_as_arr[i]))
		{
			ft_printf("Map is not rectangular");
		}
		i++;
	}
}

void	check_walls_map(t_game *game)
{
	int i; 

	i = 0;
	// Check first and last column surronded by walls
	while (i < game->height)
	{
		if ((game->grid[i][0] != '1') || (game->grid[i][game->width - 1] != '1') )
		{
			ft_printf("Map is not surronded by walls\n");
		}
		else
		{
			ft_printf("Map is surronded by walls \n");
		}
		i++;
	}
	//Check first and last row surronded by walls
	i = 0;
	while (i < game->width)
	{
		if((game->grid[0][i]!= '1') || (game->grid[game->height - 1][i] != '1'))
		{
			ft_printf("NOT walls \n");
		}
		else
		{
			ft_printf("WALLS \n");
		}
		i++;
	}
}