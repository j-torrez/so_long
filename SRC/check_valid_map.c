/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorrez- <jtorrez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:03:19 by jtorrez-          #+#    #+#             */
/*   Updated: 2023/09/22 12:14:55 by jtorrez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extension(char *word)
{
	int	word_length;

	word_length = ft_strlen(word);
	if (word_length >= 11)
	{
		if (ft_strncmp(word + word_length - 4, ".ber", 4))
		{
			error_msg("Please use extension .ber\n");
		}
	}
}

void	validate_map_content(int i)
{
	if (!(ft_strchr("01CEPX\n", i)))
	{
		error_msg("Invalid characters\n");
	}
}

void	check_map_content(char *map_as_one_line)
{
	t_map_content	content;
	int				i;

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
		else 
			(validate_map_content(map_as_one_line[i]));
		i++; 
	}
	if (content.exit != 1 || content.collectible < 1 || content.position != 1)
	{
		error_msg("Please check the content of your map\n");
	}
}

void	check_map_empty(char *map_as_one_line)
{
	int	i; 

	i = 0; 
	if (!map_as_one_line[i])
		error_msg("Map is Empty");
}
