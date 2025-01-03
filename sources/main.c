/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:25:48 by zuraw             #+#    #+#             */
/*   Updated: 2025/01/03 15:00:14 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	check_file(char *file);

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_tile_to_image(t_img *img, int x, int y, int tile_size, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < tile_size)
	{
		i = 0;
		while (i < tile_size)
		{
			img_pixel_put(img, x * tile_size + i, y * tile_size + j, color);
			i++;
		}
		j++;
	}
}

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
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == '1')
			{
				color = 0x808080;
				draw_tile_to_image(data->minimap, x, y, PX / 4, color);
			}
			else if (map->map[y][x] != ' ' && map->map[y][x] != '\n')
			{
				color = 0xFFFFFF;
				draw_tile_to_image(data->minimap, x, y, PX / 4, color);
			}
			x++;
		}
		y++;
	}
}

void	set_player_dir(t_player *player)
{
	if (player->start_dir == 'N')
		player->dir = PI / 2;
	else if (player->start_dir == 'E')
		player->dir = 0;
	else if (player->start_dir == 'S')
		player->dir = 3 * PI / 2;
	else if (player->start_dir == 'W')
		player->dir = PI;
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

int	render_minimap(t_data *data)
{
	mlx_clear_window(data->mlx->mlx_ptr, data->mlx->win_ptr);

	// Rysowanie całej minimapy
	draw_map_to_image(data);
	draw_player_to_image(data->player, data->minimap);

	// Wstawienie obrazu minimapy do okna
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr, data->minimap->img_ptr, 10, 10);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (printf("%s\n", INPUT_ERROR), 1);

	check_file(av[1]);
	set_data(&data);

	if (process_map_file(data.map, av[1]) == 1)
		return (exit_clear(&data), 1);

	printf("\nMap:\n");
	for (int i = 0; data.map->map[i]; i++)
		printf("%s", data.map->map[i]);
	printf("\n");

	printf("\nStarting direction: %c\n\n", data.player->start_dir);

	open_window(data.mlx);
	data.minimap = init_img(&data, data.mlx->mlx_ptr);

	mlx_loop_hook(data.mlx->mlx_ptr, render_minimap, &data);

	register_events(&data);
	mlx_loop(data.mlx->mlx_ptr);
	return (0);
}

static void check_file(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (i < 5 || ft_strncmp(&file[i - 4], ".cub", 4))
	{
		printf("Error: Invalid file\n");
		exit(1);
	}
}
