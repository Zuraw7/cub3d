/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:12:58 by zuraw             #+#    #+#             */
/*   Updated: 2024/12/27 18:18:14 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	*my_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (malloc(new_size));
	if (old_size >= new_size)
		return (ptr);
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}

void	set_data(t_data *data)
{
	t_mlx		*mlx;
	t_map		*map;
	t_player	*player;

	mlx = malloc(sizeof(t_mlx));
	map = malloc(sizeof(t_map));
	player = malloc(sizeof(t_player));
	if (!mlx || !map || !player)
	{
		printf("Error: malloc failed\n");
		exit(1);
	}
	data->mlx = mlx;
	mlx->data = data;
	data->map = map;
	map->data = data;
	data->player = player;
	player->data = data;
}

void	clear_playmap(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	map->map = NULL;
}

void	exit_clear(t_data *data)
{
	mlx_destroy_display(data->mlx->mlx_ptr);
	clear_playmap(data->map);
	free(data->map);
	free(data->player);
	free(data->mlx);
	exit(0);
}
