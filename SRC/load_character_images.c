#include "so_long.h"

t_img	*load_character_up(mlx_t *mlx, t_img *img)
{
	mlx_texture_t *character_up;
	character_up = mlx_load_png("./Sprites/cat_up.png");
	if (!character_up)
		error_msg("Problem loading character image up");
	img->character_up = mlx_texture_to_image(mlx, character_up);
	if (!img->character_up)
		error_msg("Problem converting texture to image");
	mlx_delete_texture(character_up);
	return (img);
}

t_img	*load_character_left(mlx_t *mlx, t_img *img)
{
	mlx_texture_t *character_left;
	character_left = mlx_load_png("./Sprites/cat_left.png");
	if (!character_left)
		error_msg("Problem loading character image left");
	img->character_left = mlx_texture_to_image(mlx, character_left);
	if (!img->character_up)
		error_msg("Problem converting texture to image");
	mlx_delete_texture(character_left);
	return (img);
}

t_img	*load_character_down(mlx_t *mlx, t_img *img)
{
	mlx_texture_t *character_down;
	character_down = mlx_load_png("./Sprites/cat_down.png");
	if (!character_down)
		error_msg("Problem loading character image down");
	img->character_down = mlx_texture_to_image(mlx, character_down);
	if (!img->character_down)
		error_msg("Problem converting texture to image");
	mlx_delete_texture(character_down);
	return (img);
}