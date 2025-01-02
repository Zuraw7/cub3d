/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicja <alicja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:30:30 by zuraw             #+#    #+#             */
/*   Updated: 2025/01/02 15:01:45 by alicja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*	1. zczytanie pliku z mapą do map->map
	2. sprawdzenie poprawności pobranych informacji
	3. sprawdzenie poprawności mapy
	4. zmienić ścieżki na takie bez whitespaców -> poprzednie zwolnić i przypisać po trimmowaniu*/
int	process_map_file(t_map *map, char *file)
{
	map->map = read_map(file);
	if (!map->map)
		return (printf("%s", READ_ERROR), 1);
	if (validate_map_config(map))
		return (printf("%s", VAL_CONFIG_ERROR), 1);
	// if (validate_map(map)) // -> sprawdzenie poprawności mapy
	// 	return (printf("%s", VAL_ERROR), 1);
	// trim_values(map);
	return (0);
}
