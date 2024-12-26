/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicja <alicja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:03:48 by zuraw             #+#    #+#             */
/*   Updated: 2024/12/26 14:09:14 by alicja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
# include <sys/time.h>
# include "./minilibx/mlx.h"

/*	DEFINES	*/

# define WIDTH 800
# define HEIGHT 600

# define INPUT_ERROR "Error: Invalid input\nUsage: ./cub3d <map.cub>"

/*	STRUCTS	*/

typedef struct s_data	t_data;
typedef struct s_mlx	t_mlx;

typedef struct s_map
{
	int		floor_color;
	int		ceiling_color;
	int		max_height;
	int		max_width;
}				t_map;

typedef struct s_data
{
	t_mlx	*mlx;
}				t_data;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	*data;
}				t_mlx;

/*	FUNCTIONS	*/

/*	window_management	*/
// open_close.c
void	open_window(t_mlx *mlx);
int		close_window(t_mlx *mlx);

/*	keyboard-events	*/
// keyboard_input.c
int		key_press(int keycode, t_mlx *mlx);
void	register_events(t_mlx *mlx);

/*	utils	*/
// utils.c
void	exit_clear(t_mlx *mlx);

#endif