/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:12:58 by zuraw             #+#    #+#             */
/*   Updated: 2024/12/26 17:12:40 by zuraw            ###   ########.fr       */
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
	data->mlx = mlx;
	mlx->data = data;
	data->map = map;
	map->data = data;
	data->player = player;
	player->data = data;
}

void	exit_clear(t_data *data)
{
	mlx_destroy_display(data->mlx->mlx_ptr);
	free(data->map);
	free(data->player);
	free(data->mlx);
	exit(0);
}
