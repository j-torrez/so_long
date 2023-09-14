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
	t_img	*image;

	if (argc != 2)
	{
		ft_printf("Usage: %s <map.ber>\n", arg1);
		return 1; 
	}
	check_extension(arg2);
	game = initialize_data(arg2);

	game->mlx = mlx_init(game->width * PIXELS, game->height * PIXELS, 
	"so_long", false);

	if (!game->mlx)
	{
		return (EXIT_FAILURE);
	}

	image = initalize_img_struct(game->mlx);
	mlx_image_to_window(game->mlx, image->sky, 0 , 0);

	
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);

	ft_printf("Game width: %d\n", game->width);
    ft_printf("Game height: %d\n", game->height);

	free(game);		
}
