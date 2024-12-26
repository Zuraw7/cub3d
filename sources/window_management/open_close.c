/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:58:54 by zuraw             #+#    #+#             */
/*   Updated: 2024/12/26 13:25:03 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit_clear(mlx);
	return (0);
}
