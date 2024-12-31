/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:25:48 by zuraw             #+#    #+#             */
/*   Updated: 2024/12/31 17:22:58 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	check_file(char *file);

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
		1. zczytanie pliku mapy oraz wpisanie go do zmiennej map->file
		2. sprawdzenie poprawności zmiennych mapy
		3. sprawdzenie poprawności mapy
		Jeżeli error -> zwraca 1
	*/
	if (process_map_file(data.map, av[1]) == 1)
		return (exit_clear(&data), 1);
	
	printf("Textures paths:\n");
	for (int i = 0; data.map->nesw_textures[i]; i++)
		printf("%s", data.map->nesw_textures[i]);
	printf("\n");

	printf("RGB values:\n");
	for (int i = 0; data.map->hold_cf_color[i]; i++)
		printf("%s", data.map->hold_cf_color[i]);
	printf("\n");

	printf("Colors:\n");
	printf("ceiling_color: %#X\n", data.map->ceiling_color);
	printf("floor_color: %#X\n", data.map->floor_color);

	printf("\nMap:\n");
	for (int i = 0; data.map->map[i]; i++)
		printf("%s", data.map->map[i]);
	printf("\n");

	printf("\nStarting direction: %c\n\n", data.player->start_dir);
	
	// 3. check map -> sprawdzenie poprawności mapy, NO WE EA SO F C oraz mapa zamknięta ścianami

	open_window(data.mlx);

	register_events(&data);

	mlx_loop(data.mlx->mlx_ptr);

	return (0);
}

static void check_file(char *file)
{
	int i;

	i = ft_strlen(file);
	if (i < 5 || ft_strncmp(&file[i - 4], ".cub", 4))
	{
		printf("Error: Invalid file\n");
		exit(1);
	}
}
