/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 08:02:25 by zuraw             #+#    #+#             */
/*   Updated: 2025/01/03 14:21:05 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	exit_clear(t_data *data)
{
	if (data->map)
		free_map(data->map);
	if (data->player)
		free(data->player);
	if (data->minimap)
		free(data->minimap);
	if (data->mlx)
		free(data->mlx);
	exit(0);
}

void	free_double_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

void	clear_queue(t_bfs *queue)
{
	t_bfs	*tmp;

	while (queue)
	{
		tmp = queue;
		queue = queue->next;
		free(tmp);
	}
}
