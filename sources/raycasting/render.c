/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicja <alicja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:49:59 by alicja            #+#    #+#             */
/*   Updated: 2025/01/27 18:21:51 by alicja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*void	render_raycast(t_data *data)
{
	create_pixel_map(data);
	init_ray(&data->ray, 0, data->player);
	ray_direction(data, &data->ray);
	render_scene(data);
}*/

void render_raycast(t_data *data)
{
    int x = 0;
    while (x < data->screen_width)
    {
        create_pixel_map(data);
        init_ray(&data->ray, x, data->player);
        printf("Ray initialized\n");
        calculate_step(&data->ray, data->player);
        printf("Step calculated\n");
        perform_dda(&data->ray, data->map->map);
        printf("DDA performed\n");
        calculate_wall_dist(&data->ray, data->player);
        printf("Wall distance calculated\n");
        calculate_wall_height(&data->ray, data->screen_height);
        printf("Wall height calculated\n");
        draw_wall(&data->ray, data, x);
        printf("Wall drawn\n");
        x++;
    }
}
