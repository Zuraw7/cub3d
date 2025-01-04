/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:01:14 by zuraw             #+#    #+#             */
/*   Updated: 2025/01/04 13:34:02 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	move_player(t_player *player, int keycode)
{
	float	move_speed;

	move_speed = 0.2;
	if (keycode == 119)
	{
		player->x += cos(player->dir) * move_speed;
		player->y -= sin(player->dir) * move_speed;
	}
	else if (keycode == 115)
	{
		player->x -= cos(player->dir) * move_speed;
		player->y += sin(player->dir) * move_speed;
	}
	else if (keycode == 97)
	{
		player->x += cos(player->dir + PI / 2) * move_speed;
		player->y -= sin(player->dir + PI / 2) * move_speed;
	}
	else if (keycode == 100)
	{
		player->x -= cos(player->dir + PI / 2) * move_speed;
		player->y += sin(player->dir + PI / 2) * move_speed;
	}
}

static void	rotate_player(t_player *player, int keycode)
{
	float	rotate_speed;

	rotate_speed = 0.1;
	if (keycode == 65361)
		player->dir += rotate_speed;
	else if (keycode == 65363)
		player->dir -= rotate_speed;
	if (player->dir < 0)
		player->dir += 2 * PI;
	if (player->dir >= 2 * PI)
		player->dir -= 2 * PI;
}

int	key_checker(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_window(data);
	if (keycode == 119 || keycode == 115 || keycode == 97 || keycode == 100)
	{
		move_player(data->player, keycode);
		printf("Player position: x: %f, y: %f\n", data->player->x, data->player->y);
	}
	else if (keycode == 65361 || keycode == 65363)
	{
		rotate_player(data->player, keycode);
		printf("Player direction: %f\n", data->player->dir);
	}
	return (0);
}

/*
	mlx_key_hook -> Eventy dla klawiatury
	mlx_hook -> Zamkniecie okna na X
*/
void	register_events(t_data *data)
{
	mlx_key_hook(data->mlx->win_ptr, key_checker, data);
	mlx_hook(data->mlx->win_ptr, 17, 0, close_window, data);
}
