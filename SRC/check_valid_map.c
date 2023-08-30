#include "so_long.h"

void validate_map_content (int i)
{
	if (!(ft_strchr("01CEP\n", i)))
	{
		ft_printf("Invalid characters\n");
	}
	
}

void check_map_content(char *map_as_one_line)
{
	t_map_content content;
	int	i;

	content.exit = 0;
	content.collectible = 0;
	content.position = 0; 

	i = 0;
	while (map_as_one_line[i] != '\0')
	{
		if (map_as_one_line[i] == 'E')
			content.exit++;
		if (map_as_one_line[i] == 'C')
			content.collectible++;
		if (map_as_one_line[i] == 'P')
			content.position++;
		else (validate_map_content(map_as_one_line[i]));
	i++; 
	}
	if (content.exit != 1 || content.collectible < 1 || content.position != 1)
		ft_printf("Please check the content of your map\n");
	ft_printf("The map has\n %d Exit \n %d Collectibles \n %d Positions\n", content.exit, content.collectible, content.position);
}