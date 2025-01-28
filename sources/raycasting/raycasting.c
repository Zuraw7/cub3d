/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicja <alicja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:59:46 by alicja            #+#    #+#             */
/*   Updated: 2025/01/28 19:24:53 by alicja           ###   ########.fr       */
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
//implementacja algorytmu DDA
void perform_dda(t_ray *ray, char **map)
{
    int hit = 0;
    while (hit == 0)
    {
        if (ray->side_x < ray->side_y)
        {
            ray->side_x += ray->delta_x;
            ray->map_x += ray->step_x;
            ray->side = 0; //ściana pionowa
        }
        else
        {
            ray->side_y += ray->delta_y;
            ray->map_y += ray->step_y;
            ray->side = 1; //ściana pozioma
        }
        if (map[ray->map_x][ray->map_y] == '1')
            hit = 1;
    }
}
//obliczenie odległości do ściany
void calculate_wall_dist(t_ray *ray, t_player *player)
{
    if (ray->side == 0)
        ray->perp_wall_dist = (ray->map_x - player->x + (1 - ray->step_x) / 2) / ray->x_dir;
    else
        ray->perp_wall_dist = (ray->map_y - player->y + (1 - ray->step_y) / 2) / ray->y_dir;
}
//obliczenie wysokości ściany i start oraz koniec rysowania ściany
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
//rysowanie ściany
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
//rysowanie mapy pikseli
void ray_direction(t_data *data, t_player *player)
{
    t_ray ray;
    int x = 0;

    while (x < WIDTH)
    {
        init_ray(&ray, x, player);
        calculate_step(&ray, player);
        perform_dda(&ray, data->map->map);
        calculate_wall_dist(&ray, player);
        calculate_wall_height(&ray, HEIGHT);
        draw_wall(&ray, data, x);
        x++;
    }
}
/*do ustawiania odpowiednich tekstur w zależności od strony,
	w którą trafił promień w wyniku algorytmu*/
void tex_onwhich_side(t_data *data, t_ray *ray)
{
    if (ray->side == 0 && ray->x_dir > 0)
    {
        data->tex_w = data->tex_w1;
        data->tex_h = data->tex_h1;
    }
    else if (ray->side == 0 && ray->x_dir < 0)
    {
        data->tex_w = data->tex_w2;
        data->tex_h = data->tex_h2;
    }
    else if (ray->side == 1 && ray->y_dir > 0)
    {
        data->tex_w = data->tex_w3;
        data->tex_h = data->tex_h3;
    }
    else if (ray->side == 1 && ray->y_dir < 0)
    {
        data->tex_w = data->tex_w4;
        data->tex_h = data->tex_h4;
    }
}

//przygotowanie tekstury
void texture_prep(t_data *data, t_ray *ray)
{
    double wallx;

    // Obliczanie współrzędnej ściany (wallx) na podstawie promienia
    if (ray->side == 0)
        wallx = data->player->y + ray->perp_wall_dist * ray->y_dir;
    else
        wallx = data->player->x + ray->perp_wall_dist * ray->x_dir;

    wallx -= floor(wallx);  // Normalizacja wartości do zakresu [0, 1]

    tex_onwhich_side(data, ray);  // Wybór tekstury

    // Ustalanie współrzędnej tekstury x (tex_x)
    data->tex_x = (int)(wallx * (double)data->tex_w);
    if (ray->side == 0 && ray->x_dir > 0)
        data->tex_x = data->tex_w - data->tex_x - 1;
    if (ray->side == 1 && ray->y_dir < 0)
        data->tex_x = data->tex_w - data->tex_x - 1;
}
//pętla po teksturze
void texture_loop(t_data *data, t_ray *ray, int x)
{
    double step;
    double texpos;
    int y;
    int color;

    color = 0;
    texture_prep(data, ray);  // Przygotowanie tekstury
    step = 1.0 * data->tex_h / ray->height;  // Krok w osi Y tekstury
    texpos = (ray->draw_s - HEIGHT / 2 + ray->height / 2) * step;  // Inicjalizacja pozycji w teksturze

    y = ray->draw_s;
    while (y < ray->draw_e + 1)
    {
        // Ustalanie odpowiedniej współrzędnej w teksturze
        data->tex_y = (int)texpos & (data->tex_h - 1);
        texpos += step;  // Przemieszczanie się po teksturze

        // Pobranie koloru z tekstury
        color = get_ray_color(data, ray);

        // Przyciemnienie koloru ściany, jeśli promień trafił w poziomą ścianę
        if (ray->side == 1)
            color = (color >> 1) & 8355711;  // Efekt oświetlenia

        // Ustawienie koloru piksela w obrazie
        data->pixels[ray->draw_s][x] = color;
        y++;
    }
}

void raycast_helper(t_data *data, t_ray *ray, int x)
{
    ray->camera_x = 2.0 * x / (double)WIDTH - 1;  // Współrzędne kamery w przestrzeni 2D
    ray->x_dir = data->player->dir_x + data->player->plane_x * ray->camera_x;  // Kierunek promienia w osi X
    ray->y_dir = data->player->dir_y + data->player->plane_y * ray->camera_x;  // Kierunek promienia w osi Y

    perform_dda(ray, data->map->map);  // Wykonanie algorytmu DDA

    ray->height = (int)(HEIGHT / ray->perp_wall_dist);  // Wysokość linii do narysowania
    ray->draw_s = (int)(-ray->height / 2.0) + (int)(HEIGHT / 2.0);  // Początek rysowania ściany
}
void draw_line(t_data *data, int x, int draw_start)
{
	t_map *map = data->map;
    int y;

    y = 0;
    // Rysowanie sufitu
    while (y < draw_start)
    {
        data->pixels[y][x] = map->ceiling_color;
        y++;
    }
    // Rysowanie podłogi
    while (y < HEIGHT)
    {
        data->pixels[y][x] = map->floor_color;
        y++;
    }
}
int get_ray_color(t_data *data, t_ray *ray)
{
    int color = 0;
    int tex_x = data->tex_x; // Aktualna współrzędna x w teksturze
    int tex_y = data->tex_y; // Aktualna współrzędna y w teksturze

    // Wybór tekstury w zależności od strony uderzenia
    if (ray->side == 0 && ray->x_dir > 0)  // Uderzenie z prawej strony (wschód)
        color = data->tex_buffer[1][tex_y * data->tex_w1 + tex_x];
    else if (ray->side == 0 && ray->x_dir < 0)  // Uderzenie z lewej strony (zachód)
        color = data->tex_buffer[3][tex_y * data->tex_w3 + tex_x];
    else if (ray->side == 1 && ray->y_dir > 0)  // Uderzenie z góry (południe)
        color = data->tex_buffer[2][tex_y * data->tex_w2 + tex_x];
    else if (ray->side == 1 && ray->y_dir < 0)  // Uderzenie z dołu (północ)
        color = data->tex_buffer[0][tex_y * data->tex_w4 + tex_x];

    return color;
}

int raycast(void *param)
{
    t_ray ray;
	t_img img;
    int x;
    t_data *data;
	int keycode= 0;

    x = 0;
    data = (t_data *)param;
    move_player(data->player, keycode);  // Ruch gracza

    // Pętla po wszystkich kolumnach ekranu
    while (x < WIDTH)
    {
        raycast_helper(data, &ray, x);  // Obliczanie danych promienia dla danej kolumny

        if (ray.draw_s < 0)
            ray.draw_s = 0;  // Korekta wartości startowej, jeśli wychodzi poza ekran

        // Obliczanie końca rysowania ściany
        ray.draw_e = (int)(ray.height / 2.0) + (int)(HEIGHT / 2.0);
        if (ray.draw_e >= HEIGHT)
            ray.draw_e = HEIGHT - 1;

        draw_line(data, x, ray.draw_s);  // Rysowanie linii tła (np. niebo, ziemia)

        texture_loop(data, &ray, x);  // Rysowanie tekstury ściany
        x++;
    }
    // Wyświetlenie obrazu w oknie
    img.img = mlx_new_image(data->mlx->mlx_ptr, WIDTH, HEIGHT);  // Tworzenie nowego obrazu
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    return (0);
}

