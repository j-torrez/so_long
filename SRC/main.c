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
	int num;

	if (argc != 2)
	{
		ft_printf("Usage: %s <map.ber>\n", arg1);
		return 1; 
	}
	check_extension(arg2);
	game = initialize_data(arg2);

	game->mlx = mlx_init(game->width * PIXELS, game->height * PIXELS, 
	"so_long", true);

	if (!game->mlx)
	{
		return (EXIT_FAILURE);
	}

	image = initalize_img_struct(game->mlx);
	game->img = image;
	background_image(game);
	locate_images(game);
	string_to_screen(game);
	print_moves(game);
	print_collectibles(game);
	num = get_exit_pos(game, 'y');


	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);

	ft_printf("Game width: %d\n", game->width);
    ft_printf("Game height: %d\n", game->height);
	ft_printf("Poition: %d\n", num);

	free(game);		
}
