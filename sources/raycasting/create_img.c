/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:08:28 by zuraw             #+#    #+#             */
/*   Updated: 2025/01/05 01:33:21 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
	Funkcja tworzy miejsce na obrazy oraz wpisuje do nich treść obrazu
*/
void	render_imgs(t_data *data)
{
	data->rend_img->minimap = init_img(data, data->mlx->mlx_ptr,
		data->map->width * PX / 4, data->map->height * PX / 4);
	data->rend_img->player_mm = init_img(data, data->mlx->mlx_ptr, PX / 8, PX / 8);
	data->rend_img->floor = init_img(data, data->mlx->mlx_ptr, WIDTH, HEIGHT / 2);
	data->rend_img->ceiling = init_img(data, data->mlx->mlx_ptr, WIDTH, HEIGHT / 2);
	if (!data->rend_img->minimap || !data->rend_img->player_mm ||
		!data->rend_img->floor || !data->rend_img->ceiling)
	{
		printf("Error allocating minimap\n");
		exit(1);
	}
	draw_minimap(data);
	draw_player(data->player, data->rend_img->player_mm);
	ceiling_and_floor(data);
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
void	draw_tile_to_image(t_img *img, int x, int y, int color)
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
