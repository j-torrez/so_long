#include "so_long.h"

char *read_map(char *map)
{
	int fd;
	char *temp_line;
	char *str_arr;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Unable to open Map, please check if map exist");
		return NULL;
	}
	
	str_arr = ft_strdup("");
	while (true)
	{
		temp_line = get_next_line(fd);
		if (temp_line)
		{
			str_arr = ft_strjoin(str_arr, temp_line);
			free(temp_line);
		}
		else
			break ;
	}
	
	

	close (fd);
	return str_arr; 	
}

