/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicja <alicja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:25:48 by zuraw             #+#    #+#             */
/*   Updated: 2025/01/04 22:56:13 by alicja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


int	main(int ac, char **av)
{
	t_data	data;

	input_checker(ac, av);
	set_data(&data);

	if (process_map_file(data.map, av[1]) == 1)
		return (exit_clear(&data), 1);

	printf("\nMap:\n");
	for (int i = 0; data.map->map[i]; i++)
		printf("%s", data.map->map[i]);
	printf("\n");

	printf("\nStarting direction: %c\n\n", data.player->start_dir);

	open_window(data.mlx);

	// inicjalizacja i renderowanie img -> podłogi i sufitu raz, one sie nie zmieniaja
	// minimapa jest zainicjalizowana tutaj, a w hook jest renderowana za kazdym razem troche inaczej
	data.rend_img->minimap = init_img(&data, data.mlx->mlx_ptr, data.map->width * PX / 4, data.map->height * PX / 4);
	ceiling_and_floor(&data);
	//render_raycast(&data);
	mlx_loop_hook(data.mlx->mlx_ptr, render_scene, &data);
	register_events(&data);
	mlx_loop(data.mlx->mlx_ptr);
	return (0);
}

