/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:08:28 by zuraw             #+#    #+#             */
/*   Updated: 2025/01/05 11:56:07 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	download_textures(t_data *data);

/*
	Funkcja tworzy miejsce na obrazy oraz wpisuje do nich treść obrazu
	1. Inicjalizacja struktury na obrazy
	2. Ustawienie wall_px na 64
	3. Umieszczenie pixeli na obrazach
		a. draw_minimap
		b. draw_player
		c. ceiling_and_floor
	4. Pobranie tekstur z plików
		a. download_textures
*/
void	render_imgs(t_data *data)
{
	t_rend_img	*rend_img;

	rend_img = data->rend_img;
	rend_img->minimap = init_img(data, data->mlx->mlx_ptr,
			data->map->width * PX / 4, data->map->height * PX / 4);
	rend_img->player_mm = init_img(data, data->mlx->mlx_ptr, PX / 8, PX / 8);
	rend_img->floor = init_img(data, data->mlx->mlx_ptr, WIDTH, HEIGHT / 2);
	rend_img->ceiling = init_img(data, data->mlx->mlx_ptr, WIDTH, HEIGHT / 2);
	rend_img->wall_px = PX * 2;
	if (!data->rend_img->minimap || !data->rend_img->player_mm
		|| !data->rend_img->floor || !data->rend_img->ceiling)
	{
		printf("Error allocating minimap\n");
		exit_clear(data);
	}
	draw_minimap(data);
	draw_player(data->rend_img->player_mm);
	ceiling_and_floor(data);
	download_textures(data);
}

/*
	Pobiera tekstury z plików
*/
void	download_textures(t_data *data)
{
	t_rend_img	*rend_img;

	rend_img = data->rend_img;
	rend_img->walls[0] = mlx_xpm_file_to_image(data->mlx->mlx_ptr,
			data->map->nesw_textures[0],
			&rend_img->wall_px, &rend_img->wall_px);
	rend_img->walls[1] = mlx_xpm_file_to_image(data->mlx->mlx_ptr,
			data->map->nesw_textures[1],
			&rend_img->wall_px, &rend_img->wall_px);
	rend_img->walls[2] = mlx_xpm_file_to_image(data->mlx->mlx_ptr,
			data->map->nesw_textures[2],
			&rend_img->wall_px, &rend_img->wall_px);
	rend_img->walls[3] = mlx_xpm_file_to_image(data->mlx->mlx_ptr,
			data->map->nesw_textures[3],
			&rend_img->wall_px, &rend_img->wall_px);
	if (!rend_img->walls[0] || !rend_img->walls[1]
		|| !rend_img->walls[2] || !rend_img->walls[3])
	{
		printf("Error allocating textures\n");
		exit_clear(data);
	}
}

/*
	Umieszcza pixel w odpowiednim miejscu w obrazie
*/
void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*
	Umieszcza kwadraty na minimapie
*/
void	draw_tile_to_minimap(t_img *img, int x, int y, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < PX / 4)
	{
		i = 0;
		while (i < PX / 4)
		{
			img_pixel_put(img, x * PX / 4 + i, y * PX / 4 + j, color);
			i++;
		}
		j++;
	}
}
