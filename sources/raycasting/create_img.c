/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:08:28 by zuraw             #+#    #+#             */
/*   Updated: 2025/01/04 13:42:06 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
