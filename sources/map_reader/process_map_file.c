/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:30:30 by zuraw             #+#    #+#             */
/*   Updated: 2024/12/27 19:40:19 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void check_file(char *file)
{
	int i;

	i = ft_strlen(file);
	if (i < 5 || ft_strncmp(&file[i - 4], ".cub", 4))
	{
		printf("Error: Invalid file\n");
		exit(1);
	}
}

int	process_map_file(t_map *map, char *file)
{
	map->map = read_map(file);
	if (!map->map)
		return (1);
	// if (validate_map_config(map)) -> sprawdzenie poprawności zmiennych mapy
	// 	return (1);
	// if (validate_map(map)) -> sprawdzenie poprawności mapy
	// 	return (1);
	
	return (0);
}
