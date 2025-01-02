/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:25:48 by zuraw             #+#    #+#             */
/*   Updated: 2025/01/01 19:06:19 by zuraw            ###   ########.fr       */
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
		printf("%s\n", data.map->nesw_textures[i]);
	printf("\n");

	printf("Colors:\n");
	printf("ceiling_color: %#X\n", data.map->ceiling_color);
	printf("floor_color: %#X\n", data.map->floor_color);

	printf("\nMap:\n");
	for (int i = 0; data.map->map[i]; i++)
		printf("%s", data.map->map[i]);
	printf("\n");

	printf("\nStarting direction: %c\n\n", data.player->start_dir);

	printf("\t\tZrobione\n1. Zczytanie oraz sprawdzenie scieżek tekstur\n2. Zczytanie, sprawdzenie oraz przeformatowanie kolorów\n3. Zczytanie oraz sprawdzenie mapy\n4. Zczytanie oraz ustawienie kierunku startowego\n\n");
	

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
