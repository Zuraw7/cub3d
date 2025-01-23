/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefans <astefans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:49:59 by alicja            #+#    #+#             */
/*   Updated: 2025/01/23 13:31:22 by astefans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	render_raycast(t_data *data)
{
	create_pixel_map(data);
	init_ray(&data->ray, 0, data->player);
	ray_direction(data, &data->ray);
	render_scene(data);
}
