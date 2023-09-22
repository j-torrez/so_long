/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorrez- <jtorrez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:04:45 by jtorrez-          #+#    #+#             */
/*   Updated: 2023/09/22 13:55:53 by jtorrez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*load_sky_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*sky;

	sky = mlx_load_png("./Sprites/bricks2.png");
	if (!sky)
		error_msg("Problem loading sky image");
	img->sky = mlx_texture_to_image(mlx, sky);
	if (!img->sky)
		error_msg("Problem converting texture to image");
	mlx_delete_texture(sky);
	return (img);
}

t_img	*load_tree_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*tree;

	tree = mlx_load_png("./Sprites/crystal.png");
	if (!tree)
		error_msg("Problem loading tree image");
	img->tree = mlx_texture_to_image(mlx, tree);
	if (!img->tree)
		error_msg("Problem converting texture to image");
	mlx_delete_texture(tree);
	return (img);
}

t_img	*load_collectible_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*honey;

	honey = mlx_load_png("./Sprites/coin.png");
	if (!honey)
		error_msg("Problem loading honey image");
	img->honey = mlx_texture_to_image(mlx, honey);
	if (!img->honey)
		error_msg("Problem converting texture to image");
	mlx_delete_texture(honey);
	return (img);
}

t_img	*load_exit_close_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*exit_close;

	exit_close = mlx_load_png("./Sprites/door.png");
	if (!exit_close)
		error_msg("Problem loading exit image");
	img->exit_close = mlx_texture_to_image(mlx, exit_close);
	if (!img->exit_close)
		error_msg("Problem converting texture to image");
	mlx_delete_texture(exit_close);
	return (img);
}

t_img	*load_exit_open_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*exit_open;

	exit_open = mlx_load_png("./Sprites/door_open.png");
	if (!exit_open)
		error_msg("Problem loading exit open image");
	img->exit_open = mlx_texture_to_image(mlx, exit_open);
	if (!img->exit_open)
		error_msg("Problem converting texture to image");
	mlx_delete_texture(exit_open);
	return (img);
}
