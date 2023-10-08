/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorrez- <jtorrez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:05:14 by jtorrez-          #+#    #+#             */
/*   Updated: 2023/10/08 18:39:53 by jtorrez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/* While (true) initialize an infinite loop until reaching the break
statement*/
static void	check_file(int fd)
{
	if (fd == -1)
	{
		perror("Error:");
		exit(-1);
	}
}

char	*read_map(char *map_path)
{
	int		fd;
	char	*temp_line;
	char	*map_one_line; 

	fd = open(map_path, O_RDONLY);
	check_file(fd);
	map_one_line = ft_calloc(1, 1);
	if (!map_one_line)
		return (NULL);
	while (1)
	{
		temp_line = get_next_line(fd);
		if (temp_line)
		{
			map_one_line = ft_strjoin(map_one_line, temp_line);
			free(temp_line);
		}
		else
			break ;
	}
	close (fd);
	return (map_one_line);
}

char	**map_as_array(char *map_one_line)
{
	char	**map_as_arr;
	char	delimiter;

	delimiter = '\n';
	map_as_arr = ft_split(map_one_line, delimiter);
	return (map_as_arr);
}

void	free_map_array(char **map_as_arr)
{
	int	i;

	i = 0;
	if (map_as_arr)
	{
		while (map_as_arr[i])
		{
			free(map_as_arr[i]);
			i++;
		}
		free(map_as_arr);
	}
}
