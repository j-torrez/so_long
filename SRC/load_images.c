#include "so_long.h"

t_img	*load_sky_texture(mlx_t *mlx, t_img *img)
{
	//Try to load image file
	mlx_texture_t *sky;
	sky = mlx_load_png("./Sprites/grass-tile.png");
	if (!sky)
		error_msg("Problem loading sky image");
	//Convert texture to a displayable image
	img->sky = mlx_texture_to_image(mlx, sky);
	if (!img->sky)
		error_msg("Problem converting texture to image");
	mlx_delete_texture(sky);
	return (img);
	//It return a pointer
	// to a Structure ? So how do we access that element.
}

t_img	*load_tree_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t *tree;
	tree = mlx_load_png("./Sprites/bigtree.png");
	if (!tree)
		error_msg("Problem loading tree image");
	img->tree = mlx_texture_to_image(mlx, tree);
	if (!img->tree)
		error_msg("Problem converting texture to image");
	mlx_delete_texture(tree);
	return (img);
}