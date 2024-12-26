/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:12:58 by zuraw             #+#    #+#             */
/*   Updated: 2024/12/26 17:05:01 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	exit_clear(t_data *data)
{
	mlx_destroy_display(data->mlx->mlx_ptr);
	free(data->map);
	free(data->player);
	free(data->mlx);
	exit(0);
}
