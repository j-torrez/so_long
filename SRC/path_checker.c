/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnbosco <johnbosco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:00:24 by jtorrez-          #+#    #+#             */
/*   Updated: 2023/09/27 21:32:51 by johnbosco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	test_case(t_game *game)
{
	t_game	*copy;
	int		total_exit_count;
	int		total_collectible_count;

	copy = create_duplicate(game);
	flood_fill(copy->grid, copy->chara_pos_x, 
		copy->chara_pos_y, copy->height, copy->width, 'C', '0', 'E', 'N');
	total_collectible_count = count_collectibles(copy);
	total_exit_count = count_exit(copy);
	if (total_collectible_count != 0 || total_exit_count != 0)
		error_msg("There is not a valid path in the map");
	free_grid(copy->grid, copy->height);
}

void	flood_fill(char **grid, int sr, int sc, int row, 
			int col, char free_space, char collectibles, 
			char exit, char position)
{
	if (sr < 0 || sr >= row || sc < 0 || sc >= col)
	{
		return ;
	}
	if (grid[sr][sc] != free_space && grid[sr][sc] 
		!= collectibles && grid[sr][sc] != exit)
	{
		return ;
	}
	grid[sr][sc] = position;
	flood_fill(grid, sr - 1, sc, row, col, free_space, 
		collectibles, exit, position);
	flood_fill(grid, sr + 1, sc, row, col, free_space, 
		collectibles, exit, position);
	flood_fill(grid, sr, sc - 1, row, col, free_space, 
		collectibles, exit, position);
	flood_fill(grid, sr, sc + 1, row, col, free_space, 
		collectibles, exit, position);
}

void	free_grid(char **grid, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

t_game	*create_duplicate(t_game *game)
{
	t_game	*copy;
	int		i;

	i = 0;
	copy = (t_game *)malloc(sizeof(t_game));
	if (!copy) 
	{
		error_msg("Error allocating memory");
	}
	ft_memcpy(copy, game, sizeof(t_game));
	copy->grid = (char **)malloc(game->height * sizeof(char *));
	if (!copy->grid) 
	{
		free(copy);
	}
	while (i < game->height) 
	{
		copy->grid[i] = ft_strdup(game->grid[i]);
		if (!copy->grid[i]) 
		{
			free(copy->grid);
			free(copy);
		}
		i++;
	}
	return (copy);
}

int	count_exit(t_game *game)
{
	int	i;
	int	j;
	int	exit;

	exit = 0;
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->grid[i][j] == 'E')
			{
				exit++;
			}
			j++;
		}
		i++;
	}
	return (exit);
}
