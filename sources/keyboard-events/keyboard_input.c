/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:01:14 by zuraw             #+#    #+#             */
/*   Updated: 2024/12/26 13:24:45 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_press(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
		close_window(mlx);
	return (0);
}

/*
	mlx_key_hook -> Eventy dla klawiatury
	mlx_hook -> Zamkniecie okna na X
*/
void	register_events(t_mlx *mlx)
{
	mlx_key_hook(mlx->win_ptr, key_press, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, close_window, mlx);
}
