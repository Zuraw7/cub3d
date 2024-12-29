/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_config_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:32:12 by zuraw             #+#    #+#             */
/*   Updated: 2024/12/29 20:47:59 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_tex_path(t_map *map, int i, char *line, int *count)
{
	if (map->nesw_textures[i] == NULL)
	{
		map->nesw_textures[i] = ft_strdup(line + 2);
		(*count)++;
	}
}

char	**alloc_nesw(void)
{
	char	**nesw_textures;
	int		i;

	nesw_textures = (char **)malloc(sizeof(char *) * 5);
	if (!nesw_textures)
		return (NULL);
	i = 0;
	while (i < 5)
	{
		nesw_textures[i] = NULL;
		i++;
	}
	return (nesw_textures);
}

char	**alloc_color(void)
{
	char	**hold_cf_color;
	int		i;

	hold_cf_color = (char **)malloc(sizeof(char *) * 3);
	if (!hold_cf_color)
		return (NULL);
	i = 0;
	while (i < 3)
	{
		hold_cf_color[i] = NULL;
		i++;
	}
	return (hold_cf_color);
}
