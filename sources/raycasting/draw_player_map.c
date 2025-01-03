/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:15:00 by zuraw             #+#    #+#             */
/*   Updated: 2025/01/03 15:17:22 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_map_to_image(t_data *data)
{
	int		x;
	int		y;
	int		color;
	t_map	*map;

	map = data->map;
	y = 0;
	while (map->map[y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (map->map[y][x] == '1')
			{
				color = 0x808080;
				draw_tile_to_image(data->minimap, x, y, color);
			}
			else if (map->map[y][x] != ' ' && map->map[y][x] != '\n')
			{
				color = 0xFFFFFF;
				draw_tile_to_image(data->minimap, x, y, color);
			}
		}
		y++;
	}
}

void	draw_player_to_image(t_player *player, t_img *img)
{
	int		i;
	int		j;
	float	player_x;
	float	player_y;

	player_x = player->x * PX / 4 + (PX / (PX / 2));
	player_y = player->y * PX / 4;
	i = 0;
	while (i < PX / 8)
	{
		j = 0;
		while (j < PX / 8)
		{
			img_pixel_put(img, player_x + i, player_y + j, 0xFF0000);
			j++;
		}
		i++;
	}
}

int	render_minimap(t_data *data)
{
	mlx_clear_window(data->mlx->mlx_ptr, data->mlx->win_ptr);
	draw_map_to_image(data);
	draw_player_to_image(data->player, data->minimap);
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
		data->minimap->img_ptr, 10, 10);
	return (0);
}
