/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:22:32 by zuraw             #+#    #+#             */
/*   Updated: 2024/12/31 15:57:25 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	clear_map_file(t_map *map)
{
	int	i;

	i = 0;
	while (map->file[i])
	{
		free(map->file[i]);
		i++;
	}
	free(map->file);
	map->file = NULL;
}

static void	free_nesw(t_map *map)
{
	if (map->nesw_textures[0])
		free(map->nesw_textures[0]);
	if (map->nesw_textures[1])
		free(map->nesw_textures[1]);
	if (map->nesw_textures[2])
		free(map->nesw_textures[2]);
	if (map->nesw_textures[3])
		free(map->nesw_textures[3]);
	free(map->nesw_textures);
}

static void	free_cf_color(t_map *map)
{
	if (map->hold_cf_color[0])
		free(map->hold_cf_color[0]);
	if (map->hold_cf_color[1])
		free(map->hold_cf_color[1]);
	free(map->hold_cf_color);
}

void	free_map(t_map *map)
{
	clear_map_file(map);
	free_double_arr(map->map);
	free_nesw(map);
	free_cf_color(map);
	free(map);
}
