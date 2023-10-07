/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorrez- <jtorrez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:00:24 by jtorrez-          #+#    #+#             */
/*   Updated: 2023/10/07 11:52:36 by jtorrez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_grid(char **grid, size_t height)
{
	size_t	i;

	i = 0;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

int	check_path(t_game *temp, size_t y, size_t x)
{
	if (temp->grid[y][x] == '1')
		return (0);
	if (temp->grid[y][x] == 'C')
		temp->coins--;
	if (temp->grid[y][x] == 'E')
	{
		temp->exit_pos_x = 1;
		return (0);
	}
	temp->grid[y][x] = '1';
	if (check_path(temp, y + 1, x))
		return (1);
	if (check_path(temp, y - 1, x))
		return (1);
	if (check_path(temp, y, x + 1))
		return (1);
	if (check_path(temp, y, x - 1))
		return (1);
	return (0);
}

void	flood_fill(t_game *game)
{
	t_game	temp;
	int		i;

	temp.height = game->height;
	temp.width = game->width;
	temp.collectibles = game->collectibles;
	temp.chara_pos_x = game->chara_pos_x;
	temp.chara_pos_y = game->chara_pos_y;
	temp.exit_pos_x = 0;
	temp.coins = game->coins;
	temp.grid = (char **)malloc(temp.height * sizeof(char *));
	if (!temp.grid)
		error_msg("Memory allocation failed");
	i = 0;
	while (i < temp.height)
	{
		temp.grid[i] = ft_strdup(game->grid[i]);
		i++;
	}
	check_path(&temp, temp.chara_pos_y, temp.chara_pos_x);
	if (!(temp.exit_pos_x == 1 && temp.coins == 0))
		error_msg("No valid path available");
	free_grid(temp.grid, temp.height);
}
