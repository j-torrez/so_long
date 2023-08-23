#include "so_long.h"
#define BPP sizeof(int32_t)

/* mlx_init() Initialize and run a new window instance.*/
int32_t	main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);

	mlx_image_t *img;

	img = mlx_new_image(mlx, 128, 128);

    memset(img->pixels, 255, img->width * img->height * BPP);

    mlx_image_to_window(mlx, img, 0, 0);

    // Run the main loop and terminate on quit.  
    mlx_loop(mlx);
    mlx_terminate(mlx);
    return (EXIT_SUCCESS);

}