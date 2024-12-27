/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:25:48 by zuraw             #+#    #+#             */
/*   Updated: 2024/12/27 19:40:14 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int ac, char **av)
{
	t_data	data;
	
	if (ac != 2)
		return (printf("%s\n", INPUT_ERROR), 1);
	

	// 1. check file -> sprawdzenie poprawności pliku, czy jest .cub
	check_file(av[1]);

	set_data(&data);
	
	/*
		Process map file
		1. zczytanie pliku mapy oraz wpisanie go do zmiennej map->map
		2. sprawdzenie poprawności zmiennych mapy
		3. sprawdzenie poprawności mapy
	*/
	if (process_map_file(data.map, av[1]) == 1)
		return (1);
	
	for (int i = 0; data.map->map[i]; i++)
		printf("%s", data.map->map[i]);
	printf("\n");
	
	// 3. check map -> sprawdzenie poprawności mapy, NO WE EA SO F C oraz mapa zamknięta ścianami

	open_window(data.mlx);

	register_events(&data);

	mlx_loop(data.mlx->mlx_ptr);

	return (0);
}
