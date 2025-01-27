/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicja <alicja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:49:19 by alicja            #+#    #+#             */
/*   Updated: 2025/01/27 21:09:59 by alicja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
/*tworzy bufor tekstury z obrazu,
kopiując piksele z adresu obrazu (img->addr) do nowego bufora (pixels)*/
bool	create_tex_buffer_from_img(t_data *data,
		t_img *img, t_main_direction dir)
{
	int	*pixels;
	int	i;
	int	j;

	pixels = ft_calloc(sizeof(int), img->width * img->height);
	if (!pixels)
		return (false);
	i = -1;
	while (++i < img->height)
	{
		j = -1;
		while (++j < img->width)
			pixels[i * img->width + j] = *(int *)(img->addr + (i * img->line_length + j * (img->bits_per_pixel / 8)));
	}
	data->tex_buffer[dir] = pixels;
	return (true);
}

//kierunki główne
static t_main_direction	get_main_direction(t_ray *ray)
{
	if (ray->side == 0)
        return (ray->x_dir < 0 ? WEST : EAST);
    else
        return (ray->y_dir > 0 ? SOUTH : NORTH);
}
//zwalnia pamięć z tablicy
void	free_array(void **array, int n)
{
	int	i;

	i = -1;
	if (n == -1)
		while (array[++i])
			free(array[i]);
	else
		while (++i < n)
			if (array[i])
				free(array[i]);
	free(array);
}
//tworzy mapę pikseli
bool	create_pixel_map(t_data *data)
{
	int	i;

	data->pixels = ft_calloc(sizeof(int *), HEIGHT + 1);
	if (!data->pixels)
		return (false);
	i = -1;
	while (++i < HEIGHT)
	{
		data->pixels[i] = ft_calloc(sizeof(int), WIDTH);
		if (!data->pixels[i])
			return (free_array((void **)data->pixels, i), false);
	}
	return (true);
}

//aktualizuje piksele na mapie
void	update_pixel_map(t_data *data, t_ray *ray, int x)
{
	t_main_direction	dir;
	int						tex_x;
	int 					tex_y;	
	int						color;
	double					pos;
	double					step;

	dir = get_main_direction(ray);
	tex_x = (int)(ray->wx * TEX_SIZE);
	if ((ray->side == 0 && ray->x_dir < 0) || (ray->side == 1 && ray->y_dir > 0))
		tex_x = TEX_SIZE - tex_x - 1;
	step = 1.0 * TEX_SIZE / ray->height;
	pos = (ray->draw_s - HEIGHT / 2 + ray->height / 2) * step;
	while (ray->draw_s < ray->draw_e)
	{
		tex_y = (int)pos & (TEX_SIZE - 1);
        pos += step;
        color = data->tex_buffer[dir][tex_y * TEX_SIZE + tex_x];
        // Efekt przyciemniania w zależności od odległości do ściany
        if (ray->side == 1)
            color = (color >> 1) & 0x7F7F7F;
        // Ustawienie koloru piksela
        if (color > 0)
            data->pixels[ray->draw_s][x] = color;
        ray->draw_s++;
	}
}

//rysuje mapę pikseli
/*void	draw_pixel_map(t_data *data)
{
	t_img	img;
	int		x;
	int		y;

	img.img = mlx_new_image(data->mlx->mlx_ptr, WIDTH, HEIGHT);
	if (!img.img)
		return ;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (data->pixels[y][x] > 0)
				img.addr[y * (img.line_length / 4) + x] = data->pixels[y][x];
			else if (y < HEIGHT / 2)
				img.addr[y * (img.line_length / 4) + x] = data->map->ceiling_color;
			else if (y < HEIGHT -1)
				img.addr[y * (img.line_length / 4) + x] = data->map->floor_color;
		}
	}
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr, img.img, 0, 0);
	mlx_destroy_image(data->mlx->mlx_ptr, img.img);
}*/

void draw_pixel_map(t_data *data)
{
    t_img img;
    int x;
	int y;

    img.img = mlx_new_image(data->mlx->mlx_ptr, WIDTH, HEIGHT);
    if (!img.img)
        return;
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    // Wypełnianie tła (sufit i podłoga)
    for (y = 0; y < HEIGHT; y++)
    {
        int color = (y < HEIGHT / 2) ? data->map->ceiling_color : data->map->floor_color;
        for (x = 0; x < WIDTH; x++)
            img.addr[y * (img.line_length / 4) + x] = color;
    }
    // Rysowanie ścian
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            if (data->pixels[y][x] > 0)
                img.addr[y * (img.line_length / 4) + x] = data->pixels[y][x];
        }
    }
    mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr, img.img, 0, 0);
    mlx_destroy_image(data->mlx->mlx_ptr, img.img);
}