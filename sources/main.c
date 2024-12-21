/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:25:48 by zuraw             #+#    #+#             */
/*   Updated: 2024/12/21 23:56:41 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	open_window(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
	{
		printf("Error\nmlx_init failed\n");
		exit(1);
	}
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "cub3d");
	if (!mlx->win_ptr)
	{
		printf("Error\nmlx_new_window failed\n");
		exit(1);
	}
}

int close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
		close_window(mlx);
	return (0);
}

void register_events(t_mlx *mlx)
{
	// Eventy dla klawiatury
	mlx_key_hook(mlx->win_ptr, key_press, mlx);

	// Zamkniecie okna na X
	mlx_hook(mlx->win_ptr, 17, 0, close_window, mlx);
}

int main(int ac, char **av)
{
	t_data	data;
	t_mlx	mlx;
	
	(void)ac;
	(void)av;
	data.mlx = &mlx;
	open_window(data.mlx);

	register_events(data.mlx);

	mlx_loop(data.mlx->mlx_ptr);

	return (0);
}
