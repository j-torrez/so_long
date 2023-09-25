/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorrez- <jtorrez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:00:24 by jtorrez-          #+#    #+#             */
/*   Updated: 2023/09/25 16:13:46 by jtorrez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	test_case(t_game *game)
{
    t_game *copy;
    int i;
    int j;
    int x_space;
    int y_space;
    int total_exit_count;
    int total_collectible_count;

    copy = create_duplicate(game);
    printf("TOTAL COLLECTIBLES BEFORE: %d\n", count_collectibles(copy));
    printf("TOTAL EXIT BEFORE: %d\n", count_exit(copy));
    flood_fill(copy->grid, copy->chara_pos_x, copy->chara_pos_y, copy->height, copy->width, 'C', '0', 'E', 'N');

    total_collectible_count = count_collectibles(copy);
    total_exit_count = count_exit(copy);

    if (total_collectible_count != 0 || total_exit_count != 0 )
        error_msg("There is not a valid path in the map");

    i = copy->chara_pos_x;
    j = copy->chara_pos_y;
    
    x_space = copy->free_space_x;
    y_space = copy->free_space_y;

    ft_printf("Character Position X: %d \n", i);
    ft_printf("Character Position Y: %d \n", j);
    ft_printf("First instance free space X: %d \n", x_space);
    ft_printf("First instance free space Y: %d\n", y_space);
    printf("TOTAL COLLECTIBLES AFTER: %d\n", count_collectibles(copy));
    printf("TOTAL EXIT AFTER: %d\n", count_exit(copy));

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
	}
}

void flood_fill(char **grid, int sr, int sc, int row, int col, char free_space, char collectibles, char exit, char position)
{
  if (sr < 0 || sr >= row || sc < 0 || sc >= col)
    {
        return;
    }
    
  if (grid[sr][sc] != free_space && grid[sr][sc] != collectibles && grid[sr][sc] != exit)
    {
        return;
    }

    grid[sr][sc] = position;
    flood_fill(grid, sr - 1, sc, row, col, free_space, collectibles, exit, position);
    flood_fill(grid, sr + 1, sc, row, col, free_space, collectibles, exit, position);
    flood_fill(grid, sr, sc - 1, row, col, free_space, collectibles, exit, position);
    flood_fill(grid, sr, sc + 1, row, col, free_space, collectibles, exit, position);
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
        copy->grid[i] = ft_strdup(game->grid[i]); // Create a duplicate of each row
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
int count_exit(t_game *game)
{
    int i;
    int j;
    int exit;

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