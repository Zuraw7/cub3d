/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:22:32 by zuraw             #+#    #+#             */
/*   Updated: 2024/12/29 20:03:50 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	clear_playmap(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	map->map = NULL;
}

void	free_map(t_map *map)
{
	clear_playmap(map);
	free_double_arr(map->nesw_textures);
	free_double_arr(map->hold_cf_color);
	free(map);
}
