/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:17:59 by zuraw             #+#    #+#             */
/*   Updated: 2025/01/05 11:53:12 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	cursor_limit(t_data *data, int x, int y)
{
	if (x > WIDTH - MOUSE_EDGE_LIMIT)
	{
		x = MOUSE_EDGE_LIMIT;
		mlx_mouse_move(data->mlx->mlx_ptr, data->mlx->win_ptr, x, y);
	}
	if (x < MOUSE_EDGE_LIMIT)
	{
		x = WIDTH - MOUSE_EDGE_LIMIT;
		mlx_mouse_move(data->mlx->mlx_ptr, data->mlx->win_ptr, x, y);
	}
}
//player_rotation.c do zrobienia, ale to potem
/*static int	mouse_handler(int x, int y, t_data *data)
{
	static int	previous_x = WIDTH / 2;

	cursor_limit(data, x, y);
	if (x == previous_x)
		return (0);
	else if (x < previous_x)
		data->player.has_moved += player_rotation(data, -1);
	else if (x > previous_x)
		data->player.has_moved += player_rotation(data, 1);
	previous_x = x;
	return (0);
}*/