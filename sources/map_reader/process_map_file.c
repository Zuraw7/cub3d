/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:30:30 by zuraw             #+#    #+#             */
/*   Updated: 2024/12/31 17:15:34 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
/*
	1. zczytanie pliku z mapą do map->file
	2. sprawdzenie poprawności pobranych informacji
	3. sprawdzenie poprawności mapy
	4. zmienić ścieżki na takie bez whitespaców -> poprzednie zwolnić i przypisać po trimmowaniu, dodatkowo zwolnić to co nie potrzebne map->file, map->hold_cf_color
*/
int	process_map_file(t_map *map, char *file)
{
	map->file = read_map(file);
	if (!map->file)
		return (printf("%s", READ_ERROR), 1);
	if (validate_map_config(map))
		return (printf("%s", VAL_CONFIG_ERROR), 1);
	if (validate_map(map))
		return (printf("%s", VAL_ERROR), 1);
	// trim_values(map);
	return (0);
}
