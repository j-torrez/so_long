/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorrez- <jtorrez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:03:58 by jtorrez-          #+#    #+#             */
/*   Updated: 2023/09/22 10:57:22 by jtorrez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	background_image(t_game *data)
{
	data->position_x = 0;
	while (data->position_x < data->width)
	{
		data->position_y = 0;
		while (data->position_y < data->height)
		{
			if (mlx_image_to_window(data->mlx, data->img->sky, 
					data->position_x * PIXELS, data->position_y * PIXELS) < 0)
				error_msg("Failed to put background image");
			data->position_y++;
		}
		data->position_x++;
	}
}

void	render_map(t_game *data, int y, int x)
{
	int	img_size;

	img_size = 32;

	if (data->grid[y][x] == '1')
		if (mlx_image_to_window (data->mlx, data->img->tree, 
				x * PIXELS, y * PIXELS) < 0)
			error_msg("Failed to put tree images");
	if (data->grid[y][x] == 'C')
		if (mlx_image_to_window (data->mlx, data->img->honey, 
				x * PIXELS + img_size / 2, y * PIXELS + img_size / 2) < 0)
			error_msg("Failed to put tree images");
	if (data->grid[y][x] == 'P')
		if (mlx_image_to_window (data->mlx, data->img->character, 
				x * PIXELS, y * PIXELS) < 0)
			error_msg ("Failed to put character image");
	if (data->grid[y][x] == 'E')
		if (mlx_image_to_window (data->mlx, data->img->exit_close, 
				x * PIXELS, y * PIXELS) < 0)
			error_msg ("Failed to put exit image");
}

void	locate_images(t_game *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			render_map(data, y, x);
			x++;
		}
		y++;
	}
}

