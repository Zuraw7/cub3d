/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:15:00 by zuraw             #+#    #+#             */
/*   Updated: 2025/01/05 01:35:16 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
	Funkcja zapełnia cały obraz tłem o podanym kolorze
*/
static void	fill_minimap_background(t_img *image)
{
	int	x;
	int	y;

	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			img_pixel_put(image, x, y, get_argb(0, 97, 91, 86));
			x++;
		}
		y++;
	}
}

/*
	Funkcja umieszcza ściany oraz podłogę na minimapie
*/
void	draw_minimap(t_data *data)
{
	int		x;
	int		y;
	int		color;
	t_map	*map;

	map = data->map;
	fill_minimap_background(data->rend_img->minimap);
	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (map->map[y][x] == '1')
			{
				color = 0x808080;
				draw_tile_to_image(data->rend_img->minimap, x, y, color);
			}
			else if (map->map[y][x] != ' ' && map->map[y][x] != '\n')
			{
				color = 0xFFFFFF;
				draw_tile_to_image(data->rend_img->minimap, x, y, color);
			}
		}
	}
}

/*
	Funkcja umieszcza gracza na minimapie w zależności od pozycji
*/
void	draw_player(t_player *player, t_img *img)
{
	int		i;
	int		j;


	(void)player;
	i = 0;
	while (i < PX / 8)
	{
		j = 0;
		while (j < PX / 8)
		{
			img_pixel_put(img, i, j, 0xFF0000);
			j++;
		}
		i++;
	}
}

/*
	1. Czyści okno
	2. Renderuje obrazy na oknie
		a. sufit
		b. podłoga
		c. minimapę
		d. gracza na minimapie
*/
int	render_scene(t_data *data)
{
	mlx_clear_window(data->mlx->mlx_ptr, data->mlx->win_ptr);
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
		data->rend_img->ceiling->img_ptr, 0, 0);
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
		data->rend_img->floor->img_ptr, 0, HEIGHT / 2);
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
		data->rend_img->minimap->img_ptr, 5, 5);
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
		data->rend_img->player_mm->img_ptr, data->player->x * PX / 4 + 5, data->player->y * PX / 4 + 5);
	return (0);
}
