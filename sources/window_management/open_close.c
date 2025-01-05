/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:58:54 by zuraw             #+#    #+#             */
/*   Updated: 2025/01/05 11:57:39 by zuraw            ###   ########.fr       */
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

int	close_window(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 4)
		mlx_destroy_image(data->mlx->mlx_ptr, data->rend_img->walls[i]);
	mlx_destroy_image(data->mlx->mlx_ptr, data->rend_img->minimap->img_ptr);
	mlx_destroy_image(data->mlx->mlx_ptr, data->rend_img->player_mm->img_ptr);
	mlx_destroy_image(data->mlx->mlx_ptr, data->rend_img->ceiling->img_ptr);
	mlx_destroy_image(data->mlx->mlx_ptr, data->rend_img->floor->img_ptr);
	mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->win_ptr);
	mlx_destroy_display(data->mlx->mlx_ptr);
	exit_clear(data);
	return (0);
}
