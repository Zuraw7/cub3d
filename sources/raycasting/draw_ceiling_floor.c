/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling_floor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:18:28 by zuraw             #+#    #+#             */
/*   Updated: 2025/01/05 01:31:00 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
	Dla make_ceiling oraz make floor
	1. Alokacja pamięci dla obrazu
	2. Wstawienie pixela w odpowiednie miejsce (adres) obrazu
*/
void	make_ceiling(t_data *data)
{
	int			color;
	t_map		*map;
	t_rend_img	*rend_img;
	int			i;
	int			j;

	map = data->map;
	rend_img = data->rend_img;
	color = map->ceiling_color;
	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT / 2)
			img_pixel_put(rend_img->ceiling, i, j, color);
	}
}

void	make_floor(t_data *data)
{
	int			color;
	t_map		*map;
	t_rend_img	*rend_img;
	int			i;
	int			j;

	map = data->map;
	rend_img = data->rend_img;
	color = map->floor_color;
	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT / 2)
			img_pixel_put(rend_img->floor, i, j, color);
	}
}

void	ceiling_and_floor(t_data *data)
{
	make_ceiling(data);
	make_floor(data);
}
