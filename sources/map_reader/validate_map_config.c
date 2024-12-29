/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_config.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:30:07 by zuraw             #+#    #+#             */
/*   Updated: 2024/12/29 20:51:39 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


/*
	Zadanie
	1. zczytanie informacji z pliku mapy
		a. NO, EA, SO, WE -> tekstury ścian (4 kierunki)
		b. C, F -> kolory sufitu i podłogi
	2. sprawdzenie czy jest tylko tyle ile powinno -> 6 zmiennych
	
	3. jeżeli zacznie zczytywać mapę, a nie ma jeszcze NO, EA, SO, WE, C, F -> error

	zaalokować pamięć na mapę bez NO EA SO WE C F
	przekopiowac od danego miejsca, pominąć puste linie
	sprawdzić czy jest sama mapa, jak nie to error
*/

/*
	1. sprawdza czy linia jest pusta
	2. przechodzi do pierwszego znaku alfanumerycznego
	3. jeżeli NO, EA, SO, WE kopiuje do nesw_textures
	4. jeżeli NO, EA, SO, WE -> zwraca 1
	5. jeżeli nie NO, EA, SO, WE -> zwraca 0
*/
static int	get_texture(t_map *map, char *line)
{
	if (!line || is_line_empty(line))
		return (0);
	while (!ft_isalnum(*line))
		line++;
	if (ft_strncmp(line, "NO", 2) == 0)
		set_tex_path(map, 0, line);
	else if (ft_strncmp(line, "EA", 2) == 0)
			set_tex_path(map, 1, line);
	else if (ft_strncmp(line, "SO", 2) == 0)
			set_tex_path(map, 2, line);
	else if (ft_strncmp(line, "WE", 2) == 0)
			set_tex_path(map, 3, line);
	else
		return (0);
	return (1);
}

/*
	1. sprawdza czy linia jest pusta
	2. przechodzi do pierwszego znaku alfanumerycznego
	3. jeżeli C, F kopiuje do hold_color
	4. jeżeli C, F -> zwraca 1
	5. jeżeli nie C, F -> zwraca 0
*/
static int	get_color(t_map *map, char *line)
{
	if (!line || is_line_empty(line))
		return (0);
	while(!ft_isalnum(*line))
		line++;
	if (ft_strncmp(line, "C", 1) == 0)
	{
		if (map->hold_cf_color[0] == NULL)
			map->hold_cf_color[0] = ft_strdup(line + 1);
	}
	else if (ft_strncmp(line, "F", 1) == 0)
	{
		if (map->hold_cf_color[1] == NULL)
			map->hold_cf_color[1] = ft_strdup(line + 1);
	}
	else
		return (0);
	return (1);
}

/*
	1. Alokuje miejsce dla NO, EA, SO, WE oraz C, F
	2. Pętla while
		a. check_is_map -> sprawdza czy jest znajdzie najpierw, jeżeli tak to wychodzi z pętli -> mapa musi zacząć się od 1 -> otoczona ścianami
		a. przechodzi przez całą mapę lub do znalezienia 6 info
		b. odpala get_texture
		c. odpala get_color
		d. zwiększa count jeżeli get_texture lub get_color zwróci 1
	3. sprawdzenie poprawności skopiowanych danych
	4. ustawienie kolorów i zwolnienie map->hold_cf_color (usunąć z free_map)
	
*/

int check_is_map(char *line)
{
	char	*trimmed;

	if (!line || is_line_empty(line))
		return (0);
	trimmed = ft_strtrim(line, " \t\v\r");
	if (ft_isdigit(trimmed[0]) == 1)
		return (free(trimmed), 1);
	free(trimmed);
	return (0);
}

int	validate_map_config(t_map *map)
{
	int	i;
	int	count;

	// alokacja miejsca na przechowywanie tekstur i kolorów
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
		// przypisanie NO, EA, SO, WE
		if (!is_line_empty(map->map[i]) && get_texture(map, map->map[i]))
			count++;
		// zczytanie C, F do hold_color
		if (!is_line_empty(map->map[i]) && get_color(map, map->map[i]))
			count++;
		i++;
	}
	if (count != 6)
		return (1);

	/*
		sprawdź poprawność znalezionych danych 
		1. Tesktury
			a. czy plik istnieje? OPEN flaga O_RDONLY
			b. czy plik nie zawiera tylko samych białych znaków?
			c. czy plik ma poprawne rozszerzenie .xmp
		2. Kolory
			a. dokładnie dwa przecinki -> 220,100,0
			b. czy każda wartość jest liczbą
			c. każda wartość mieści się w przedziale od 0 do 255
			d. są 3 liczby
	*/

	// sprawdzenie poprawności skopiowanych danych
	return (0);
}
