/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:03:48 by zuraw             #+#    #+#             */
/*   Updated: 2024/12/30 20:06:18 by zuraw            ###   ########.fr       */
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
# define READ_ERROR "Error: Failed to load map\n"
# define VAL_CONFIG_ERROR "Error: Invalid map configuration\n"
# define VAL_ERROR "Error: Invalid map\n"
# define TEXTURES_ERROR "Error: Invalid textures\n"
# define COLORS_ERROR "Error: Invalid colors\n"

# define MOUSE_EDGE_LIMIT 30

/*	STRUCTS	*/

typedef struct s_data		t_data;
typedef struct s_mlx		t_mlx;
typedef struct s_map		t_map;
typedef struct s_player		t_player;

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
	char	**hold_cf_color;	// 0 - C, 1 - F, 2 - NULL
	char	**nesw_textures;	// 0 - NO, 1 - EA, 2 - SO, 3 - WE, 4 - NULL
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

/*	------window_management------	*/
// open_close.c
void	open_window(t_mlx *mlx);
int		close_window(t_data *data);

/*	keyboard-events	*/
// keyboard_input.c
int		key_press(int keycode, t_data *data);
void	register_events(t_data *data);

/*	------utils------	*/
// utils.c
void	exit_clear(t_data *data);
void	*my_realloc(void *ptr, size_t old_size, size_t new_size);
void	free_double_arr(char **arr);
int		ft_isspace(char c);
int		is_line_empty(char *line);

// set_data.c
void	set_data(t_data *data);

// clear_map.c
void	free_map(t_map *map);
void	clear_playmap(t_map *map);

// mlx_colors.c
int		get_rgba(int r, int g, int b, int a);
int		get_r(int rgba);
int		get_g(int rgba);
int		get_b(int rgba);
int		get_a(int rgba);

// parse_map_utils.c
int		valid_colors(t_map *map);

/*	------map_reader------	*/
// copy_map_file.c
char	**read_map(char *file);

// process_map_file.c
void	check_file(char *file);
int		process_map_file(t_map *map, char *file);

// validate_map_config.c
int		validate_map_config(t_map *map);

// valid_texture.c
int		valid_textures(t_map *map);

// check_colors.c
int		check_colors(t_map *map);

// validate_map_config_utils.c
char	**alloc_nesw(void);
char	**alloc_color(void);
void	set_tex_path(t_map *map, int i, char *line, int *count);
int		check_is_map(char *line);

#endif