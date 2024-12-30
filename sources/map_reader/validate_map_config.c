/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_config.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:30:07 by zuraw             #+#    #+#             */
/*   Updated: 2024/12/30 18:35:40 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	get_texture(t_map *map, char *line, int *count);
static void	get_color(t_map *map, char *line, int *count);

/*
	1. Alokuje miejsce dla NO, EA, SO, WE oraz C, F
	2. Pętla while
		a. check_is_map -> sprawdza czy jest znajdzie najpierw,
			jeżeli tak to wychodzi z pętli
			-> mapa musi zacząć się od 1 -> otoczona ścianami
		b. przechodzi przez całą mapę lub do znalezienia 6 info
		c. odpala get_texture
		d. odpala get_color
		e. zwiększa count jeżeli get_texture lub get_color zwróci 1
	3. sprawdzenie poprawności skopiowanych danych
	4. ustawienie kolorów i zwolnienie map->hold_cf_color (usunąć z free_map)
*/
int	validate_map_config(t_map *map)
{
	int	i;
	int	count;

	map->nesw_textures = alloc_nesw();
	map->hold_cf_color = alloc_color();
	if (!map->nesw_textures || !map->hold_cf_color)
		return (1);
	i = 0;
	count = 0;
	while (map->map[i])
	{
		if (check_is_map(map->map[i]))
			break ;
		get_texture(map, map->map[i], &count);
		get_color(map, map->map[i], &count);
		i++;
	}
	if (count != 6)
		return (1);
	if (valid_textures(map))
		return (printf("%s", TEXTURES_ERROR), 1);
	if (check_colors(map))
		return (printf("%s", COLORS_ERROR), 1);
	return (0);
}

/*
	1. sprawdza czy linia jest pusta
	2. przechodzi do pierwszego znaku alfanumerycznego
	3. jeżeli NO, EA, SO, WE kopiuje do nesw_textures
	4. jeżeli NO, EA, SO, WE -> zwraca 1
	5. jeżeli nie NO, EA, SO, WE -> zwraca 0
*/
static void	get_texture(t_map *map, char *line, int *count)
{
	if (!line || is_line_empty(line))
		return ;
	while (!ft_isalnum(*line))
		line++;
	if (ft_strncmp(line, "NO", 2) == 0)
		set_tex_path(map, 0, line, count);
	else if (ft_strncmp(line, "EA", 2) == 0)
		set_tex_path(map, 1, line, count);
	else if (ft_strncmp(line, "SO", 2) == 0)
		set_tex_path(map, 2, line, count);
	else if (ft_strncmp(line, "WE", 2) == 0)
		set_tex_path(map, 3, line, count);
}

/*
	1. sprawdza czy linia jest pusta
	2. przechodzi do pierwszego znaku alfanumerycznego
	3. jeżeli C, F kopiuje do hold_color
	4. jeżeli C, F -> zwraca 1
	5. jeżeli nie C, F -> zwraca 0
*/
static void	get_color(t_map *map, char *line, int *count)
{
	if (!line || is_line_empty(line))
		return ;
	while (!ft_isalnum(*line))
		line++;
	if (ft_strncmp(line, "C", 1) == 0)
	{
		(*count)++;
		if (map->hold_cf_color[0] == NULL)
			map->hold_cf_color[0] = ft_strdup(line + 1);
	}
	else if (ft_strncmp(line, "F", 1) == 0)
	{
		(*count)++;
		if (map->hold_cf_color[1] == NULL)
			map->hold_cf_color[1] = ft_strdup(line + 1);
	}
}
