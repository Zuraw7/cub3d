/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:25:48 by zuraw             #+#    #+#             */
/*   Updated: 2025/01/05 11:58:16 by zuraw            ###   ########.fr       */
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

	printf("North texture:	%s\n", data.map->nesw_textures[0]);
	printf("East texture:	%s\n", data.map->nesw_textures[1]);
	printf("South texture:	%s\n", data.map->nesw_textures[2]);
	printf("West texture:	%s\n", data.map->nesw_textures[3]);
	printf("\n\n");

	open_window(data.mlx);

	render_imgs(&data);

	mlx_loop_hook(data.mlx->mlx_ptr, render_scene, &data);

	register_events(&data);
	mlx_loop(data.mlx->mlx_ptr);
	return (0);
}

