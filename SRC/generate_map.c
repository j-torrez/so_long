#include "so_long.h"

void	background_image(t_game *data)
{
	data->position_x = 0;
	while (data->position_x < data->width)
	{
		data->position_y = 0;
		while (data->position_y < data->height)
		{
			if (mlx_image_to_window(data->mlx, data->img->sky, data->position_x * PIXELS, data->position_y * PIXELS) < 0)
				error_msg("Failed to put background image");
			data->position_y++;
		}
		data->position_x++;
	}
}