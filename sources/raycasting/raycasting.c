/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicja <alicja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:59:46 by alicja            #+#    #+#             */
/*   Updated: 2025/01/04 22:58:33 by alicja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//obliczenia płaszczyzny kamery
/*void calculate_camera_plane(t_player *player) 
{
    player->plane_x = player->dir_y * tan(player->fov / 2);
    player->plane_y = -player->dir_x * tan(player->fov / 2);
}

void	init_ray(t_ray *ray, int x, t_player *player)
{
	ray->camera_x = 2 * x / (double)WIDTH - 1;
	ray->x_dir = player->dir_x + player->plane_x * ray->camera_x;
	ray->y_dir = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)player->x;
	ray->map_y = (int)player->y;
	ray->delta_x = fabs(1 / ray->x_dir);
	ray->delta_y = fabs(1 / ray->y_dir);
}

static void	calculate_step(t_ray *ray, t_player *player)
{
	if (ray->x_dir < 0)
	{
		ray->step_x = -1;
		ray->side_x = (player->x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1.0 - player->x) * ray->delta_x;
	}
	if (ray->y_dir < 0)
	{
		ray->step_y = -1;
		ray->side_y = (player->y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1.0 - player->y) * ray->delta_y;
	}
}

static void	calculate_wall_dist(t_ray *ray, char **map)
{
	while (42)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (map[ray->map_y][ray->map_x] > 0)
			break ;
	}
	if (ray->side == 0)
		ray->wall_d = ray->side_x - ray->delta_x;
	else
		ray->wall_d = ray->side_y - ray->delta_y;
}

static void	calculate_wall_height(t_ray *ray, t_player *player)
{
	ray->height = (int)(HEIGHT / ray->wall_d);
	ray->draw_s = -ray->height / 2 + HEIGHT / 2;
	if (ray->draw_s < 0)
		ray->draw_s = 0;
	ray->draw_e = ray->height / 2 + HEIGHT / 2;
	if (ray->draw_e >= HEIGHT)
		ray->draw_e = HEIGHT - 1;
	if (ray->side == 0)
		ray->wx = player->y + ray->wall_d * ray->y_dir;
	else
		ray->wx = player->x + ray->wall_d * ray->x_dir;
	ray->wx -= floor(ray->wx);
}

void	ray_direction(t_data *data, t_ray *ray)
{
    int	x;

	x = 0;
	while (x < WIDTH)
	{
		init_ray(ray, x, data->player);
		calculate_step(ray, data->player);
		calculate_wall_dist(ray, data->map->map);
		calculate_wall_height(ray, data->player);
		update_pixel_map(data, ray, x);
		x++;
	}
}*/
