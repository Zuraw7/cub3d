/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:03:57 by zuraw             #+#    #+#             */
/*   Updated: 2024/12/31 17:15:52 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
	1. zczytanie mapy tylko mapy do map->map
	2. sprawdzenie czy znaki są poprawne oraz czy nie ma luki w mapie
	3. sprawdzenie czy jest otoczona ścianami
*/
int	validate_map(t_map *map)
{
	if (copy_map(map))
		return (1);
	if (valid_map_structure(map))
		return (1);
	// if (check_walls(map))
	// 	return (1);
	return (0);
}
