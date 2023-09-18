#include "so_long.h"
/* This function return x = column where is located the character, y = row where is located the character*/
/*if char is "x" this return the column, other char like "y" return the row*/
int	get_character_pos(t_game *game, char c)
{
	int	y;
	int x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->grid[y][x] == 'P')
			{
				if (c == 'x')
					return (x);
				else
					return (y);
			}
			x++;	
		}
		y++;
	}
	return (0);	
}

int	get_exit_pos(t_game *game, char c )
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->grid[y][x] == 'E')
			{
				if (c == 'x')
					return (x);
				else
					return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}