/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorrez- <jtorrez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:00:24 by jtorrez-          #+#    #+#             */
/*   Updated: 2023/09/24 14:26:35 by jtorrez-         ###   ########.fr       */
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

    copy = create_duplicate(game);
    flood_fill(copy->grid, copy->free_space_y, copy->free_space_x, copy->height, copy->width, '0', 'P');
    i = copy->chara_pos_x;
    j = copy->chara_pos_y;
    
    x_space = copy->free_space_x;
    y_space = copy->free_space_y;

    ft_printf("Character Position X: %d \n", i);
    ft_printf("Character Position Y: %d \n", j);
    ft_printf("First instance free space X: %d \n", x_space);
    ft_printf("First instance free space Y: %d\n", y_space);

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

void flood_fill(char **grid, int sr, int sc, int row, int col, char free_space, char position)
{
  if (sr < 0 || sr >= row || sc < 0 || sc >= col)
    {
        return;
    }
    
  if (grid[sr][sc] != free_space)
    {
        return;
    }

    grid[sr][sc] = position;
    flood_fill(grid, sr - 1, sc, row, col, free_space, position);
    flood_fill(grid, sr + 1, sc, row, col, free_space, position);
    flood_fill(grid, sr, sc - 1, row, col, free_space, position);
    flood_fill(grid, sr, sc + 1, row, col, free_space, position);
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

int find_free_space (t_game *game, char c)
{

    int x; 
    int y;

    y = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
            if (game->grid[y][x] == '0')
            {
                
                if (c == 'x')
                    return x;
                else
                    return y;
            }
            x++;
        }
        y++;
    }
    return (0);    
}