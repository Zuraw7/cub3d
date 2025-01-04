/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_structure.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:05:25 by zuraw             #+#    #+#             */
/*   Updated: 2025/01/04 13:25:50 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_neighbour(char **map, char *set, int i, int j);
static void	count_p_pos(t_map *map, int i, int j, int *pp);
static void	calc_width_height(t_map *map);

/*
	1. Stworzenie setu {'0', '1', 'N', 'E', 'S', 'W'}
	2. Sprawdzenie czy mapa składa się tylko z tego setu
	3. Sprawdzenie czy nie ma pustych luk w mapie
		111111
		100001
		10 001
		100001
		111111
		Powyższa mapa jest nieakceptowana
	4. Sprawdzenie czy jest tylko jedna pozycja startowa
*/
int	valid_map_structure(t_map *map)
{
	char	*set;
	int		i;
	int		j;
	int		p_pos;

	set = make_set("01NESW");
	if (!set)
		return (1);
	i = -1;
	p_pos = 0;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (!ft_strchr(set, map->map[i][j]))
				if (check_neighbour(map->map, set, i, j) == 4)
					return (free(set), 1);
			count_p_pos(map, i, j, &p_pos);
		}
	}
	if (p_pos != 1)
		return (free(set), 1);
	calc_width_height(map);
	return (free(set), 0);
}

static int	check_neighbour(char **map, char *set, int i, int j)
{
	int	walls;

	walls = 0;
	if (j > 0 && ft_strchr(set, map[i][j - 1]))
		walls++;
	if (j + 1 < (int)ft_strlen(map[i])
		&& ft_strchr(set, map[i][j + 1]))
		walls++;
	if (i > 0 && j < (int)ft_strlen(map[i - 1])
		&& ft_strchr(set, map[i - 1][j]))
		walls++;
	if (map[i + 1] && j < (int)ft_strlen(map[i + 1])
		&& ft_strchr(set, map[i + 1][j]))
		walls++;
	return (walls);
}

static void	count_p_pos(t_map *map, int i, int j, int *pp)
{
	if (map->map[i][j] == 'N' || map->map[i][j] == 'E'
			|| map->map[i][j] == 'S' || map->map[i][j] == 'W')
	{
		(*pp)++;
		if (*pp == 1)
		{
			map->data->player->start_dir = map->map[i][j];
			map->data->player->x = j;
			map->data->player->y = i;
			set_player_dir(map->data->player);
		}
	}
}

static int	process_row(char *row, int *in_map, int current_width)
{
	int		j;
	char	*trimmed;

	trimmed = ft_strtrim(row, " \t\v\r\n");
	if (!trimmed)
		return (-1);
	j = 0;
	while (row[j])
	{
		if (row[j] == '1')
			*in_map = 1;
		if (*in_map && (row[j] == ' ' || row[j] == '\n'))
			break ;
		j++;
	}
	if (j > current_width)
		current_width = j;
	free(trimmed);
	return (current_width);
}

static void	calc_width_height(t_map *map)
{
	int		i;
	int		in_map;
	char	*trimmed;

	i = 0;
	in_map = 0;
	while (map->map[i])
	{
		trimmed = ft_strtrim(map->map[i], " \t\v\r\n");
		map->width = process_row(map->map[i], &in_map, map->width);
		if (map->width == -1)
			return ;
		if (ft_strlen(trimmed) == 0)
			break ;
		free(trimmed);
		trimmed = NULL;
		i++;
	}
	if (trimmed)
		free(trimmed);
	map->height = i;
}
