/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_structure.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:05:25 by zuraw             #+#    #+#             */
/*   Updated: 2024/12/31 17:22:29 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char	*make_set(void);
static int	check_neighbour(char **map, char *set, int i, int j);
static void	count_p_pos(t_map *map, int i, int j, int *pp);

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

	set = make_set();
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
	return (free(set), 0);
}

static char	*make_set(void)
{
	char	*set;

	set = malloc(sizeof(char) * 7);
	if (!set)
		return (NULL);
	set[0] = '0';
	set[1] = '1';
	set[2] = 'N';
	set[3] = 'E';
	set[4] = 'S';
	set[5] = 'W';
	set[6] = '\0';
	return (set);
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
			map->data->player->start_dir = map->map[i][j];		
	}
}
