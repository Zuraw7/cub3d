/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 00:49:04 by zuraw             #+#    #+#             */
/*   Updated: 2025/01/05 01:26:05 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int		rnd(float num);
static float	new_xy(t_player *player, float dir_x,
					float dir_y, float *new_y);

void	move_player(t_player *player, int keycode)
{
	float	new_x;
	float	new_y;
	t_map	*map;

	map = player->data->map;
	if (keycode == 119)
		new_x = new_xy(player, cos(player->dir), -sin(player->dir), &new_y);
	else if (keycode == 115)
		new_x = new_xy(player, -cos(player->dir), sin(player->dir), &new_y);
	else if (keycode == 97)
		new_x = new_xy(player, cos(player->dir + PI / 2),
				-sin(player->dir + PI / 2), &new_y);
	else if (keycode == 100)
		new_x = new_xy(player, -cos(player->dir + PI / 2),
				sin(player->dir + PI / 2), &new_y);
	if (map->map[(int)rnd(new_y + OFFSET)][(int)rnd(new_x + OFFSET)] != '1' &&
		map->map[(int)rnd(new_y - OFFSET)][(int)rnd(new_x - OFFSET)] != '1' &&
		map->map[(int)rnd(new_y + OFFSET)][(int)rnd(new_x - OFFSET)] != '1' &&
		map->map[(int)rnd(new_y - OFFSET)][(int)rnd(new_x + OFFSET)] != '1')
	{
		player->x = new_x;
		player->y = new_y;
	}
}

// Funkcja zwraca zaokrągloną wartość liczby zmiennoprzecinkowej (rounding)
static int	rnd(float num)
{
	float	decimal;
	float	integer;

	integer = num;
	decimal = modff(num, &integer);
	if (decimal > 0.85)
		return (ceil(num));
	return (floor(num));
}

static float	new_xy(t_player *player, float dir_x, float dir_y, float *new_y)
{
	float	move_speed;

	move_speed = 0.2;
	*new_y = player->y + dir_y * move_speed;
	return (player->x + dir_x * move_speed);
}
