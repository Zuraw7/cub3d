/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicja <alicja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:59:46 by alicja            #+#    #+#             */
/*   Updated: 2025/01/27 21:11:57 by alicja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//obliczenia płaszczyzny kamery na podstawie kierunku gracza
void	calculate_camera_plane(t_player *player)
{
	player->plane_x = player->dir_y * tan(player->fov / 2);
	player->plane_y = -player->dir_x * tan(player->fov / 2);
}

//inicjalizacja struktury promienia i jego wartości do obliczenia promienia
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

/*obliczenia "kroku" (step) promienia,
który będzie następnie używany do obliczenia odległości do ściany*/
void	calculate_step(t_ray *ray, t_player *player)
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

//odległość do ściany 
/*static void	calculate_wall_dist(t_ray *ray, char **map)
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

//obliczenie wysokości ściany i start oraz koniec rysowania ściany
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

//aktualizacja pikseli na mapie
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

void perform_dda(t_ray *ray, char **map)
{
    int hit = 0;
    while (hit == 0)
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
        if (map[ray->map_x][ray->map_y] == '1')
            hit = 1;
    }
}

void calculate_wall_dist(t_ray *ray, t_player *player)
{
    if (ray->side == 0)
        ray->perp_wall_dist = (ray->map_x - player->x + (1 - ray->step_x) / 2) / ray->x_dir;
    else
        ray->perp_wall_dist = (ray->map_y - player->y + (1 - ray->step_y) / 2) / ray->y_dir;
}

void calculate_wall_height(t_ray *ray, int screen_height)
{
    ray->height = (int)(screen_height / ray->perp_wall_dist);
    ray->draw_s = -ray->height / 2 + screen_height / 2;
    if (ray->draw_s < 0)
        ray->draw_s = 0;
    ray->draw_e = ray->height / 2 + screen_height / 2;
    if (ray->draw_e >= screen_height)
        ray->draw_e = screen_height - 1;
}

void draw_wall(t_ray *ray, t_data *data, int x)
{
    int y = ray->draw_s;
    while (y < ray->draw_e)
    {
        // Set the pixel color based on the side of the wall hit
        if (ray->side == 0)
            data->pixels[y][x] = 0xFF0000; // Red for x-side
        else
            data->pixels[y][x] = 0x00FF00; // Red for x-side
        y++;
    }
}


