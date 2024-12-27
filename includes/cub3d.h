/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:03:48 by zuraw             #+#    #+#             */
/*   Updated: 2024/12/27 19:40:24 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
# include <fcntl.h>
# include <sys/time.h>
# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include "mlx_colors.h"

/*	DEFINES	*/

# define WIDTH 800
# define HEIGHT 600

# define INPUT_ERROR "Error: Invalid input\nUsage: ./cub3d <map.cub>"

# define MOUSE_EDGE_LIMIT 30

/*	STRUCTS	*/

typedef struct s_data	t_data;
typedef struct s_mlx	t_mlx;
typedef struct s_map	t_map;
typedef struct s_player	t_player;

typedef struct s_data
{
	t_mlx		*mlx;
	t_map		*map;
	t_player	*player;
	void		*window;
	int			win_height;
	int			win_width;
}				t_data;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	*data;
}				t_mlx;

typedef struct s_map
{
	int		floor_color;
	int		ceiling_color;
	char	**map;
	int		width;
	int		height;
	t_data	*data;
}				t_map;

typedef struct s_player
{
	float	x;
	float	y;
	float	dir;
	float	fov;
	int		has_moved;
	t_data	*data;
}				t_player;

/*	FUNCTIONS	*/

/*	window_management	*/
// open_close.c
void	open_window(t_mlx *mlx);
int		close_window(t_data *data);

/*	keyboard-events	*/
// keyboard_input.c
int		key_press(int keycode, t_data *data);
void	register_events(t_data *data);

/*	utils	*/
// utils.c
void	set_data(t_data *data);
void	exit_clear(t_data *data);
void	*my_realloc(void *ptr, size_t old_size, size_t new_size);
void	clear_playmap(t_map *map);

/*	map_reader	*/
// copy_map_file.c
char	**read_map(char *file);

// process_map_file.c
void	check_file(char *file);
int		process_map_file(t_map *map, char *file);

#endif