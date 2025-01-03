/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:12:58 by zuraw             #+#    #+#             */
/*   Updated: 2025/01/03 10:52:56 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	*my_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	if (new_size == 0)
	{
		if (ptr)
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

//	checks if character is a whitespace
int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

//	checks if line is empty, returns 1 if true 0 if false
int	is_line_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (0);
		i++;
	}
	return (1);
}

char	*make_set(char *list)
{
	char	*set;
	int		i;
	int		len;

	len = ft_strlen(list);
	set = malloc(sizeof(char) * len + 1);
	if (!set)
		return (NULL);
	i = 0;
	while (i < len)
	{
		set[i] = list[i];
		i++;
	}
	set[i] = '\0';
	return (set);
}

t_bfs	*init_queue(int x, int y)
{
	t_bfs	*new;

	new = malloc(sizeof(t_bfs));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	new->next = NULL;
	return (new);
}
