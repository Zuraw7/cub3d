/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:25:48 by zuraw             #+#    #+#             */
/*   Updated: 2024/12/26 17:06:36 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// map reader
char	**read_map(char *file)
{
	(void)file;
	return (NULL);
}

void	set_data(t_data *data)
{
	t_mlx		*mlx;
	t_map		*map;
	t_player	*player;

	mlx = malloc(sizeof(t_mlx));
	map = malloc(sizeof(t_map));
	player = malloc(sizeof(t_player));
	if (!mlx || !map || !player)
	{
		printf("Error: malloc failed\n");
		exit(1);
	}
	data->mlx = mlx;
	mlx->data = data;
	data->map = map;
	map->data = data;
	data->player = player;
	player->data = data;
}

int main(int ac, char **av)
{
	t_data	data;
	
	if (ac != 2)
		return (printf("%s\n", INPUT_ERROR), 1);
	(void)av;
	set_data(&data);

	printf("%s\n", av[1]);
	// read map
	data.map->map = read_map(av[1]);
	
	open_window(data.mlx);

	register_events(&data);

	mlx_loop(data.mlx->mlx_ptr);

	return (0);
}
