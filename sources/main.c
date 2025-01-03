/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:25:48 by zuraw             #+#    #+#             */
/*   Updated: 2025/01/03 15:18:27 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	check_file(char *file);

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (printf("%s\n", INPUT_ERROR), 1);

	check_file(av[1]);
	set_data(&data);

	if (process_map_file(data.map, av[1]) == 1)
		return (exit_clear(&data), 1);

	printf("\nMap:\n");
	for (int i = 0; data.map->map[i]; i++)
		printf("%s", data.map->map[i]);
	printf("\n");

	printf("\nStarting direction: %c\n\n", data.player->start_dir);

	open_window(data.mlx);
	data.minimap = init_img(&data, data.mlx->mlx_ptr);

	mlx_loop_hook(data.mlx->mlx_ptr, render_minimap, &data);

	register_events(&data);
	mlx_loop(data.mlx->mlx_ptr);
	return (0);
}

static void check_file(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (i < 5 || ft_strncmp(&file[i - 4], ".cub", 4))
	{
		printf("Error: Invalid file\n");
		exit(1);
	}
}
