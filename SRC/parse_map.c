#include "so_long.h"

char *read_map(char *map)
{
	int fd;
	char *map_output;

	fd = open(map, O_RDONLY);
	

	map_output = get_next_line(fd);
	close (fd);
	return map_output; 	
}

