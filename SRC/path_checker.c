/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorrez- <jtorrez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:00:24 by jtorrez-          #+#    #+#             */
/*   Updated: 2023/09/23 16:03:53 by jtorrez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	test_case(t_game *game)
{
	/* int i; 
	int j;
    t_game *copy;

	i = 0;
	while (i < copy->height)
	{
		j = 0;
		while (j < copy->width)
		{
			printf("%c ", copy->grid[i][j]);
			j++;
		}
		printf("\n");
		i++;	
	}   */
    t_game * copy;
    copy = create_duplicate(game);
    flood_fill(copy->grid, copy->grid[copy->chara_pos_y], copy->grid[copy->chara_pos_x], 'P', 'NP');

}

void flood_fill(char **grid, int sr, int sc, char old_position, char new_position)
{
    int sr;
    int sc;
    int width;
    int heigth;
    t_game *game;
    t_game *copy; 

    copy = create_duplicate(game);

    sr = copy->grid[copy->chara_pos_y];
    sc = copy->grid[copy->chara_pos_x];
    width = copy->width;
    heigth = copy->height;

    if (sr < 0 || sc < 0 || sr >= heigth || sc >= width||grid[sr][sc] != old_position)
    {
        return;
    }
    grid[sr][sc] = new_position;

    flood_fill(grid, sr - 1, sc, old_position, new_position);
    flood_fill(grid, sr + 1, sc, old_position, new_position);
    flood_fill(grid, sr, sc - 1, old_position, new_position);
    flood_fill(grid, sr, sc + 1, old_position, new_position);


    int i = 0;
    while (i < copy->height)
	{
		int j = 0;
		while (j < copy->width)
		{
			printf("%c ", copy->grid[i][j]);
			j++;
		}
		printf("\n");
		i++;	
	}
}
t_game *create_duplicate(t_game *game)
{
	t_game *copy;

    // Allocate memory for the new structure
    copy = (t_game *)malloc(sizeof(t_game));
    if (!copy) {
        error_msg("Error allocating memory");
    }
	
    // Copy primitive data members
    ft_memcpy(copy, game, sizeof(t_game));

    // Copy the 'grid' array
    copy->grid = (char **)malloc(game->height * sizeof(char *));
    if (!copy->grid) {
        // Handle memory allocation error here
        free(copy); // Free the previously allocated memory for the structure
    }

    // Copy the rows of the grid
    for (int i = 0; i < game->height; i++) {
        copy->grid[i] = strdup(game->grid[i]); // Create a duplicate of each row
        if (!copy->grid[i]) {
            // Handle memory allocation error here
            // You may also need to free previously allocated memory
            // for 'copy' and its 'grid' elements.
            free(copy->grid);
            free(copy);
        }
    }

    return	copy;	
}
