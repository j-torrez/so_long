#include "so_long.h"
/*
Check if the word in long enough
Compare the last character of the word with .ber
*/
int main (int argc, char *argv[])
{
	char *arg1 = argv[0];
	char *arg2 = argv[1];
	t_game	*game; 
	

	if (argc != 2)
	{
		ft_printf("Usage: %s <map.ber>\n", arg1);
		return 1; 
	}
	check_extension(arg2);

	game = initialize_data(arg2);

	ft_printf("Game width: %d\n", game->width);
    ft_printf("Game height: %d\n", game->height);

	free(game);
}

