/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:30:30 by zuraw             #+#    #+#             */
/*   Updated: 2024/12/30 18:37:20 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
	1. zczytanie pliku z mapą do map->map
	2. sprawdzenie poprawności pobranych informacji
	3. sprawdzenie poprawności mapy
*/
int	process_map_file(t_map *map, char *file)
{
	map->map = read_map(file);
	if (!map->map)
		return (printf("%s", READ_ERROR), 1);
	if (validate_map_config(map))
		return (printf("%s", VAL_CONFIG_ERROR), 1);
	// if (validate_map(map)) // -> sprawdzenie poprawności mapy
	// 	return (printf("%s", VAL_ERROR), 1);
	return (0);
}
