/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefans <astefans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:49:10 by astefans          #+#    #+#             */
/*   Updated: 2025/01/03 10:49:13 by astefans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	print_instructions(void)
{
	printf("%sPlease provide as an argument one of the maps from maps folder \
		example:%s ./cub3d maps/test.cub%s\n", "\033[1;31m", "\033[1;33m", "\033[0m");
	exit(1);
}

void	input_checker(int argc, char **argv)
{
	int	fd;

	if (argc != 2 || ft_strlen(argv[1]) < 4 || ft_strncmp(argv[1]
			+ ft_strlen(argv[1]) - 4, ".cub", 4))
		print_instructions();
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_instructions();
	close(fd);
}
