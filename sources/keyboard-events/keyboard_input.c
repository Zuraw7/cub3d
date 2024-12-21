/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:01:14 by zuraw             #+#    #+#             */
/*   Updated: 2024/12/22 00:01:28 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
