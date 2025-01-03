/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:08:28 by zuraw             #+#    #+#             */
/*   Updated: 2025/01/03 15:14:38 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_img	*init_img(t_data *data, void *mlx_ptr)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->img_ptr = mlx_new_image(mlx_ptr, WIDTH / 2, HEIGHT / 4);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->width = WIDTH / 2;
	img->height = HEIGHT / 4;
	img->data = data;
	return (img);
}

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

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
