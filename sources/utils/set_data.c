/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:05:33 by zuraw             #+#    #+#             */
/*   Updated: 2025/01/03 14:57:47 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_data(t_data *data)
{
	t_mlx		*mlx;
	t_map		*map;
	t_player	*player;

	mlx = malloc(sizeof(t_mlx));
	map = malloc(sizeof(t_map));
	player = malloc(sizeof(t_player));
	if (!mlx || !map || !player)
	{
		printf("Error: malloc failed\n");
		exit(1);
	}
	// mlx
	mlx->mlx_ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->data = data;
	data->mlx = mlx;
	// map
	map->data = data;
	map->floor_color = 0;
	map->ceiling_color = 0;
	map->hold_cf_color = NULL;
	map->nesw_textures = NULL;
	map->file = NULL;
	map->height = 0;
	map->width = 0;
	map->map = NULL;
	map->queue = NULL;
	data->map = map;
	// player
	player->data = data;
	data->player = player;
}
