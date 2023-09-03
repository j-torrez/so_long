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