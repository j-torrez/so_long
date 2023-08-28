#include "so_long.h"

char *read_map(char *map)
{
	int fd;
	char *map_output;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Unable to open file");
		return NULL;
	}
	
	map_output = get_next_line(fd);

	close (fd);
	return map_output; 	
}

