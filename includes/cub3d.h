/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicja <alicja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:03:48 by zuraw             #+#    #+#             */
/*   Updated: 2025/01/05 12:53:15 by alicja           ###   ########.fr       */
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
# include <stdbool.h>
# include <sys/time.h>
# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include "mlx_colors.h"

/*	DEFINES	*/

# define WIDTH 800
# define HEIGHT 600

# define PX 32
# define PI 3.14159265359

# define TEX_SIZE 64

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
typedef struct s_bfs		t_bfs;
typedef struct s_map		t_map;
typedef struct s_player		t_player;
typedef struct s_ray		t_ray;
typedef struct s_img		t_img;
typedef struct s_rend_img	t_rend_img;


typedef enum e_main_direction
{
	NORTH = 0,
	SOUTH = 1,
	WEST = 2,
	EAST = 3,
}				t_main_direction;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	*data;
}				t_mlx;

// Breadth-First Search
typedef struct s_bfs
{
	int		x;
	int		y;
	t_bfs	*next;
}				t_bfs;

typedef struct s_map
{
	int		floor_color;		// RGB kolor podłogi
	int		ceiling_color;		// RGB kolor sufitu
	char	**hold_cf_color;	// 0 - C, 1 - F, 2 - NULL
	char	**nesw_textures;	// 0 - NO, 1 - EA, 2 - SO, 3 - WE, 4 - NULL
	char	**file;				// zczytany plik z info i mapą
	char	**map;				// zczytana mapa
	int		width;
	int		height;
	t_data	*data;
	t_bfs	*queue;				// kolejka do algorytmu BFS
}				t_map;

typedef struct	s_player
{
	float	x; // pozycja x gracza
	float	y; // pozycja y gracza
	float	dir_x; // wektor kierunku x gracza
	float	dir_y; // wektor kierunku y gracza
	float	dir; // kąt patrzenia gracza w radianach
	float	fov; // pole widzenia w radianach
	float	plane_x; // wektor kierunku x płaszczyzny kamery
	float	plane_y; // wektor kierunku y płaszczyzny kamery
	//int		has_moved;
	char	start_dir;
	t_data	*data;
}				t_player;

typedef struct s_ray
{
	double	x_dir; // wektor kierunku x
	double	y_dir; // wektor kierunku y
	double	camera_x; // x na płaszczyźnie ekranu, camera plane
	double  delta_x; // odległość promienia, którą pokonuje przechodząc przez kratkę w osi x
	double  delta_y; // odległość promienia, którą pokonuje przechodząc przez kratkę w osi y
	double	side_x; //odległość do najbliższej linii siatki x
	double	side_y; //odległość do najbliższej linii siatki y
	double	wall_d; // odległość do ściany
	double	wx; //ściana x
	int		map_x; // pozycja x na mapie
	int		map_y; // pozycja y na mapie
	int		step_x; // krok x
	int		step_y; // krok y
	int		side; //strona uderzenia ściany
	int		height; //wysokość ściany
	int		draw_s; //początek rysowania ściany
	int		draw_e; //koniec rysowania ściany
}				t_ray;

typedef struct	s_img
{
	void	*img_ptr;			// Wskaźnik na obraz
	char	*addr;				// Dane obrazu
	int		bits_per_pixel;		// Liczba bitów na piksel
	int		line_length;		// Rozmiar jednej linii w bajtach
	int		endian;				// Porządek bajtów
	int		width;				// Szerokość obrazu
	int		height;				// Wysokość obrazu
	void	*img;				// Wskaźnik na obraz
	t_data	*data;
}				t_img;

typedef struct s_rend_img
{
	t_img	*minimap;
	t_img	*ceiling;
	t_img	*floor;
	t_data	*data;
}			t_rend_img;

typedef struct s_data
{
	t_mlx		*mlx;
	t_map		*map;
	t_player	*player;
	t_rend_img	*rend_img;
	t_ray		ray;
	void		*window;
	int			win_height;
	int			win_width;
	int			*tex_buffer[4];
	int			**pixels;
}				t_data;

/*	FUNCTIONS	*/

/*	------window_management------	*/
// open_close.c
void	open_window(t_mlx *mlx);
int		close_window(t_data *data);

/*	keyboard-events	*/
// keyboard_input.c
int		key_checker(int keycode, t_data *data);
void	register_events(t_data *data);

/*	------utils------	*/
// utils.c
void	*my_realloc(void *ptr, size_t old_size, size_t new_size);
int		ft_isspace(char c);
int		is_line_empty(char *line);
char	*make_set(char *list);
void	set_player_dir(t_player *player);

// clear.c
void	exit_clear(t_data *data);
void	free_double_arr(char **arr);
void	clear_queue(t_bfs *queue);

// set_data.c
void	set_data(t_data *data);

// clear_map.c
void	free_map(t_map *map);
void	free_cf_color(t_map *map);

// mlx_colors.c
int		get_argb(int a, int r, int g, int b);
int		get_r(int argb);
int		get_g(int argb);
int		get_b(int argb);
int		get_a(int argb);

// parse_map_utils.c
int		valid_colors(t_map *map);

// inits.c
t_bfs	*init_queue(int x, int y);
t_img	*init_img(t_data *data, void *mlx_ptr, int width, int height);

/*	------map_reader------	*/
// copy_map_file.c
char	**read_map(char *file);

// process_map_file.c
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

// validate_map.c
int		validate_map(t_map *map);
char	**bfs_map(t_map *map);

// validate_map_copy_map.c
int		copy_map(t_map *map);

// valid_map_structure.c
int		valid_map_structure(t_map *map);

// check_walls.c
int		check_walls(t_map *map);

// input_validation.c
void	input_checker(int argc, char **argv);

/*	------raycasting------	*/
// raycasting.c
void	ray_direction(t_data *data, t_ray *ray);
void	calculate_camera_plane(t_player *player);
bool	create_tex_buffer_from_img(t_data *data,
		t_img *img, t_main_direction dir);
void	free_array(void **array, int n);
bool	create_pixel_map(t_data *data);
void	update_pixel_map(t_data *data, t_ray *ray, int x);
void	draw_pixel_map(t_data *data);

// create_img.c
void	img_pixel_put(t_img *img, int x, int y, int color);
void	draw_tile_to_image(t_img *img, int x, int y, int color);
void	init_ray(t_ray *ray, int x, t_player *player);

// draw_player_map.c
void	draw_map_to_image(t_data *data);
void	draw_player_to_image(t_player *player, t_img *img);
int		render_scene(t_data *data);

// draw_ceiling_floor.c
void	make_ceiling(t_data *data);
void	make_floor(t_data *data);
void	ceiling_and_floor(t_data *data);

// render.c
void	render_raycast(t_data *data);
#endif