#include "../includes/cub3d.h"

int	valid_colors(t_map *map)
{
	if (map->ceiling_color == -1 || map->floor_color == -1)
		return (0);
	return (1);
}