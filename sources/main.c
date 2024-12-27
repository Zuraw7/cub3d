/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:25:48 by zuraw             #+#    #+#             */
/*   Updated: 2024/12/27 18:16:34 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int ac, char **av)
{
	t_data	data;
	
	if (ac != 2)
		return (printf("%s\n", INPUT_ERROR), 1);
	(void)av;
	set_data(&data);

	// 1. sprawdzić poprawność pliku podanego jako argument
	

	// 2. read map
	data.map->map = read_map(av[1]);
	if (!data.map->map)
		return (1);
	
	open_window(data.mlx);

	register_events(&data);

	mlx_loop(data.mlx->mlx_ptr);

	return (0);
}
