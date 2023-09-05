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