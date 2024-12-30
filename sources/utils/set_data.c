/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:05:33 by zuraw             #+#    #+#             */
/*   Updated: 2024/12/30 20:06:05 by zuraw            ###   ########.fr       */
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
	mlx->mlx_ptr = NULL;
	mlx->win_ptr = NULL;
	data->mlx = mlx;
	mlx->data = data;
	data->map = map;
	map->data = data;
	data->player = player;
	player->data = data;
}
