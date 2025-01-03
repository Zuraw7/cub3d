/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_structure.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:05:25 by zuraw             #+#    #+#             */
/*   Updated: 2025/01/03 15:18:41 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_neighbour(char **map, char *set, int i, int j);
static void	count_p_pos(t_map *map, int i, int j, int *pp);
static void	calc_width_height(t_map *map);
static void	set_player_dir(t_player *player);

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

static void	set_player_dir(t_player *player)
{
	if (player->start_dir == 'N')
		player->dir = PI / 2;
	else if (player->start_dir == 'E')
		player->dir = 0;
	else if (player->start_dir == 'S')
		player->dir = 3 * PI / 2;
	else if (player->start_dir == 'W')
		player->dir = PI;
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

static void	calc_width_height(t_map *map)
{
	int	i;
	int	j;
	int	in_map;

	i = 0;
	in_map = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '1')
				in_map = 1;
			if (in_map && map->map[i][j] == ' ')
				break ;
			j++;
		}
		if (j > map->width)
			map->width = j;
		i++;
	}
	map->height = i;
}
