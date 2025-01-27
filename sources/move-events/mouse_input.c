/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicja <alicja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:38:17 by alicja            #+#    #+#             */
/*   Updated: 2025/01/27 18:06:47 by alicja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
//funkcje do obsługi kamery myszką - BONUS PART
/*void	wrap_mouse_position(t_data *data, int x, int y)
{
	if (!data->mlx || !data->mlx->win_ptr)
        return;
	if (x > data->win_width - DIST_EDGE_MOUSE_WRAP)
	{
		x = DIST_EDGE_MOUSE_WRAP;
		mlx_mouse_move(data->mlx, data->mlx->win_ptr, x, y);
	}
	if (x < DIST_EDGE_MOUSE_WRAP)
	{
		x = data->win_width - DIST_EDGE_MOUSE_WRAP;
		mlx_mouse_move(data->mlx, data->mlx->win_ptr, x, y);
	}
}

int	mouse_motion_handler(int x, int y, t_data *data)
{
	static int	old_x = WIDTH / 2;

	wrap_mouse_position(data, x, y);
	if (x == old_x)
		return (0);
	else if (x < old_x)
		rotate_player(data->player, -1);
	else if (x > old_x)
		rotate_player(data->player, 1);
	old_x = x;
	return (0);
}*/
