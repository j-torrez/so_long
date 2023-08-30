#include "so_long.h"
/* While (true) initialize an infinite loop until reaching the break
statement*/
char *read_map(char *map_path)
{
	int fd;
	char *temp_line;
	char *map_one_line; 

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Unable to open file");
		return NULL;
	}

	map_one_line = ft_strdup("");
	while (true)
	{
		temp_line = get_next_line(fd);
		if(temp_line)
		{
			map_one_line = ft_strjoin(map_one_line, temp_line);
			free(temp_line);
		}
		else
			break ;
	}
	
	close (fd);
	return map_one_line;
	 	
}

char **map_as_array (char *map_one_line)
{
	char **map_as_arr;
	char delimiter = '\n';

	map_as_arr = ft_split(map_one_line, delimiter);

	return map_as_arr;
}

