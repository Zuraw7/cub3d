/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicja <alicja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:05:33 by zuraw             #+#    #+#             */
/*   Updated: 2025/01/27 17:35:28 by alicja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_mlx		*set_mlx(t_data *data);
static t_map		*set_map(t_data *data);
static t_player		*set_player(t_data *data);
static t_rend_img	*set_rend_img(t_data *data);

void	set_data(t_data *data)
{
	data->mlx = set_mlx(data);
	data->map = set_map(data);
	data->player = set_player(data);
	data->rend_img = set_rend_img(data);
	data->screen_width = data->win_width;  // Initialize screen_width
	data->screen_height = data->win_height; // Initialize screen_height
	data->keys.w = false;
	data->keys.s = false;
	data->keys.a = false;
	data->keys.d = false;
	data->keys.left = false;
	data->keys.right = false;
}

static	t_mlx	*set_mlx(t_data *data)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
	{
		printf("Error: mlx allocation failed\n");
		exit(1);
	}
	mlx->last_time = 0;
	mlx->mlx_ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->data = data;
	return (mlx);
}

static t_map	*set_map(t_data *data)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
	{
		printf("Error: map allocation failed\n");
		exit(1);
	}
	map->floor_color = 0;
	map->ceiling_color = 0;
	map->hold_cf_color = NULL;
	map->nesw_textures = NULL;
	map->file = NULL;
	map->height = 0;
	map->width = 0;
	map->map = NULL;
	map->queue = NULL;
	map->data = data;
	return (map);
}

static t_player	*set_player(t_data *data)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
	{
		printf("Error: player allocation failed\n");
		exit(1);
	}
	player->data = data;
	return (player);
}

static t_rend_img	*set_rend_img(t_data *data)
{
	t_rend_img	*rend_img;
	int			i;

	rend_img = malloc(sizeof(t_rend_img));
	if (!rend_img)
	{
		printf("Error: rend_img allocation failed\n");
		exit(1);
	}
	rend_img->minimap = NULL;
	rend_img->player_mm = NULL;
	rend_img->ceiling = NULL;
	rend_img->floor = NULL;
	i = -1;
	while (++i < 4)
		rend_img->walls[i] = NULL;
	rend_img->data = data;
	return (rend_img);
}
